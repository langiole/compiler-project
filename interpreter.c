#include "y.tab.h"
#include <stdio.h>
#include "dfs.h"
#include "typecheck.h"

// top town search of vardecllist
Identifier * searchVarDeclListId(VarDeclList * vl, Identifier * i) {
	VarDecl * curr = vl->head;
	while (curr != NULL)
	{
		if (identifiersEqual(i, curr->i))
			return curr->i;
		curr = curr->next;
	}
	return 0;
}

// bottom up search of formal list
Identifier * searchFormalListId(FormalList * fl, Identifier * i) {
	FormalRest * curr = fl->tail;
	while (curr != NULL)
	{
		if (identifiersEqual(i, curr->i))
			return curr->i;
		curr = curr->prev;
	}
	return 0;
}

Identifier * findVarId(Identifier * keyId) {

	Identifier * i;

	// search current method variables
	if (CURR_METHOD != NULL)
	{
		// top down search of vardecllist
		i = searchVarDeclListId(CURR_METHOD->vl, keyId);

		if (i != NULL) { return i; }
	
		//  bottom up search of the formallist
		i = searchFormalListId(CURR_METHOD->fl, keyId);

		if (i != NULL) { return i; }
	}

	// search current class and extended class variables
	if (CURR_CLASS != NULL)
	{
		// top down search of vardecllist in current class
		i = searchVarDeclListId(CURR_CLASS->vl, keyId);

		if (i != NULL) { return i; }

		// top down search of vardecllist in extended class
		if (CURR_CLASS->mode == CLASSDECLEXTENDS)
		{
			ClassDecl * extendedClass = findClass(CURR_CLASS->i2);

			while (extendedClass != NULL)
			{
				// top down search of vardecllist in extended class
				i = searchVarDeclListId(extendedClass->vl, keyId);

				if (i != NULL) { return i; }
				if (extendedClass->mode != CLASSDECLEXTENDS) { return 0; }
				extendedClass = findClass(extendedClass->i2);
			}
		}
	}
	return 0;
}

void interpretReturn(Exp * e) {

	// interpret exp + propagate
	dfs(e->n);

	// set return value
	CURR_METHOD->ret = 1;
	CURR_METHOD->i->value = e->value;
}

void interpretObject(Exp * e) {
	Object * o = e->o;
	switch (o->mode)
	{
	case IDENTIFIER:
		// propagate
		e->value = o->i->value;
		break;
	}
}

void interpretAssign(Assign * a) {

	// interpret exp
	dfs(a->e->n);

	// propagate
	findVarId(a->i)->value = a->e->value;
}

void interpretMethodDecl(MethodDecl * md) {

	// reset return value
	md->ret = 0;

	// interpret statementlists
	dfs(md->sl->n);

	// interpret final return if we havent hit a return
	if (md->ret == 0) { interpretReturn(md->e); }
}

void interpretCall(Exp * e) {

	ClassDecl * tempCd = CURR_CLASS;
	MethodDecl * tempMd = CURR_METHOD;

	Object * o = e->c->o;
	Identifier * i = e->c->i;
	ExpList * el = e->c->el;

	switch (o->mode)
	{
	case NEWOBJ:
	{
		CURR_CLASS = findClass(o->no->i);
		break;
	}
	}

	// search for the method
	CURR_METHOD = findMethod(CURR_CLASS, i, el);

	// execute method
	dfs(CURR_METHOD->n);

	// propagate return value
	e->value = CURR_METHOD->e->value;

	// reset current class
	CURR_CLASS = tempCd;
	CURR_METHOD = tempMd;

}

void interpretIntegerLiteral(Exp * exp) {
	exp->value = exp->il->value;
}

void interpretBoolean(Exp * exp) {
	exp->value = exp->b->value;
}

void interpretParen(Exp * exp) {
	// interpret exp + propagate
	dfs(exp->pe->e->n);

	exp->value = exp->pe->e->value;
}

void interpretPrint(Print * p) {
	switch (p->mode)
	{
	case EXP:
		// interpret exp + propagate
		dfs(p->e->n);

		if (p->newline)
			printf("%d\n", p->e->value);
		else
			printf("%d", p->e->value);
		break;
	case STRINGLITERAL:
		if (p->newline)
			printf("%s\n", p->sl->str);
		else
			printf("%s", p->sl->str);
		break;
	}
	
}

void interpretWhile(While * w) {

	// interpret exp + propagate
	dfs(w->e->n);

	while (w->e->value)
	{
		dfs(w->s->n);

		// reinterpret exp + propagate
		dfs(w->e->n);
	}
}

void interpretIf(If * i) {

	// interpret exp + propagate
	dfs(i->e->n);

	if (i->e->value)
		dfs(i->s1->n);
	else
		dfs(i->s2->n);
}

void interpretBinaryOp(Exp * exp) {
	int op = exp->bo->op;
	Exp * e1 = exp->bo->e1;
	Exp * e2 = exp->bo->e2;

	// interpret exps + propagate
	dfs(e1->n);	
	dfs(e2->n);

	switch (op)
	{
	case AND:
	{
		if (e1->value == 1 && e2->value == 1)
			exp->value = 1;
		else
			exp->value = 0;
		break;
	}
	case OR:
	{
		if (e1->value == 1 || e2->value == 1)
			exp->value = 1;
		else
			exp->value = 0;
		break;
	}
	case EQ:
	{
		if (e1->value == e2->value)
			exp->value = 1;
		else
			exp->value = 0;
		break;
	}
	case NOTEQ:
	{
		if (e1->value != e2->value)
			exp->value = 1;
		else
			exp->value = 0;
		break;
	}
	case LESSTHANEQ:
	{
		if (e1->value <= e2->value)
			exp->value = 1;
		else
			exp->value = 0;
		break;	
	}
	case GREATTHANEQ:
	{
		if (e1->value >= e2->value)
			exp->value = 1;
		else
			exp->value = 0;
		break;	
	}
	case LESSTHAN:
	{
		if (e1->value < e2->value)
			exp->value = 1;
		else
			exp->value = 0;
		break;	
	}
	case GREATTHAN:
	{
		if (e1->value > e2->value)
			exp->value = 1;
		else
			exp->value = 0;
		break;	
	}
	case PLUS:
	{
		exp->value = e1->value + e2->value;
		break;
	}
	case MINUS:
	{
		exp->value = e1->value - e2->value;
		break;
	}
	case TIMES:
	{
		exp->value = e1->value * e2->value;
		break;
	}
	case DIVIDE:
	{
		exp->value = e1->value / e2->value;
		break;
	}
	}
}

void interpretUnaryOp(Exp * exp) {
	int op = exp->uo->op;
	Exp * e = exp->uo->e;
	switch (op)
	{
	case NEGATE:
		exp->value = !(e->value);
		break;
	case MINUS:
		exp->value = -(e->value);
		break;
	case PLUS:
		exp->value = +(e->value);
		break;
	}
}






