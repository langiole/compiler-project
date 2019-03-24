#include <stdio.h>
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
#include "typecheck.h"
#include "dfs.h"

PrimType * getPrimType(Type * t) {
	if (t->mode == ARRAYTYPE) { while (t->mode == ARRAYTYPE) { t = t->at->t; } }
	return t->pt;
}

char * typeToString(Type * t) {
	PrimType * pt = getPrimType(t);
	switch (pt->mode)
	{
	case INT:
		return "int";
	case BOOLEAN:
		return "boolean";
	case IDENTIFIER:
		return pt->i->name;
	}
}

void printUnknownSymbolErr(Identifier * i, int lineno) {
	fprintf(stderr, "Type Violation in Line %d : cannot find symbol %s\n", lineno, i->name);
}

void printIncompatibleTypeErr(Type * t, int lineno) {
	fprintf(stderr, "Type Violation in Line %d : incompatible type: %s\n", lineno, typeToString(t));
}

void printIncompatibleTypeBoolErr(Type * t, int lineno) {
	fprintf(stderr, "Type Violation in Line %d : incompatible type: %s cannot be converted to boolean\n", lineno, typeToString(t));
}

void printIncompatibleTypeIntErr(Type * t, int lineno) {
	fprintf(stderr, "Type Violation in Line %d : incompatible type: %s cannot be converted to int\n", lineno, typeToString(t));
}

void printCannotDereferenceErr(Type * t, int lineno) {
	fprintf(stderr, "Type Violation in Line %d : incompatible type: %s cannot be dereferenced\n", lineno, typeToString(t));
}

void printIncompatibleTypesErr(Type * t1, Type * t2, int lineno) {
	fprintf(stderr, "Type Violation in Line %d : incompatible types: %s cannot be converted to %s\n", lineno, typeToString(t1), typeToString(t2));
}

void printRedefinedVarErr(Identifier * i, int lineno) {
	fprintf(stderr, "Type Violation in Line %d : variable %s is already defined\n", lineno, i->name);
}

void printRedefinedMethodErr(MethodDecl * md, int lineno) {
	fprintf(stderr, "Type Violation in Line %d :  method %s() is already defined\n", lineno, md->i->name);
}

void printCyclicInheritanceErr(Identifier * i, int lineno) {
	fprintf(stderr, "Type Violation in Line %d : cyclic inheritance involving %s\n", lineno, i->name);
}

void printNonStaticVarErr(int lineno) {
	fprintf(stderr, "Type Violation in Line %d : non-static variable this cannot be referenced from a static context\n", lineno);	
}

void printArrayRequiredErr(Type * t, int lineno) {
	fprintf(stderr, "Type Violation in Line %d : array required, but %s found\n", lineno, typeToString(t));	
}

int typeIsInt(Type * t) {
	if (t->mode != PRIMTYPE) { return 0; }
	if (t->pt->mode != INT) { return 0; }
	return 1;
}

int typeIsBoolean(Type * t) {
	if (t->mode != PRIMTYPE) { return 0; }
	if (t->pt->mode != BOOLEAN) { return 0; }
	return 1;
}

int identifiersEqual(Identifier * i1, Identifier * i2) {
	if (strcmp(i1->name, i2->name) == 0) { return 1; }
	else { return 0; }
}

Identifier * extractID(Type * t) {
	while (t->mode == ARRAYTYPE) { t = t->at->t; }
	if (t->pt->mode == IDENTIFIER) { return t->pt->i; }
	return 0;
}

// top town search of vardecllist
Type * searchVarDeclList(VarDeclList * vl, Identifier * i) {
	VarDecl * curr = vl->head;
	while (curr != NULL)
	{
		if (identifiersEqual(i, curr->i))
			return curr->t;
		curr = curr->next;
	}
	return 0;
}

// bottom up search of formal list
Type * searchFormalList(FormalList * fl, Identifier * i) {
	FormalRest * curr = fl->tail;
	while (curr != NULL)
	{
		if (identifiersEqual(i, curr->i))
			return curr->t;
		curr = curr->prev;
	}
	return 0;
}

ClassDecl * findClass(Identifier * i) {
	ClassDecl * curr = CLASS_DECL_LIST->head;
	while (curr != NULL) 
	{
		if (identifiersEqual(curr->i1, i))
			return curr;
		curr = curr->next;
	}
	return 0;
}

Type * findVar(Identifier * i) {

	Type * t;

	// search current method variables
	if (CURR_METHOD != NULL)
	{
		// top down search of vardecllist
		t = searchVarDeclList(CURR_METHOD->vl, i);

		if (t != NULL) { return t; }
	
		//  bottom up search of the formallist
		t = searchFormalList(CURR_METHOD->fl, i);

		if (t != NULL) { return t; }
	}

	// search current class and extended class variables
	if (CURR_CLASS != NULL)
	{
		// top down search of vardecllist in current class
		t = searchVarDeclList(CURR_CLASS->vl, i);

		if (t != NULL) { return t; }

		// top down search of vardecllist in extended class
		if (CURR_CLASS->mode == CLASSDECLEXTENDS)
		{
			ClassDecl * extendedClass = findClass(CURR_CLASS->i2);

			while (extendedClass != NULL)
			{
				// top down search of vardecllist in extended class
				t = searchVarDeclList(extendedClass->vl, i);

				if (t != NULL) { return t; }
				if (extendedClass->mode != CLASSDECLEXTENDS) { return 0; }
				extendedClass = findClass(extendedClass->i2);
			}
		}
	}
	return 0;
}

int typecheckPrint(Print * p, int lineno) {
	if (p->mode == EXP)
	{
		// typecheck exp + propagate
		dfs(p->e->n);

		if (p->e->type == NULL) { return 0; }
		if (typeIsInt(p->e->type)) { return 0; }
		
		printIncompatibleTypeErr(p->e->type, lineno);
		return 1;
	}
	return 0;
}

int typecheckType(Type * t, int lineno) {

	Identifier * i = extractID(t);
	if (i == NULL) { return 0; }

	// check if i is a valid class
	if (findClass(i) != NULL) { return 0; }

	printUnknownSymbolErr(i, lineno);
	return 1;
}

int typecheckWhile(While * w, int lineno) {

	// typecheck exp + propagate type
	dfs(w->e->n);

	// check if type is valid
	if (w->e->type == NULL) { return 0; }
	if (typeIsBoolean(w->e->type)) { return 0; }
	
	printIncompatibleTypeBoolErr(w->e->type, lineno);
	
	// typecheck statement
	dfs(w->s->n);

	return 1;
}

int typecheckIf(If * i, int lineno) {

	// typecheck exp + propagate type
	dfs(i->e->n);

	// check if type is valid
	if (i->e->type == NULL) { return 0; }
	if (typeIsBoolean(i->e->type)) { return 0; }
	
	printIncompatibleTypeBoolErr(i->e->type, lineno);
	
	// typecheck statements
	dfs(i->s1->n);
	dfs(i->s2->n);

	return 1;
}

int typesEqual(Type * t1, Type * t2) {

	if (t1->mode != t2->mode) { return 0; }

	switch (t1->mode)
	{
	case PRIMTYPE:
		if (t1->pt->mode != t2->pt->mode) { return 0; }
		else if (t1->pt->mode != IDENTIFIER) { return 1; }
		else if (identifiersEqual(t1->pt->i, t2->pt->i)) { return 1; }
		else { return 0; }
	case ARRAYTYPE:
		while (t1->mode == ARRAYTYPE)
		{
			t1 = t1->at->t;
			t2 = t2->at->t;
			if (t1->mode != t2->mode) { return 0; }
		}
		if (t1->pt->mode != t2->pt->mode) { return 0; }
		else if (t1->pt->mode != IDENTIFIER) { return 1; }
		else if (identifiersEqual(t1->pt->i, t2->pt->i)) { return 1; }
		else { return 0; }
	}
}

int typecheckReturn(Exp * e, int lineno) {

	// typecheck exp + propagate
	dfs(e->n);

	// check if return type equals method return type
	if (e->type == NULL) { return 0; }
	if (typesEqual(e->type, CURR_METHOD->t)) { return 0; }
	
	printIncompatibleTypesErr(e->type, CURR_METHOD->t, lineno);
	return 1;
}

int typecheckAssign(Assign * a, int lineno) {

	// typecheck exp + propagate
	dfs(a->e->n);

	Type * t1 = findVar(a->i);
	Type * t2 = a->e->type;

	// check if var is a valid type
	if (t1 == NULL)
	{
		printUnknownSymbolErr(a->i, lineno);
		return 1;
	}

	// check if types equal
	if (t2 == NULL) { return 1; }
	if (typesEqual(t1, t2)) { return 0; }

	printIncompatibleTypesErr(t1, t2, lineno);
	return 1;
}

int formalListsEqual(FormalList * fl1, FormalList * fl2) {
	FormalRest * curr1 = fl1->head;
	FormalRest * curr2 = fl2->head;
	while (curr1 != NULL || curr2 != NULL)
	{
		if (curr1 == NULL || curr2 == NULL) { return 0; }
		if (!typesEqual(curr1->t, curr2->t)) { return 0; }
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	return 1;
}

int typecheckMethodDecl(MethodDecl * md, int lineno) {

	// set curr method
	CURR_METHOD = md;

	// typecheck type
	dfs(md->t->n);

	// typecheck formallist
	dfs(md->fl->n);

	// typecheck vardecllist
	VarDecl * currVd = md->vl->head;
	while (currVd != NULL)
	{
		// check if var exists in formallist if it is unique in the vardecllist
		if (!typecheckVarDecl(currVd, currVd->n->lineno))
		{
			if (searchFormalList(md->fl, currVd->i) != 0)
				printRedefinedVarErr(currVd->i, currVd->n->lineno);
		}
		else { TYPEERR = 1; }
		currVd = currVd->next;
	}

	// typecheck statements
	dfs(md->sl->n);

	// check if return type equals method type
	if (typecheckReturn(md->e, md->e->n->lineno)) { TYPEERR = 1; }

	// check if method is already defined
	MethodDecl * currMd = md->prev;
	while (currMd != NULL) 
	{
		if (identifiersEqual(md->i, currMd->i) && formalListsEqual(md->fl, currMd->fl))
		{
			printRedefinedMethodErr(md, lineno);
			return 1;
		}
		currMd = currMd->prev;
	}
	return 0;
}

int typecheckClassDecl(ClassDecl * cd, int lineno) {

	CURR_CLASS = cd;

	// check if class exists
	ClassDecl * curr = cd->prev;
	while (curr != NULL) 
	{
		if (identifiersEqual(curr->i1, cd->i1))
		{
			fprintf(stderr, "Type Violation in Line %d : duplicate class: %s\n", lineno, cd->i1->name);
			return 1;
		}
		curr = curr->prev;
	}

	// typecheck extended class
	if (cd->mode == CLASSDECLEXTENDS)
	{
		if (identifiersEqual(cd->i1, cd->i2))
		{
			printCyclicInheritanceErr(cd->i1, lineno);
			return 1;
		}
		if (findClass(cd->i2) == NULL) 
		{ 
			printUnknownSymbolErr(cd->i2, lineno); 
			return 1;
		}
	}

	// typecheck class contents
	dfs(cd->vl->n);
	dfs(cd->ml->n);

	return 0;
}

int typecheckFormalRest(FormalRest * fr, int lineno) {
	
	// typecheck type
	dfs(fr->t->n);

	// check for redefinitions
	FormalRest * curr = fr->prev;
	while (curr != NULL) 
	{
		if (identifiersEqual(curr->i, fr->i))
		{
			printRedefinedVarErr(fr->i, lineno);
			return 1;
		}
		curr = curr->prev;
	}
	return 0;	
}

int typecheckVarDecl(VarDecl * vd, int lineno) {

	// typecheck type
	dfs(vd->t->n);

	// check for redefinitions
	VarDecl * curr = vd->prev;
	while (curr != NULL) 
	{
		if (identifiersEqual(curr->i, vd->i))
		{
			printRedefinedVarErr(vd->i, lineno);
			return 1;
		}
		curr = curr->prev;
	}
	return 0;
}

int typecheckIntegerLiteral(Exp * e, int lineno) {
	// propagate type and value
	Type * t = malloc(sizeof(Type));
	PrimType * pt = malloc(sizeof(PrimType));

	pt->mode = INT;

	t->mode = PRIMTYPE;
	t->pt = pt;

	e->type = t;
}

int typecheckBoolean(Exp * e, int lineno) {
	// propagate type and value
	Type * t = malloc(sizeof(Type));
	PrimType * pt = malloc(sizeof(PrimType));

	pt->mode = BOOLEAN;

	t->mode = PRIMTYPE;
	t->pt = pt;

	e->type = t;
}

int argsMatchFormalList(ExpList * el, FormalList * fl) {
	Exp * currE = el->head;
	FormalRest * currFr = fl->head;
	while (currE != NULL || currFr != NULL)
	{
		if (currE == NULL || currFr == NULL) { return 0; }
		if (currE->type == NULL) { return 0; }
		if (!typesEqual(currE->type, currFr->t)) { return 0; }
		currE = currE->next;
		currFr = currFr->next;
	}
	return 1;
}

MethodDecl * findMethod(ClassDecl * cd, Identifier * i, ExpList * el) {
	MethodDecl * curr = cd->ml->head;
	while (curr != NULL)
	{
		if (identifiersEqual(i, curr->i) && argsMatchFormalList(el, curr->fl)) { return curr; }
		curr = curr->next;
	}
	if (cd->mode != CLASSDECLEXTENDS) { return 0; }

	// search extendedClass if it is found
	ClassDecl * extendedClass = findClass(cd->i2);
	if (extendedClass == NULL) { return 0; }
	return findMethod(extendedClass, i, el);
}

int typecheckCall(Exp * e, int lineno) {
	ClassDecl * cd;
	Object * o = e->c->o;

	// search for class
	switch (o->mode)
	{
	case IDENTIFIER:
	{
		Type * t = findVar(o->i);

		// check if var is declared
		if (t == NULL) 
		{ 
			printUnknownSymbolErr(o->i, lineno);
			return 1; 
		}

		// check if the type is prim
		if (t->mode != PRIMTYPE)
		{
			printCannotDereferenceErr(t, lineno);
			return 1;
		}

		// check if the type is id
		if (t->pt->mode != IDENTIFIER)
		{
			printCannotDereferenceErr(t, lineno);
			return 1;
		}

		// search for the class
		cd = findClass(t->pt->i);
		if (cd == NULL) 
		{
			printUnknownSymbolErr(o->i, lineno);
			return 1;
		}
		break;
	}
	case THIS:
	{
		cd = CURR_CLASS;
		break;
	}
	case NEWOBJ:
	{
		cd = findClass(o->no->i);
		if (cd == NULL) 
		{
			printUnknownSymbolErr(o->no->i, lineno);
			return 1;
		}
		break;
	}
	case NEWARR:
	{
		// set prim type
		Type * t = o->na->ix->t;
		while (t->mode == ARRAYTYPE) { t = t->at->t; }
		t->pt = o->na->pt;

		// typecheck type
		typecheckType(t, lineno);

		printCannotDereferenceErr(t, lineno);

		// continue typechecking
		dfs(o->na->ix->n);

		return 1;
	}
	}

	// typecheck explist
	dfs(e->c->el->n);

	// search for method
	MethodDecl * md = findMethod(cd, e->c->i, e->c->el);

	if (md == NULL)
	{
		printUnknownSymbolErr(e->c->i, lineno);
		return 1;
	}

	return 0;
}

int typecheckObject(Exp * e, int lineno) {
	Object * o = e->o;
	switch (o->mode)
	{
	case IDENTIFIER:
	{
		Type * t = findVar(o->i);

		if (t == NULL) 
		{ 
			printUnknownSymbolErr(o->i, lineno);
			return 1; 
		}

		e->type = t;
		return 0;
	}
	case THIS:
	{
		if (CURR_CLASS == NULL)
		{
			printNonStaticVarErr(lineno);
			return 1;
		}

		Type * t = malloc(sizeof(Type));
		PrimType * pt = malloc(sizeof(PrimType));

		pt->mode = IDENTIFIER;
		pt->i = CURR_CLASS->i1;

		t->mode = PRIMTYPE;
		t->pt = pt;

		e->type = t;
		return 0;
	}
	case NEWOBJ:
	{
		Type * t = malloc(sizeof(Type));
		PrimType * pt = malloc(sizeof(PrimType));

		pt->mode = IDENTIFIER;
		pt->i = o->no->i;

		t->mode = PRIMTYPE;
		t->pt = pt;

		e->type = t;

		if (typecheckType(t, lineno)) { return 1; }

		return 0;
	}
	case NEWARR:
	{
		// set prim type
		Type * t = o->na->ix->t;
		while (t->mode == ARRAYTYPE) { t = t->at->t; }
		t->pt = o->na->pt;

		// set exp type
		e->type = o->na->ix->t;

		// continue typechecking
		dfs(o->na->ix->n);

		// typecheck type
		if (typecheckType(t, lineno)) { return 1; }

		return 0;
	}
	}

}

int typecheckIndex(Index * ix, int lineno) {
	Type * t;
	switch (ix->mode)
	{
	case MULTIINDEX:
	{
		// typecheck exp + propagate
		dfs(ix->mi->e->n);
		t = ix->mi->e->type;
		break;
	}
	case EXP:
	{
		// typecheck exp + propagate
		dfs(ix->e->n);
		t = ix->e->type;
		break;
	}
	}

	// check if type is int
	if (t != NULL){
		if (!typeIsInt(t)) { 
			printIncompatibleTypeIntErr(t, lineno);
			TYPEERR = 1;
		}
	}

	// continue typechecking if multiindex
	if (ix->mode == MULTIINDEX) { dfs(ix->mi->ix->n); }

	return 0;
	
}

int typecheckParen(Exp * e, int lineno) {

	// typecheck exp + propagate
	dfs(e->pe->e->n);

	if (e->pe->e->type == NULL) { return 0; }

	// propagate type
	e->type = e->pe->e->type;

	return 0;
}

int typecheckIdentifierLen(Exp * e, int lineno) {
	Type * type = findVar(e->ilen->i);

	if (type == NULL) 
	{ 
		printUnknownSymbolErr(e->ilen->i, lineno);
		return 1;
	}
	if (type->mode != ARRAYTYPE)
	{ 
		printCannotDereferenceErr(type, lineno);
		return 1; 
	}

	Type * t = malloc(sizeof(Type));
	PrimType * pt = malloc(sizeof(PrimType));

	pt->mode = INT;

	t->mode = PRIMTYPE;
	t->pt = pt;

	e->type = t;

	return 0;
}

int getDimension(Type * t) {
	int dim = 0;
	while (t->mode == ARRAYTYPE) { t = t->at->t; dim++; }
	return dim;
}

Type * makeArrayType(PrimType * pt, int dim) {
	Type * t = malloc(sizeof(Type));

	// set primtype
	t->mode = PRIMTYPE;
	t->pt = pt;

	while (dim != 0)
	{
		// set arraytype
		Type * temp = malloc(sizeof(Type));
		ArrayType * at = malloc(sizeof(ArrayType));

		temp->mode = ARRAYTYPE;
		temp->at = at;

		at->t = t;

		t = temp;
		dim--;
	}

	return t;
}

int typecheckArrayLookup(Exp * e, int lineno) {
	Type * t1 = findVar(e->alook->i);

	// check if var is a valid type
	if (t1 == NULL)
	{
		printUnknownSymbolErr(e->alook->i, lineno);

		// typecheck index
		dfs(e->alook->ix->n);
		return 1;
	}

	// typecheck index
	dfs(e->alook->ix->n);

	// set prim type
	Type * temp = e->alook->ix->t;
	while (temp->mode == ARRAYTYPE) { temp = temp->at->t; }
	temp->pt = getPrimType(t1);

	// get dimensions of id type and index type
	int dim1 = getDimension(t1);
	int dim2 = getDimension(e->alook->ix->t);
	if (dim1 < dim2)
	{
		printArrayRequiredErr(e->alook->ix->t, lineno);
		return 1;
	}

	e->type = makeArrayType(getPrimType(t1), dim1-dim2);
	return 0;
}

int typecheckArrayAssign(ArrayAssign * aa, int lineno) {

	// typecheck exp + propagate
	dfs(aa->e->n);

	Type * t1 = findVar(aa->i);
	Type * t2 = aa->e->type;

	// check if var is a valid type
	if (t1 == NULL)
	{
		printUnknownSymbolErr(aa->i, lineno);

		// typecheck index
		dfs(aa->ix->n);
		return 1;
	}

	// typecheck index
	dfs(aa->ix->n);

	// set prim type
	Type * temp = aa->ix->t;
	while (temp->mode == ARRAYTYPE) { temp = temp->at->t; }
	temp->pt = getPrimType(t1);

	// get dimensions of id type and index type
	int dim1 = getDimension(t1);
	int dim2 = getDimension(aa->ix->t);
	if (dim1 < dim2)
	{
		printArrayRequiredErr(aa->ix->t, lineno);
		return 1;
	}

	// check if types equal
	if (t2 == NULL) { return 1; }

	Type * t3 = makeArrayType(getPrimType(t1), dim1-dim2);
	if (typesEqual(t2, t3)) { return 0; }

	printIncompatibleTypesErr(t2, t3, lineno);
	return 1;
}

int typecheckArrayLen(Exp * e, int lineno) {
	Type * type = findVar(e->alen->i);

	if (type == NULL) 
	{ 
		printUnknownSymbolErr(e->alen->i, lineno);
		
		// typecheck index
		dfs(e->alen->ix->n);
		return 1;
	}

	// typecheck index
	dfs(e->alen->ix->n);

	// get dimensions of id type and index type
	int dim1 = getDimension(type);
	int dim2 = getDimension(e->alen->ix->t);
	if (dim1 <= dim2)
	{
		printCannotDereferenceErr(type, lineno);
		return 1; 
	}

	Type * t = malloc(sizeof(Type));
	PrimType * pt = malloc(sizeof(PrimType));

	pt->mode = INT;

	t->mode = PRIMTYPE;
	t->pt = pt;

	e->type = t;

	return 0;
}

int typecheckBinaryOp(Exp * e, int lineno) {
	int op = e->bo->op;

	// typecheck exps + propagate
	dfs(e->bo->e1->n);
	dfs(e->bo->e2->n);

	Type * type1 = e->bo->e1->type;
	Type * type2 = e->bo->e2->type;

	if (type1 == NULL || type2 == NULL) { return 1; }

	if (op == AND || op == OR)
	{
		if (!typeIsBoolean(type1) || !typeIsBoolean(type2))
		{
			fprintf(stderr, "Type Violation in Line %d : operand(s) not of type boolean\n", lineno);
			return 1;
		}
	}
	else if (op == EQ || op == NOTEQ)
	{
		if (!((typeIsBoolean(type1) && typeIsBoolean(type2))
			|| (typeIsInt(type1) && typeIsInt(type2))))
		{
			fprintf(stderr, "Type Violation in Line %d : both operands not one of boolean or int\n", lineno);
			return 1;
		}
	}
	else if (op == LESSTHANEQ || op == GREATTHANEQ || op == LESSTHAN || op == GREATTHAN || op == PLUS || op == MINUS || op == TIMES || op == DIVIDE)
	{
		if (!typeIsInt(type1) || !typeIsInt(type2))
		{
			fprintf(stderr, "Type Violation in Line %d : operand(s) not of type int\n", lineno);
			return 1;
		}
	}

	// propagate type
	Type * t = malloc(sizeof(Type));
	PrimType * pt = malloc(sizeof(PrimType));

	if (op == AND || op == OR || op == EQ || op == NOTEQ
		|| op == LESSTHANEQ || op == GREATTHANEQ || op == LESSTHAN || op == GREATTHAN)
		pt->mode = BOOLEAN;
	
	if (op == PLUS || op == MINUS || op == TIMES || op == DIVIDE)
		pt->mode = INT;

	t->mode = PRIMTYPE;
	t->pt = pt;
	e->type = t;
	
	return 0;
}

int typecheckUnaryOp(Exp * e, int lineno) {
	int op = e->uo->op;

	// typecheck exp + propagate
	dfs(e->uo->e->n);

	Type * type = e->uo->e->type;

	if (op == PLUS || op == MINUS)
	{
		if (!typeIsInt(type))
		{
			fprintf(stderr, "Type Violation in Line %d : operand not of type int\n", lineno);	
			return 1;
		}
	}
	else if (op == NEGATE)
	{
		if (!typeIsBoolean(type))
		{
			fprintf(stderr, "Type Violation in Line %d : operand not of type boolean\n", lineno);	
			return 1;
		}
	}

	// propagate type
	Type * t = malloc(sizeof(Type));
	PrimType * pt = malloc(sizeof(PrimType));

	if (op == PLUS || op == MINUS)
		pt->mode = INT;

	if (op == NEGATE)
		pt->mode = BOOLEAN;

	t->mode = PRIMTYPE;
	t->pt = pt;
	e->type = t;

	return 0;
}
