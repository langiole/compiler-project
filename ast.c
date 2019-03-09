#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include "typecheck.h"
#include "interpreter.h"

AST_Node * mkleaf(int mode, char * ptr) {
	switch (mode) {
	case IDENTIFIER:
	{
		Identifier * i = malloc(sizeof(Identifier));
		Entry * e = malloc(sizeof(Entry));
		AST_Node * node = malloc(sizeof(AST_Node));

		i->name = ptr;
		i->n = node;
		
		e->mode = IDENTIFIER;
		e->i = i;

		node->mode = IDENTIFIER;
		node->identifier = i;

		return node;
	}
	case STRINGLITERAL:
	{
		StringLiteral * sl = malloc(sizeof(StringLiteral));
		AST_Node * node = malloc(sizeof(AST_Node));

		sl->str = ptr;
		sl->n = node;

		node->mode = STRINGLITERAL;
		node->stringliteral = sl;

		return node;
	}
	case INTEGERLITERAL:
	{
		IntegerLiteral * il = malloc(sizeof(IntegerLiteral));
		AST_Node * node = malloc(sizeof(AST_Node));

		il->value = atoi(ptr);
		il->n = node;

		node->mode = INTEGERLITERAL;
		node->integerliteral = il;
		free(ptr);

		return node;
	}
	}
}

AST_Node * binaryOp(int op, Exp * e1, Exp * e2) {
	Exp * e = malloc(sizeof(Exp));
	BinaryOp * bo = malloc(sizeof(BinaryOp));
	AST_Node * node = malloc(sizeof(AST_Node));

	switch (op)
	{
	case AND:
		bo->op = AND;
		break;
	case OR:
		bo->op = OR;
		break;
	case EQ:
		bo->op = EQ;
		break;
	case NOTEQ:
		bo->op = NOTEQ;
		break;
	case LESSTHANEQ:
		bo->op = LESSTHANEQ;
		break;
	case GREATTHANEQ:
		bo->op = GREATTHANEQ;
		break;
	case LESSTHAN:
		bo->op = LESSTHAN;
		break;
	case GREATTHAN:
		bo->op = GREATTHAN;
		break;
	case PLUS:
		bo->op = PLUS;
		break;
	case MINUS:
		bo->op = MINUS;
		break;
	case TIMES:
		bo->op = TIMES;
		break;
	case DIVIDE:
		bo->op = DIVIDE;
		break;
	}

	bo->e1 = e1;
	bo->e2 = e2;

	e->mode = BINARYOP;
	e->bo = bo;
	e->n = node;

	int type1 = e1->type;
	int type2 = e2->type;

	if (type1 != 0 && type2 != 0)
	{
		// begin typechecking
		if (typecheckBinaryExp(op, type1, type2))
			TYPEERR = 1;
		
		// begin program interpretation
		if (!TYPEERR)
			interpretBinaryExp(op, e, e1, e2);
	}

	node->mode = EXP;
	node->exp = e;

	return node;
}

AST_Node * unaryOp(int op, Exp * exp) {
	Exp * e = malloc(sizeof(Exp));
	UnaryOp * uo = malloc(sizeof(UnaryOp));
	AST_Node * node = malloc(sizeof(AST_Node));

	switch (op)
	{
	case NEGATE:
		uo->op = NEGATE;
		break;
	case MINUS:
		uo->op = MINUS;
		break;
	case PLUS:
		uo->op = PLUS;
		break;
	}

	uo->e = exp;

	e->mode = UNARYOP;
	e->uo = uo;
	e->n = node;

	int type = exp->type;

	if (type != 0)
	{
		// begin typechecking
		if (typecheckUnaryExp(op, type))
			TYPEERR = 1;
		
		// begin program interpretation
		if (!TYPEERR)
			interpretUnaryExp(op, e, exp);
	}

	node->mode = EXP;
	node->exp = e;

	return node;
}

AST_Node * boolean(int value) {
	Exp * e = malloc(sizeof(Exp));
	Boolean * b = malloc(sizeof(Boolean));
	AST_Node * node = malloc(sizeof(AST_Node));

	b->value = value;

	e->mode = BOOLEAN;
	e->b = b;
	e->n = node;

	// propagate type and value
	e->type = BOOLEAN;
	e->value = value;

	node->mode = EXP;
	node->exp = e;

	return node;
}

AST_Node * mknode0(int mode) {
	switch (mode) {
	case CLASSDECLLIST:
	{
		ClassDeclList * cl = malloc(sizeof(ClassDeclList));
		AST_Node * node = malloc(sizeof(AST_Node));

		cl->n = node;

		node->mode = CLASSDECLLIST;
		node->classdecllist = cl;

		return node;
	}
	case VARDECLLIST:
	{
		VarDeclList * vl = malloc(sizeof(VarDeclList));
		AST_Node * node = malloc(sizeof(AST_Node));

		vl->n = node;

		node->mode = VARDECLLIST;
		node->vardecllist = vl;

		return node;
	}
	case METHODDECLLIST:
	{
		MethodDeclList * ml = malloc(sizeof(MethodDeclList));
		AST_Node * node = malloc(sizeof(AST_Node));

		ml->n = node;

		node->mode = METHODDECLLIST;
		node->methoddecllist = ml;

		return node;
	}
	case FORMALLIST:
	{
		FormalList * fl = malloc(sizeof(FormalList));
		AST_Node * node = malloc(sizeof(AST_Node));

		fl->n = node;

		node->mode = FORMALLIST;
		node->formallist = fl;

		return node;
	}
	case FORMALRESTLIST:
	{
		FormalRestList * fl = malloc(sizeof(FormalRestList));
		AST_Node * node = malloc(sizeof(AST_Node));

		fl->n = node;

		node->mode = FORMALRESTLIST;
		node->formalrestlist = fl;

		return node;
	}
	case BLOCK:
	{
		Statement * s = malloc(sizeof(Statement));
		Block * b = malloc(sizeof(Block));
		AST_Node * node = malloc(sizeof(AST_Node));

		s->mode = BLOCK;
		s->b = b;
		s->n = node;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case THIS:
	{
		Object * o = malloc(sizeof(Object));
		This * t = malloc(sizeof(This));
		AST_Node * node = malloc(sizeof(AST_Node));

		o->mode = THIS;
		o->t = t;
		o->n = node;

		node->mode = OBJECT;
		node->object = o;

		return node;
	}
	case EXPRESTLIST:
	{
		ExpRestList * erl = malloc(sizeof(ExpRestList));
		AST_Node * node = malloc(sizeof(AST_Node));

		erl->n = node;

		node->mode = EXPRESTLIST;
		node->exprestlist = erl;

		return node;
	}
	case PRIMTYPEINT:
	{
		PrimType * pt = malloc(sizeof(PrimType));
		IntegerType * it = malloc(sizeof(IntegerType));
		AST_Node * node = malloc(sizeof(AST_Node));

		pt->mode = INT;
		pt->it = it;
		pt->n = node;

		node->mode = PRIMTYPE;
		node->primtype = pt;

		return node;
	}
	case PRIMTYPEBOOL:
	{
		PrimType * pt = malloc(sizeof(PrimType));
		BooleanType * bt = malloc(sizeof(BooleanType));
		AST_Node * node = malloc(sizeof(AST_Node));

		pt->mode = BOOLEAN;
		pt->bt = bt;
		pt->n = node;

		node->mode = PRIMTYPE;
		node->primtype = pt;

		return node;
	}
	case TRUE:
		return boolean(1);
	case FALSE:
		return boolean(0);
	case EXPLIST:
	{
		ExpList * el = malloc(sizeof(ExpList));
		Exp * e = malloc(sizeof(Exp));
		ExpRestList * erl = malloc(sizeof(ExpRestList));
		AST_Node * node = malloc(sizeof(AST_Node));

		el->e = e;
		el->erl = erl;
		el->n = node;

		node->mode = EXPLIST;
		node->explist = el;

		return node;
	}
	}
}

AST_Node * mknode1(int mode, AST_Node * n1) {
	switch (mode) {
	case STATEMENTLIST:
	{
		StatementList * sl = malloc(sizeof(StatementList));
		AST_Node * node = malloc(sizeof(AST_Node));

		sl->head = n1->statement;
		sl->tail = n1->statement;
		sl->n = node;

		node->mode = STATEMENTLIST;
		node->statementlist = sl;

		return node;
	}
	case TYPEPRIM:
	{
		Type * t = malloc(sizeof(Type));
		AST_Node * node = malloc(sizeof(AST_Node));

		t->mode = PRIMTYPE;
		t->pt = n1->primtype;
		t->n = node;

		node->mode = TYPE;
		node->type = t;

		return node;
	}
	case TYPEARR:
	{
		Type * t = malloc(sizeof(Type));
		ArrayType * at = malloc(sizeof(ArrayType));
		AST_Node * node = malloc(sizeof(AST_Node));

		at->t = n1->type;

		t->mode = ARRAYTYPE;
		t->at = at;
		t->n = node;

		node->mode = TYPE;
		node->type = t;

		return node;
	}
	case PRIMTYPEID:
	{
		PrimType * pt = malloc(sizeof(PrimType));
		AST_Node * node = malloc(sizeof(AST_Node));

		pt->mode = IDENTIFIER;
		pt->i = n1->identifier;
		pt->n = node;

		node->mode = PRIMTYPE;
		node->primtype = pt;

		return node;
	}
	case BLOCK:
	{
		Statement * s = malloc(sizeof(Statement));
		Block * b = malloc(sizeof(Block));
		AST_Node * node = malloc(sizeof(AST_Node));

		b->sl = n1->statementlist;

		s->mode = BLOCK;
		s->b = b;
		s->n = node;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case PRINTLNEXP:
	{
		Statement * s = malloc(sizeof(Statement));
		Print * p = malloc(sizeof(Print));
		AST_Node * node = malloc(sizeof(AST_Node));

		p->newline = 1;
		p->mode = EXP;
		p->e = n1->exp;

		s->mode = PRINT;
		s->p = p;
		s->n = node;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case PRINTLNSTR:
	{
		Statement * s = malloc(sizeof(Statement));
		Print * p = malloc(sizeof(Print));
		AST_Node * node = malloc(sizeof(AST_Node));

		p->newline = 1;
		p->mode = STRINGLITERAL;
		p->sl = n1->stringliteral;

		s->mode = PRINT;
		s->p = p;
		s->n = node;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case PRINTEXP:
	{
		Statement * s = malloc(sizeof(Statement));
		Print * p = malloc(sizeof(Print));
		AST_Node * node = malloc(sizeof(AST_Node));

		p->newline = 0;
		p->mode = EXP;
		p->e = n1->exp;

		s->mode = PRINT;
		s->p = p;
		s->n = node;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case PRINTSTR:
	{
		Statement * s = malloc(sizeof(Statement));
		Print * p = malloc(sizeof(Print));
		AST_Node * node = malloc(sizeof(AST_Node));

		p->newline = 0;
		p->mode = STRINGLITERAL;
		p->sl = n1->stringliteral;

		s->mode = PRINT;
		s->p = p;
		s->n = node;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case RET:
	{
		Statement * s = malloc(sizeof(Statement));
		AST_Node * node = malloc(sizeof(AST_Node));

		s->mode = RET;
		s->e = n1->exp;
		s->n = node;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case INDEX:
	{
		Index * ix = malloc(sizeof(Index));
		AST_Node * node = malloc(sizeof(AST_Node));

		ix->mode = EXP;
		ix->e = n1->exp;
		ix->n = node;

		node->mode = INDEX;
		node->index = ix;

		return node;
	}
	case NEGATE:
	{
		return unaryOp(NEGATE, n1->exp);
	}
	case MINUS:
	{
		return unaryOp(MINUS, n1->exp);
	}
	case PLUS:
	{
		return unaryOp(PLUS, n1->exp);
	}
	case EXPINT:
	{
		Exp * e = malloc(sizeof(Exp));
		AST_Node * node = malloc(sizeof(AST_Node));

		e->mode = INTEGERLITERAL;
		e->il = n1->integerliteral;
		e->n = node;

		// propagate type and value
		e->type = INT;
		e->value = n1->integerliteral->value;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case EXPOBJECT:
	{
		Exp * e = malloc(sizeof(Exp));
		AST_Node * node = malloc(sizeof(AST_Node));

		e->mode = OBJECT;
		e->o = n1->object;
		e->n = node;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case PAREN:
	{
		Exp * e = malloc(sizeof(Exp));
		ParenExp * pe = malloc(sizeof(ParenExp));
		AST_Node * node = malloc(sizeof(AST_Node));

		pe->e = n1->exp;

		e->mode = PAREN;
		e->pe = pe;
		e->n = node;

		// propagate type and value
		if (n1->exp->type != 0) {
			e->type = n1->exp->type;
			e->value = n1->exp->value;
		}

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case IDENTIFIERLEN:
	{
		Exp * e = malloc(sizeof(Exp));
		IdentifierLength * ilen = malloc(sizeof(IdentifierLength));
		AST_Node * node = malloc(sizeof(AST_Node));

		ilen->i = n1->identifier;

		e->mode = IDENTIFIERLEN;
		e->ilen = ilen;
		e->n = node;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case OBJID:
	{
		Object * o = malloc(sizeof(Object));
		AST_Node * node = malloc(sizeof(AST_Node));

		o->mode = IDENTIFIER;
		o->i = n1->identifier;
		o->n = node;

		node->mode = OBJECT;
		node->object = o;

		return node;
	}
	case NEWOBJ:
	{
		Object * o = malloc(sizeof(Object));
		NewObject * no = malloc(sizeof(NewObject));
		AST_Node * node = malloc(sizeof(AST_Node));

		no->i = n1->identifier;

		o->mode = NEWOBJ;
		o->no = no;
		o->n = node;

		node->mode = OBJECT;
		node->object = o;

		return node;
	}
	case EXPREST:
	{
		ExpRest * er = malloc(sizeof(ExpRest));
		AST_Node * node = malloc(sizeof(AST_Node));

		er->e = n1->exp;
		er->n = node;

		node->mode = EXPREST;
		node->exprest = er;

		return node;
	}
	}
}

AST_Node * mknode2(int mode, AST_Node * n1, AST_Node * n2) {
	switch (mode) 
	{	
	case PROGRAM:
	{
		Program * p = malloc(sizeof(Program));
		AST_Node * node = malloc(sizeof(AST_Node));

		p->m = n1->mainclass;
		p->cl = n2->classdecllist;

		node->mode = PROGRAM;
		node->program = p;

		return node;
	}
	case CLASSDECLLIST:
	{
		if (n1->classdecllist->head == NULL) 
		{
			n1->classdecllist->head = n2->classdecl;
			n1->classdecllist->tail = n2->classdecl;
		}
		else 
		{
			n1->classdecllist->tail->next = n2->classdecl;
			n1->classdecllist->tail = n2->classdecl;
		}
		return n1;
	}
	case VARDECLLIST:
	{
		if (n1->vardecllist->head == NULL) {
			n1->vardecllist->head = n2->vardecl;
			n1->vardecllist->tail = n2->vardecl;
		}
		else {
			n1->vardecllist->tail->next = n2->vardecl;
			n1->vardecllist->tail = n2->vardecl;
		}
		return n1;
	}
	case VARDECL:
	{
		VarDecl * vd = malloc(sizeof(VarDecl));
		AST_Node * node = malloc(sizeof(AST_Node));

		vd->t = n1->type;
		vd->i = n2->identifier;
		vd->n = node;

		node->mode = VARDECL;
		node->vardecl = vd;

		return node;
	}
	case METHODDECLLIST:
	{
		if (n1->methoddecllist->head == NULL) {
			n1->methoddecllist->head = n2->methoddecl;
			n1->methoddecllist->tail = n2->methoddecl;
		}
		else {
			n1->methoddecllist->tail->next = n2->methoddecl;
			n1->methoddecllist->tail = n2->methoddecl;
		}
		return n1;
	}
	case FORMALRESTLIST:
	{
		if (n1->formalrestlist->head == NULL) {
			n1->formalrestlist->head = n2->formalrest;
			n1->formalrestlist->tail = n2->formalrest;
		}
		else {
			n1->formalrestlist->tail->next = n2->formalrest;
			n1->formalrestlist->tail = n2->formalrest;
		}
		return n1;
	}
	case FORMALREST:
	{
		FormalRest * fr = malloc(sizeof(FormalRest));
		AST_Node * node = malloc(sizeof(AST_Node));

		fr->t = n1->type;
		fr->i = n2->identifier;
		fr->n = node;

		node->mode = FORMALREST;
		node->formalrest = fr;

		return node;
	}
	case STATEMENTLIST:
	{		
		n1->statementlist->tail->next = n2->statement;
		n1->statementlist->tail = n2->statement;
		return n1;
	}
	case WHILE:
	{
		Statement * s = malloc(sizeof(Statement));
		While * w = malloc(sizeof(While));
		AST_Node * node = malloc(sizeof(AST_Node));

		w->e = n1->exp;
		w->s = n2->statement;

		s->mode = WHILE;
		s->w = w;
		s->n = node;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case ASSGN:
	{
		Statement * s = malloc(sizeof(Statement));
		Assign * a = malloc(sizeof(Assign));
		AST_Node * node = malloc(sizeof(AST_Node));

		a->i = n1->identifier;
		a->e = n2->exp;

		s->mode = ASSGN;
		s->a = a;
		s->n = node;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case INDEX:
	{
		Index * ix = malloc(sizeof(Index));
		MultiIndex * mi = malloc(sizeof(MultiIndex));
		AST_Node * node = malloc(sizeof(AST_Node));

		mi->ix = n1->index;
		mi->e = n2->exp;

		ix->mode = MULTIINDEX;
		ix->mi = mi;
		ix->n = node;

		node->mode = INDEX;
		node->index = ix;

		return node;
	}
	case AND:
		return binaryOp(AND, n1->exp, n2->exp);
	case OR:
		return binaryOp(OR, n1->exp, n2->exp);
	case EQ:
		return binaryOp(EQ, n1->exp, n2->exp);
	case NOTEQ:
		return binaryOp(NOTEQ, n1->exp, n2->exp);
	case LESSTHANEQ:
		return binaryOp(LESSTHANEQ, n1->exp, n2->exp);
	case GREATTHANEQ:
		return binaryOp(GREATTHANEQ, n1->exp, n2->exp);
	case LESSTHAN:
		return binaryOp(LESSTHAN, n1->exp, n2->exp);
	case GREATTHAN:
		return binaryOp(GREATTHAN, n1->exp, n2->exp);
	case PLUS:
		return binaryOp(PLUS, n1->exp, n2->exp);
	case MINUS:
		return binaryOp(MINUS, n1->exp, n2->exp);
	case TIMES:
		return binaryOp(TIMES, n1->exp, n2->exp);
	case DIVIDE:
		return binaryOp(DIVIDE, n1->exp, n2->exp);
	case ARRLOOKUP:
	{
		Exp * e = malloc(sizeof(Exp));
		ArrayLookup * alook = malloc(sizeof(ArrayLookup));
		AST_Node * node = malloc(sizeof(AST_Node));

		alook->i = n1->identifier;
		alook->ix = n2->index;

		e->mode = ARRLOOKUP;
		e->alook = alook;
		e->n = node;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case ARRLEN:
	{
		Exp * e = malloc(sizeof(Exp));
		ArrayLength * alen = malloc(sizeof(ArrayLength));
		AST_Node * node = malloc(sizeof(AST_Node));

		alen->i = n1->identifier;
		alen->ix = n2->index;

		e->mode = ARRLEN;
		e->alen = alen;
		e->n = node;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case NEWARR:
	{
		Object * o = malloc(sizeof(Object));
		NewArray * na = malloc(sizeof(NewArray));
		AST_Node * node = malloc(sizeof(AST_Node));

		na->pt = n1->primtype;
		na->ix = n2->index;

		o->mode = NEWARR;
		o->na = na;
		o->n = node;

		node->mode = OBJECT;
		node->object = o;

		return node;
	}
	case EXPLIST:
	{
		ExpList * el = malloc(sizeof(ExpList));
		AST_Node * node = malloc(sizeof(AST_Node));

		el->e = n1->exp;
		el->erl = n2->exprestlist;
		el->n = node;

		node->mode = EXPLIST;
		node->explist = el;

		return node;
	}
	case EXPRESTLIST:
	{
		if (n1->exprestlist->head == NULL) 
		{
			n1->exprestlist->head = n2->exprest;
			n1->exprestlist->tail = n2->exprest;
		}
		else 
		{
			n1->exprestlist->tail->next = n2->exprest;
			n1->exprestlist->tail = n2->exprest;
		}
		return n1;
	}
	}
}

AST_Node * mknode3(int mode, AST_Node * n1, AST_Node * n2, AST_Node * n3) {
	switch (mode) {
	case MAINCLASS:
	{
		MainClass * m = malloc(sizeof(MainClass));
		AST_Node * node = malloc(sizeof(AST_Node));

		m->i1 = n1->identifier;
		m->i2 = n2->identifier;
		m->s = n3->statement;
		m->n = node;

		node->mode = MAINCLASS;
		node->mainclass = m;

		return node;
	}
	case CLASSDECL:
	{
		ClassDecl * c = malloc(sizeof(ClassDecl));
		ClassDeclSimple * cs = malloc(sizeof(ClassDeclSimple));
		AST_Node * node = malloc(sizeof(AST_Node));

		cs->i = n1->identifier;
		cs->vl = n2->vardecllist;
		cs->ml = n3->methoddecllist;

		c->mode = CLASSDECLSIMPLE;
		c->cs = cs;
		c->n = node;

		node->mode = CLASSDECL;
		node->classdecl = c;

		return node;
	}
	case FORMALLIST:
	{
		FormalList * fl = malloc(sizeof(FormalList));
		AST_Node * node = malloc(sizeof(AST_Node));

		fl->t = n1->type;
		fl->i = n2->identifier;
		fl->fr = n3->formalrestlist;
		fl->n = node;

		node->mode = FORMALLIST;
		node->formallist = fl;

		return node;
	}
	case IF:
	{
		Statement * s = malloc(sizeof(Statement));
		If * i = malloc(sizeof(If));
		AST_Node * node = malloc(sizeof(AST_Node));

		i->e = n1->exp;
		i->s1 = n2->statement;
		i->s2 = n3->statement;

		s->mode = IF;
		s->i = i;
		s->n = node;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case ARRASSGN:
	{
		Statement * s = malloc(sizeof(Statement));
		ArrayAssign * aa = malloc(sizeof(ArrayAssign));
		AST_Node * node = malloc(sizeof(AST_Node));

		aa->i = n1->identifier;
		aa->ix = n2->index;
		aa->e = n3->exp;

		s->mode = ARRASSGN;
		s->aa = aa;
		s->n = node;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case CALL:
	{
		Exp * e = malloc(sizeof(Exp));
		Call * c = malloc(sizeof(Call));
		AST_Node * node = malloc(sizeof(AST_Node));

		c->o = n1->object;
		c->i = n2->identifier;
		c->el = n3->explist;

		e->mode = CALL;
		e->c = c;
		e->n = node;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	}
}

AST_Node * mknode4(int mode, AST_Node * n1, AST_Node * n2, AST_Node * n3, AST_Node * n4) {
	switch (mode) {
	case CLASSDECL:
	{
		ClassDecl * c = malloc(sizeof(ClassDecl));
		ClassDeclExtends * ce = malloc(sizeof(ClassDeclExtends));
		AST_Node * node = malloc(sizeof(AST_Node));

		ce->i1 = n1->identifier;
		ce->i2 = n2->identifier;
		ce->vl = n3->vardecllist;
		ce->ml = n4->methoddecllist;

		c->mode = CLASSDECLEXTENDS;
		c->ce = ce;
		c->n = node;

		node->mode = CLASSDECL;
		node->classdecl = c;

		return node;
	}
	}	
}

AST_Node * mknode5(int mode, AST_Node * n1, AST_Node * n2, AST_Node * n3, AST_Node * n4, AST_Node * n5) {
	switch (mode) {
	case METHODDECL:
	{
		MethodDecl * md = malloc(sizeof(MethodDecl));
		AST_Node * node = malloc(sizeof(AST_Node));

		md->t = n1->type;
		md->i = n2->identifier;
		md->fl = n3->formallist;
		md->vl = n4->vardecllist;
		md->e = n5->exp;
		md->n = node;

		node->mode = METHODDECL;
		node->methoddecl = md;

		return node;
	}
	}
}

AST_Node * mknode6(int mode, AST_Node * n1, AST_Node * n2, AST_Node * n3, AST_Node * n4, AST_Node * n5, AST_Node * n6) {
	switch (mode) {
	case METHODDECL:
	{
		MethodDecl * md = malloc(sizeof(MethodDecl));
		AST_Node * node = malloc(sizeof(AST_Node));

		md->t = n1->type;
		md->i = n2->identifier;
		md->fl = n3->formallist;
		md->vl = n4->vardecllist;
		md->sl = n5->statementlist;
		md->e = n6->exp;
		md->n = node;

		node->mode = METHODDECL;
		node->methoddecl = md;

		return node;
	}
	}
}





































