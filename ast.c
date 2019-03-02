#include "y.tab.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

AST_Node * mknode0(int mode) {
	switch (mode) {
	case CLASSDECLLIST:
	{
		ClassDeclList * cl = malloc(sizeof(ClassDeclList));
		AST_Node * node = malloc(sizeof(AST_Node));

		node->mode = CLASSDECLLIST;
		node->classdecllist = cl;

		return node;
	}
	case VARDECLLIST:
	{
		VarDeclList * vl = malloc(sizeof(VarDeclList));
		AST_Node * node = malloc(sizeof(AST_Node));

		node->mode = VARDECLLIST;
		node->vardecllist = vl;

		return node;
	}
	case METHODDECLLIST:
	{
		MethodDeclList * ml = malloc(sizeof(MethodDeclList));
		AST_Node * node = malloc(sizeof(AST_Node));

		node->mode = METHODDECLLIST;
		node->methoddecllist = ml;

		return node;
	}
	case FORMALLIST:
	{
		FormalList * fl = malloc(sizeof(FormalList));
		AST_Node * node = malloc(sizeof(AST_Node));

		node->mode = FORMALLIST;
		node->formallist = fl;

		return node;
	}
	case FORMALRESTLIST:
	{
		FormalRestList * fl = malloc(sizeof(FormalRestList));
		AST_Node * node = malloc(sizeof(AST_Node));

		node->mode = FORMALRESTLIST;
		node->formalrestlist = fl;

		return node;
	}
	case STATEMENTLIST:
	{
		StatementList * sl = malloc(sizeof(StatementList));
		AST_Node * node = malloc(sizeof(AST_Node));

		node->mode = STATEMENTLIST;
		node->statementlist = sl;

		return node;
	}
	case BLOCK:
	{
		Statement * s = malloc(sizeof(Statement));
		Block * b = malloc(sizeof(Block));
		StatementList * sl = malloc(sizeof(StatementList));
		AST_Node * node = malloc(sizeof(AST_Node));

		b->sl = sl;

		s->mode = BLOCK;
		s->b = b;

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case OBJTHIS:
	{
		Object * o = malloc(sizeof(Object));
		This * t = malloc(sizeof(This));
		AST_Node * node = malloc(sizeof(AST_Node));

		o->mode = THIS;
		o->t = t;

		node->mode = OBJECT;
		node->object = o;

		return node;
	}
	case EXPRESTLIST:
	{
		ExpRestList * erl = malloc(sizeof(ExpRestList));
		AST_Node * node = malloc(sizeof(AST_Node));

		node->mode = EXPRESTLIST;
		node->exprestlist = erl;

		return node;
	}
	case PRIMTYPEINT:
	{
		PrimType * pt = malloc(sizeof(PrimType));
		IntegerType * it = malloc(sizeof(IntegerType));
		AST_Node * node = malloc(sizeof(AST_Node));

		pt->mode = INTEGERTYPE;
		pt->it = it;

		node->mode = PRIMTYPE;
		node->primtype = pt;

		return node;
	}
	case PRIMTYPEBOOL:
	{
		PrimType * pt = malloc(sizeof(PrimType));
		BooleanType * bt = malloc(sizeof(BooleanType));
		AST_Node * node = malloc(sizeof(AST_Node));

		pt->mode = BOOLEANTYPE;
		pt->bt = bt;

		node->mode = PRIMTYPE;
		node->primtype = pt;

		return node;
	}
	case EXPTRUE:
	{
		Exp * e = malloc(sizeof(Exp));
		Boolean * b = malloc(sizeof(Boolean));
		AST_Node * node = malloc(sizeof(AST_Node));

		b->value = 1;

		e->mode = BOOLEAN;
		e->b = b;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case EXPFALSE:
	{
		Exp * e = malloc(sizeof(Exp));
		Boolean * b = malloc(sizeof(Boolean));
		AST_Node * node = malloc(sizeof(AST_Node));

		b->value = 0;

		e->mode = BOOLEAN;
		e->b = b;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	}
}

AST_Node * mknode1(int mode, AST_Node * n1) {
	switch (mode) {
	case TYPEPRIM:
	{
		Type * t = malloc(sizeof(Type));
		AST_Node * node = malloc(sizeof(AST_Node));

		t->mode = PRIMTYPE;
		t->pt = n1->primtype;

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

		node->mode = STATEMENT;
		node->statement = s;

		return node;
	}
	case RET:
	{
		Statement * s = malloc(sizeof(Statement));
		AST_Node * node = malloc(sizeof(AST_Node));

		s->mode = EXP;
		s->e = n1->exp;

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

		node->mode = INDEX;
		node->index = ix;

		return node;
	}
	case NEGATE:
	{
		Exp * e = malloc(sizeof(Exp));
		UnaryOp * uo = malloc(sizeof(UnaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		uo->op = NEGATE;
		uo->e = n1->exp;

		e->mode = UNARYOP;
		e->uo = uo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case MINUS:
	{
		Exp * e = malloc(sizeof(Exp));
		UnaryOp * uo = malloc(sizeof(UnaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		uo->op = MINUS;
		uo->e = n1->exp;

		e->mode = UNARYOP;
		e->uo = uo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case PLUS:
	{
		Exp * e = malloc(sizeof(Exp));
		UnaryOp * uo = malloc(sizeof(UnaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		uo->op = PLUS;
		uo->e = n1->exp;

		e->mode = UNARYOP;
		e->uo = uo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case EXPINT:
	{
		Exp * e = malloc(sizeof(Exp));
		AST_Node * node = malloc(sizeof(AST_Node));

		e->mode = INTEGERLITERAL;
		e->il = n1->integerliteral;

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

		node->mode = OBJECT;
		node->object = o;

		return node;
	}
	case EXPREST:
	{
		ExpRest * er = malloc(sizeof(ExpRest));
		AST_Node * node = malloc(sizeof(AST_Node));

		er->e = n1->exp;

		node->mode = EXPREST;
		node->exprest = er;

		return node;
	}
	}
}

AST_Node * mknode2(int mode, AST_Node * n1, AST_Node * n2) {
	switch (mode) {	
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
		n1->classdecllist->curr->next = n2->classdecl;
		return n1;
	}
	case VARDECLLIST:
	{
		n1->vardecllist->curr->next = n2->vardecl;
		return n1;
	}
	case VARDECL:
	{
		VarDecl * vd = malloc(sizeof(VarDecl));
		AST_Node * node = malloc(sizeof(AST_Node));

		vd->t = n1->type;
		vd->i = n2->identifier;

		node->mode = VARDECL;
		node->vardecl = vd;

		return node;
	}
	case METHODDECLLIST:
	{
		n1->methoddecllist->curr->next = n2->methoddecl;
		return n1;
	}
	case FORMALRESTLIST:
	{
		n1->formalrestlist->curr->next = n2->formalrest;
		return n1;
	}
	case FORMALREST:
	{
		FormalRest * fr = malloc(sizeof(FormalRest));
		AST_Node * node = malloc(sizeof(AST_Node));

		fr->t = n1->type;
		fr->i = n2->identifier;

		node->mode = FORMALREST;
		node->formalrest = fr;

		return node;
	}
	case STATEMENTLIST:
	{
		n1->statementlist->curr->next = n2->statement;
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

		s->mode = ASSIGN;
		s->a = a;

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

		node->mode = INDEX;
		node->index = ix;

		return node;
	}
	case AND:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = AND;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case OR:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = OR;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case EQ:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = EQ;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case NOTEQ:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = NOTEQ;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case LESSTHANEQ:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = LESSTHANEQ;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case GREATTHANEQ:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = GREATTHANEQ;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case LESSTHAN:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = LESSTHAN;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case GREATTHAN:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = GREATTHAN;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case PLUS:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = PLUS;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case MINUS:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = MINUS;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case TIMES:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = TIMES;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case DIVIDE:
	{
		Exp * e = malloc(sizeof(Exp));
		BinaryOp * bo = malloc(sizeof(BinaryOp));
		AST_Node * node = malloc(sizeof(AST_Node));

		bo->op = DIVIDE;
		bo->e1 = n1->exp;
		bo->e2 = n2->exp;

		e->mode = BINARYOP;
		e->bo = bo;

		node->mode = EXP;
		node->exp = e;

		return node;
	}
	case ARRLOOKUP:
	{
		Exp * e = malloc(sizeof(Exp));
		ArrayLookup * alook = malloc(sizeof(ArrayLookup));
		AST_Node * node = malloc(sizeof(AST_Node));

		alook->i = n1->identifier;
		alook->ix = n2->index;

		e->mode = ARRLOOKUP;
		e->alook = alook;

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

		node->mode = EXPLIST;
		node->explist = el;

		return node;
	}
	case EXPRESTLIST:
	{
		n1->exprestlist->curr->next = n2->exprest;
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
		StatementList * sl = malloc(sizeof(StatementList));
		AST_Node * node = malloc(sizeof(AST_Node));

		md->t = n1->type;
		md->i = n2->identifier;
		md->fl = n3->formallist;
		md->vl = n4->vardecllist;
		md->sl = sl;
		md->e = n5->exp;

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

		node->mode = METHODDECL;
		node->methoddecl = md;

		return node;
	}
	}
}





































