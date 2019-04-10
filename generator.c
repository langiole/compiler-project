#include <string.h>
#include <stdio.h>
#include "y.tab.h"

void push1(FILE * f) { fprintf(f, "\tpush\t{lr}\n"); }
void pop1(FILE * f) { fprintf(f, "\tpop\t{pc}\n"); }

void generateBinaryOp(Exp * e, FILE * f) {

	generateExp(e->bo->e1, f);
	generateExp(e->bo->e2, f);

	TempVar * t1 = e->bo->e1->t;
	TempVar * t2 = e->bo->e2->t;

	switch (e->bo->op) {
	case PLUS:
		e->t = t1->value + t2->value;
		break;
	}
}

void generateExp(Exp * e, FILE * f) {
	switch (e->mode) {
	case BINARYOP:
		generateBinaryOp(e, f);
		break;
	}
}

void generatePrint(Print * p, FILE * f) {
	switch (p->mode) {
	case EXP:
		generateExp(p->e, f);
		fprintf(f, "\tldr\tr1, =t%d\n", p->e->t->index);
		fprintf(f, "\tldr\tr0, =int_println\n");
		break;
	case STRINGLITERAL:
		if (p->newline) {
			fprintf(f, "\tldr\tr1, =str%d\n", p->sl->index);
			fprintf(f, "\tldr\tr0, =str_println\n");
		} else {
			fprintf(f, "\tldr\tr0, =str%d\n", p->sl->index);
		}
		break;
	}
	fprintf(f, "\tbl\tprintf\n");
}

void generateStatement(Statement * s, FILE * f) {
	switch (s->mode) {
	case BLOCK:
	{
		Statement * curr = s->b->sl->head;
		while (curr != NULL)
		{
			generateStatement(curr, f);
			curr = curr->next;
		}
		break;
	}
	case PRINT:
		generatePrint(s->p, f);
		break;
	}
}

void generateCode(char * prog_name, AST_Node * root) {

	// replace .java extension with .s
	char * dot = index(prog_name, '.');
	*(++dot) = 's';
	*(++dot) = '\0';

	FILE * f = fopen(prog_name, "w+");

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
	push1(f);

	// continue main generation
	generateStatement(root->program->m->s, f);

	// end main
	pop1(f);
}

