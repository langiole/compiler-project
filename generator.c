#include <string.h>
#include <stdio.h>
#include "y.tab.h"

FILE * f;

void generateExp(Exp * e);

void push1(const char * v1) { fprintf(f, "\tpush\t{%s}\n", v1); }
void pop1(const char * v1) { fprintf(f, "\tpop\t{%s}\n", v1); }
void ldr(const char * reg, const char * adr) { fprintf(f, "\tldr\t%s, %s\n", reg, adr); }
void ldr_str(const char * reg, int index) { fprintf(f, "\tldr\t%s, =str%d\n", reg, index); }
void add(const char * v1, const char * v2, const char * v3) { fprintf(f, "\tadd\t%s, %s, %s\n", v1, v2, v3); }
void sub(const char * v1, const char * v2, const char * v3) { fprintf(f, "\tsub\t%s, %s, %s\n", v1, v2, v3); }
void mul(const char * v1, const char * v2, const char * v3) { fprintf(f, "\tmul\t%s, %s, %s\n", v1, v2, v3); }
void bl(const char * adr) { fprintf(f, "\tbl\t%s\n", adr); }
void mov_imm(const char * reg, int value) { fprintf(f, "\tmov\t%s, #%d\n", reg, value); }

void generateIntegerLiteral(Exp * e) {

}

void generateBinaryOp(Exp * e) {

	generateExp(e->bo->e1);
	push1("r0");
	generateExp(e->bo->e2);
	pop1("r1");

	switch (e->bo->op) {
	case PLUS:
		add("r0", "r1", "r0");
		break;
	case MINUS:
		sub("r0", "r1", "r0");
		break;
	case TIMES:
		mul("r0", "r1", "r0");
		break;
	}
}

void generateExp(Exp * e) {
	switch (e->mode) {
	case BINARYOP:
		generateBinaryOp(e);
		break;
	case INTEGERLITERAL:
		mov_imm("r0", e->il->value);
		break;
	case PAREN:
		generateExp(e->pe->e);
		break;
	}
}

void generatePrint(Print * p) {
	switch (p->mode) {
	case EXP:
		generateExp(p->e);
		add("r1", "r0", "#0");			// load r1 with r0
		ldr("r0", "=int_println");		// load r0 with printf format
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

void generateStatement(Statement * s) {
	switch (s->mode) {
	case BLOCK:
	{
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

	// generate string literals
	StringLiteral * curr = text->sl->head;
	while (curr != NULL)
	{
		fprintf(f, "str%d:\t\t.asciz \"%s\"\n", curr->index, curr->str);
		curr = curr->next;
	}

	// generate main
	fprintf(f, "\n.global main\n");
	fprintf(f, "main:\n");
	push1("lr");

	// continue main generation
	generateStatement(root->program->m->s);

	// end main
	pop1("pc");
}

