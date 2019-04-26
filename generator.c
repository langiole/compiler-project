#include <string.h>
#include <stdio.h>
#include "y.tab.h"
#include "typecheck.h"
#include "symtbl.h"
#include <stdlib.h>

FILE * f;

int ifCount;
int whileCount;

void generateExp(Exp * e);
void generateStatement(Statement * s);
int getOffsetFp(Identifier * i);
int getOffsetOp(Identifier * i);

void push1(const char * v1) { fprintf(f, "\tpush\t{%s}\n", v1); }
void pop1(const char * v1) { fprintf(f, "\tpop\t{%s}\n", v1); }
void push2(const char * v1, const char * v2) { fprintf(f, "\tpush\t{%s, %s}\n", v1, v2); }
void pop2(const char * v1, const char * v2) { fprintf(f, "\tpop\t{%s, %s}\n", v1, v2); }
void ldr(const char * reg, const char * adr) { fprintf(f, "\tldr\t%s, %s\n", reg, adr); }
void ldr_offset(const char * reg, const char * adr, int offset) { fprintf(f, "\tldr\t%s, [%s, #%d]\n", reg, adr, offset); }
void ldr_str(const char * reg, int index) { fprintf(f, "\tldr\t%s, =str%d\n", reg, index); }
void add(const char * v1, const char * v2, const char * v3) { fprintf(f, "\tadd\t%s, %s, %s\n", v1, v2, v3); }
void sub(const char * v1, const char * v2, const char * v3) { fprintf(f, "\tsub\t%s, %s, %s\n", v1, v2, v3); }
void sub_imm(const char * v1, const char * v2, int imm) { fprintf(f, "\tsub\t%s, %s, #%d\n", v1, v2, imm); }
void mul(const char * v1, const char * v2, const char * v3) { fprintf(f, "\tmul\t%s, %s, %s\n", v1, v2, v3); }
void bl(const char * adr) { fprintf(f, "\tbl\t%s\n", adr); }
void bl_constructor(const char * i1) { fprintf(f, "\tbl\t%s\n", i1); }
void bl_method(const char * i1, const char * i2, const char * el) { fprintf(f, "\tbl\t%s_%s\n", i1, i2); }
void mov_imm(const char * reg, int value) { fprintf(f, "\tmov\t%s, #%d\n", reg, value); }
void bx(const char * adr) { fprintf(f, "\tbx\t%s\n", adr); }
void str(const char * reg, const char * adr) { fprintf(f, "\tstr\t%s, %s\n", reg, adr); }
void str_offset(const char * reg, const char * adr, int offset) { fprintf(f, "\tstr\t%s, [%s, #%d]\n", reg, adr, offset); }

void generateObject(Object * o) {
	switch (o->mode) {
	case NEWOBJ:
		// allocate object on heap and move its address to r1
		if (findClass(o->no->i)->tbl->size != 0) {
			fprintf(f, "\tbl\t%s\n", o->no->i->name);
			fprintf(f, "\tmov\tr1, r0\n");
		}
		break;
	case IDENTIFIER:
	{
		// see if variable is local
		int offset = getOffsetFp(o->i);

		if (offset == -1) {
			offset = getOffsetOp(o->i);
			fprintf(f, "\tldr\tr2, [r11]\n");
			fprintf(f, "\tldr\tr1, [r2, #%d]\n", offset);
		} else {
			fprintf(f, "\tldr\tr1, [r11, #%d]\n", -offset);
		}
		break;
	}
	case THIS:
		fprintf(f, "\tldr\tr1, [r11]\n");
		break;
	case NEWARR:
	{
		int dim = 0;

		fprintf(f, "\tmov\tr0, #1\n");

		// calculate size
		Index * ix = o->na->ix;
		while (ix->mode == MULTIINDEX) {

			fprintf(f, "\tpush\t{r0}\n");

			generateExp(ix->mi->e);

			fprintf(f, "\tpop\t{r0}\n");
			fprintf(f, "\tmul\tr0, r1\n");
			fprintf(f, "\tpush\t{r1}\n");

			dim += 1;
			ix = ix->mi->ix;
		}

		fprintf(f, "\tpush\t{r0}\n");

		generateExp(ix->e);

		fprintf(f, "\tpop\t{r0}\n");
		fprintf(f, "\tmul\tr0, r1\n");
		fprintf(f, "\tpush\t{r1}\n");

		dim += 1;

		fprintf(f, "\tlsl\tr0, r0, #2\n");
		fprintf(f, "\tadd\tr0, #%d\n", 4*dim);
		fprintf(f, "\tbl\tmalloc\n");

		// store dimension info
		int i = 0;
		while (dim > i) {
			fprintf(f, "\tpop\t{r1}\n");
			fprintf(f, "\tstr\tr1, [r0, #%d]\n", 4 * i++);
		}

		// move address of array into r1
		fprintf(f, "\tmov\tr1, r0\n");
		break;
	}
	}
}

void generateCall(Call * c) {
	generateObject(c->o);

	// find class descriptor to use
	Identifier * classId;
	switch (c->o->mode) {
	case NEWOBJ:
		classId = c->o->no->i;
		break;
	case IDENTIFIER:
	{
		classId = getType(c->o->i, CURR_CLASS->tbl, CURR_METHOD->tbl)->pt->i;
		break;
	}
	case THIS:
		classId = CURR_CLASS->i1;
		break;
	}

	MethodEntry m = findMethod(classId, c->i, c->el);

	// push first parameter (self)
	if (findClass(classId)->tbl->size != 0)
		fprintf(f, "\tpush\t{r1}\n");

	// generate exp's and push values
	Exp * currExp = c->el->head;
	while (currExp != NULL) {
		generateExp(currExp);
		fprintf(f, "\tpush\t{r1}\n");
		currExp = currExp->next;
	}

	// pop parameters into registers
	if (m.fl->count != 0) {
		int i = 1;
		fprintf(f, "\tpop\t{");
		for (; i < m.fl->count; i++) {
			fprintf(f, "r%d, ", i);
		}
		fprintf(f, "r%d}\n", i);
	}

	// pop first parameter
	if (findClass(classId)->tbl->size != 0)
		fprintf(f, "\tpop\t{r0}\n");

	// call method
	fprintf(f, "\tbl\t%s_%s", m.className, m.i->name);

	// print any formal parameters
	FormalRest * currFr = m.fl->head;
	while (currFr != NULL) {
		char * str = typeToString(currFr->t);
		fprintf(f, "_%s", str);
		free(str);
		currFr = currFr->next;
	}
	fprintf(f, "\n");
}

void generateUnaryOp(Exp * e) {

	generateExp(e->uo->e);

	switch (e->uo->op) {
	case NEGATE:
		fprintf(f, "\tcmp\tr1, #1\n");
		fprintf(f, "\tmoveq\tr1, #0\n");
		fprintf(f, "\tmovne\tr1, #1\n");
		break;
	case MINUS:
		fprintf(f, "\tneg\tr1, r1\n");
		break;
	}	
}

void generateBinaryOp(Exp * e) {

	generateExp(e->bo->e1);
	push1("r1");
	generateExp(e->bo->e2);
	pop1("r2");

	switch (e->bo->op) {
	case PLUS:
		add("r1", "r2", "r1");
		break;
	case MINUS:
		sub("r1", "r2", "r1");
		break;
	case TIMES:
		mul("r1", "r2", "r1");
		break;
	case AND:
		fprintf(f, "\tand\tr1, r2, r1\n");
		break;
	case OR:
		fprintf(f, "\torr\tr1, r2, r1\n");
		break;
	case LESSTHAN:
		fprintf(f, "\tcmp\tr2, r1\n");
		fprintf(f, "\tmovlt\tr1, #1\n");
		fprintf(f, "\tmovge\tr1, #0\n");
		break;
	case LESSTHANEQ:
		fprintf(f, "\tcmp\tr2, r1\n");
		fprintf(f, "\tmovle\tr1, #1\n");
		fprintf(f, "\tmovgt\tr1, #0\n");
		break;
	case GREATTHAN:
		fprintf(f, "\tcmp\tr2, r1\n");
		fprintf(f, "\tmovgt\tr1, #1\n");
		fprintf(f, "\tmovle\tr1, #0\n");
		break;
	case GREATTHANEQ:
		fprintf(f, "\tcmp\tr2, r1\n");
		fprintf(f, "\tmovge\tr1, #1\n");
		fprintf(f, "\tmovlt\tr1, #0\n");
		break;
	case EQ:
		fprintf(f, "\tcmp\tr2, r1\n");
		fprintf(f, "\tmoveq\tr1, #1\n");
		fprintf(f, "\tmovne\tr1, #0\n");
		break;
	case NOTEQ:
		fprintf(f, "\tcmp\tr2, r1\n");
		fprintf(f, "\tmovne\tr1, #1\n");
		fprintf(f, "\tmoveq\tr1, #0\n");
		break;
	}
}

void generateBoolean(Boolean * b) {
	if (b->value) {
		fprintf(f, "\tmov\tr1, #1\n");
	} else {
		fprintf(f, "\tmov\tr1, #0\n");
	}
}

// load base address of array in r0 and offset in r3
void generateArrayIndex(Identifier * i, Index * ix) {
	// load address of array into r0
	// see if variable is local
	int offset = getOffsetFp(i);

	// global var
	if (offset == -1) { 
		offset = getOffsetOp(i);
		fprintf(f, "\tldr\tr2, [r11]\n");
		fprintf(f, "\tldr\tr0, [r2, #%d]\n", offset);
	} else {
		fprintf(f, "\tldr\tr0, [r11, #%d]\n", -offset);
	}

	fprintf(f, "\tmov\tr3, #0\n");

	// calculate index
	int dim = getDimension(getType(i, CURR_CLASS->tbl, CURR_METHOD->tbl));
	int indexDim = getDimension(ix->t);

	while (ix->mode == MULTIINDEX) {

		fprintf(f, "\tpush\t{r0, r3}\n");

		generateExp(ix->mi->e);

		fprintf(f, "\tpop\t{r0, r3}\n");

		if (dim != indexDim) {
			fprintf(f, "\tldr\tr2, [r0, #%d]\n", 4*(indexDim - 1));
			fprintf(f, "\tmul\tr1, r1, r2\n");
		}
			
		fprintf(f, "\tadd\tr3, r1, r3\n");

		indexDim--;
		ix = ix->mi->ix;
	}

	fprintf(f, "\tpush\t{r0, r3}\n");

	generateExp(ix->e);

	fprintf(f, "\tpop\t{r0, r3}\n");
	
	if (dim != indexDim) {
		fprintf(f, "\tldr\tr2, [r0, #%d]\n", 4*(indexDim - 1));
		fprintf(f, "\tmul\tr1, r1, r2\n");
	}
	fprintf(f, "\tadd\tr3, r1, r3\n");

	// adjust offset
	fprintf(f, "\tlsl\tr3, r3, #2\n");
	fprintf(f, "\tadd\tr3, r3, #%d\n", dim*4);
}

void generateArrayLookup(ArrayLookup * alook) {
	generateArrayIndex(alook->i, alook->ix);

	fprintf(f, "\tldr\tr1, [r0, r3]\n");
}

void generateExp(Exp * e) {
	switch (e->mode) {
	case BINARYOP:
		generateBinaryOp(e);
		break;
	case UNARYOP:
		generateUnaryOp(e);
		break;
	case INTEGERLITERAL:
		mov_imm("r1", e->il->value);
		break;
	case PAREN:
		generateExp(e->pe->e);
		break;
	case CALL:
		generateCall(e->c);
		break;
	case OBJECT:
		generateObject(e->o);
		break;
	case BOOLEAN:
		generateBoolean(e->b);
		break;
	case ARRLOOKUP:
		generateArrayLookup(e->alook);
		break;

	}
}

void generatePrint(Print * p) {
	switch (p->mode) {
	case EXP:
		generateExp(p->e);		
		if (p->newline) {
			ldr("r0", "=int_println");	// load r0 with printf format
		} else {
			ldr("r0", "=int_print");	// load r0 with printf format
		}
		break;
	case STRINGLITERAL:
		if (p->newline) {
			ldr_str("r1", p->sl->index);	// load r1 with sl
			ldr("r0", "=str_println");	// load r0 with printf format
		} else {
			ldr_str("r0", p->sl->index);	// load r0 with sl
		}
		break;
	}
	bl("printf");
}

int getOffsetFp(Identifier * i) {
	int index = getIndex(i, CURR_METHOD->tbl);
	if (index == -1) { return index; }
	return index * 4 + 4;
}

int getOffsetOp(Identifier * i) {
	int index = getIndex(i, CURR_CLASS->tbl);
	if (index == -1) { return index; }
	return index * 4;
}

void generateAssign(Assign * a) {
	generateExp(a->e);

	// see if variable is local
	int offset = getOffsetFp(a->i);

	// global var
	if (offset == -1) { 
		offset = getOffsetOp(a->i);
		fprintf(f, "\tldr\tr2, [r11]\n");
		fprintf(f, "\tstr\tr1, [r2, #%d]\n", offset);
	} else {
		fprintf(f, "\tstr\tr1, [r11, #%d]\n", -offset);
	}
}

void generateIf(If * i) {

	int count = ifCount++;

	generateExp(i->e);

	fprintf(f, "\tcmp\tr1, #1\n");
	fprintf(f, "\tbeq\t_true%d\n", count);

	// execute false branch
	generateStatement(i->s2);

	// branch to end of if else
	fprintf(f, "\tb\t_done%d\n", count);

	// execute true branch
	fprintf(f, "_true%d:\n", count);

	generateStatement(i->s1);

	// end of if else
	fprintf(f, "_done%d:\n", count);

}

void generateWhile(While * w) {

	int count = whileCount++;

	fprintf(f, "_loop%d:\n", count);

	generateExp(w->e);

	fprintf(f, "\tcmp\tr1, #1\n");
	fprintf(f, "\tbne\t_loop_done%d\n", count);

	generateStatement(w->s);

	fprintf(f, "\tb\t_loop%d\n", count);
	fprintf(f, "_loop_done%d:\n", count);

}

void generateReturn(Exp * e) {
	generateExp(e);

	// epilogue
	fprintf(f, "\tadd\tsp, r11, #4\n");
	if (CURR_METHOD->leaf) {
		fprintf(f, "\tpop\t{r11}\n");
		fprintf(f, "\tbx\tlr\n");
	} else
		fprintf(f, "\tpop\t{r11, pc}\n");
}

void generateArrayAssign(ArrayAssign * aa) {
	generateExp(aa->e);

	fprintf(f, "\tpush\t{r1}\n");

	generateArrayIndex(aa->i, aa->ix);

	// load exp
	fprintf(f, "\tpop\t{r1}\n");

	// store exp
	fprintf(f, "\tstr\tr1, [r0, r3]\n");
}

void generateStatement(Statement * s) {
	switch (s->mode) {
	case BLOCK:
	{
		if (s->b->sl == NULL) break;
		Statement * curr = s->b->sl->head;
		while (curr != NULL)
		{
			generateStatement(curr);
			curr = curr->next;
		}
		break;
	}
	case PRINT:
		generatePrint(s->p);
		break;
	case ASSGN:
		generateAssign(s->a);
		break;
	case ARRASSGN:
		generateArrayAssign(s->aa);
		break;
	case IF:
		generateIf(s->i);
		break;
	case WHILE:
		generateWhile(s->w);
		break;
	case RET:
		generateReturn(s->e);
		break;
	}
}

void generateMethod(MethodDecl * md, int cp) {

	CURR_METHOD = md;

	fprintf(f, "_%s", md->i->name);

	// print any formal parameters
	FormalRest * currFr = md->fl->head;
	while (currFr != NULL) {
		char * str = typeToString(currFr->t);
		fprintf(f, "_%s", str);
		free(str);
		currFr = currFr->next;
	}
	fprintf(f, ":\n");

	// prologue
	if (md->leaf)
		fprintf(f, "\tpush\t{r0, r11}\n");
	else
		fprintf(f, "\tpush\t{r0, r11, lr}\n");

	// set fp
	fprintf(f, "\tmov\tr11, sp\n");

	// allocate space in frame
	fprintf(f, "\tsub\tsp, sp, #%d\n", 4 * md->tbl->size);

	// store parameters in frame
	for (int i = md->fl->count; i > 0; i--) {
		fprintf(f, "\tstr\tr%d, [r11, #%d]\n", i, -(md->fl->count - i + 1)*4);
	}

	// generate statements
	Statement * curr = md->sl->head;
	while (curr != NULL) {
		generateStatement(curr);
		curr = curr->next;
	}

	generateReturn(md->e);
}

void generateClass(ClassDecl * cd) {

	CURR_CLASS = cd;

	MethodDecl * curr = cd->ml->head;
	while (curr != NULL) {
		fprintf(f, "\n%s", cd->i1->name);
		generateMethod(curr, cd->vl->count);
		curr = curr->next;
	}

	if (cd->tbl->size != 0) {
		fprintf(f, "\n%s:\n", cd->i1->name);
		push2("r11", "lr");
		mov_imm("r0", 4*cd->tbl->size);
		bl("malloc");
		pop2("r11", "pc");
	}
}

void generateCode(char * prog_name, AST_Node * root) {

	// replace .java extension with .s
	char * dot = index(prog_name, '.');
	*(++dot) = 's';
	*(++dot) = '\0';

	f = fopen(prog_name, "w+");

	// add .text section
	fprintf(f, ".section\t.text\n");

	// generate printf formats
	fprintf(f, "str_println:\t.asciz \"%%s\\n\"\n");
	fprintf(f, "int_println:\t.asciz \"%%d\\n\"\n");
	fprintf(f, "int_print:\t.asciz \"%%d\\n\"\n");

	// generate string literals
	StringLiteral * currSl = text->sl->head;
	while (currSl != NULL)
	{
		fprintf(f, "str%d:\t\t.asciz \"%s\"\n", currSl->index, currSl->str);
		currSl = currSl->next;
	}

	// global main and balign
	fprintf(f, "\n.global main\n");
	fprintf(f, ".balign 4\n");

	// build class descriptors
	buildClassDescriptors(root->program->cl);

	// generate classes and methods
	ClassDecl * currCd = root->program->cl->head;
	while (currCd != NULL) {
		generateClass(currCd);
		currCd = currCd->next;
	}

	// generate main
	fprintf(f, "main:\n");
	push1("lr");

	// continue main generation
	generateStatement(root->program->m->s);

	// end main
	pop1("pc");
}

