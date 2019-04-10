#include "y.tab.h"
#include <stdio.h>
#include "typecheck.h"
#include <stdlib.h>
#include "dfs.h"

void dfs(AST_Node * root) {
	switch (root->mode) 
	{
	case PROGRAM:
		CLASS_DECL_LIST = root->program->cl;

		if (TYPECHECK)
		{
			dfs(root->program->m->n);
			dfs(root->program->cl->n);
		}
		else
		{ dfs(root->program->m->n); }

		break;
	case MAINCLASS:
		dfs(root->mainclass->s->n);
		break;
	case CLASSDECLLIST:
	{
		ClassDecl * curr = root->classdecllist->head;
		while (curr != NULL) 
		{
			dfs(curr->n);
			curr = curr->next;
		}
		break;
	}
	case CLASSDECL:
		if (TYPECHECK)
		{
			if (typecheckClassDecl(root->classdecl, root->classdecl->i1->n->lineno))
				TYPEERR = 1;
		}
		break;
	case VARDECLLIST:
	{
		VarDecl * curr = root->vardecllist->head;
		while (curr != NULL) 
		{
			dfs(curr->n);
			curr = curr->next;
		}
		break;
	}
	case VARDECL:
		if (TYPECHECK)
		{
			if (typecheckVarDecl(root->vardecl, root->lineno));
				TYPEERR = 1;
		}
		break;
	case METHODDECLLIST:
	{
		MethodDecl * curr = root->methoddecllist->head;
		while (curr != NULL) 
		{
			dfs(curr->n);			
			curr = curr->next;
		}
		break;
	}
	case METHODDECL:
		if (TYPECHECK)
		{
			if (typecheckMethodDecl(root->methoddecl, root->methoddecl->i->n->lineno))
				TYPEERR = 1;
		}
		break;
	case FORMALLIST:
	{
		FormalRest * curr = root->formallist->head;
		while (curr != NULL) 
		{
			dfs(curr->n);			
			curr = curr->next;
		}
		break;
	}
	case FORMALREST:
		if (TYPECHECK)
		{
			if (typecheckFormalRest(root->formalrest, root->lineno))
				TYPEERR = 1;
		}
		break;
	case TYPE:
	{
		if (TYPECHECK)
		{
			if (typecheckType(root->type, root->lineno))
				TYPEERR = 1;

		}
		break;
	}
	case STATEMENTLIST:
	{
		Statement * curr = root->statementlist->head;
		if (TYPECHECK)
		{
			while (curr != NULL) 
			{
				dfs(curr->n);
				curr = curr->next;
			}
		}
		else { if (curr != NULL) { dfs(curr->n); } }
		break;
	}
	case STATEMENT:
		switch (root->statement->mode)
		{
		case BLOCK:
			if (root->statement->b->sl != NULL) { dfs(root->statement->b->sl->n); }
			break;
		case IF:
		{
			if (TYPECHECK)
			{
				if (typecheckIf(root->statement->i, root->statement->i->e->n->lineno))
					TYPEERR = 1;
				// typecheck statements
				dfs(root->statement->i->s1->n);
				dfs(root->statement->i->s2->n);
			}
			
			break;
		}
		case WHILE:
		{
			if (TYPECHECK)
			{
				if (typecheckWhile(root->statement->w, root->statement->w->e->n->lineno))
					TYPEERR = 1;
				// typecheck statement
				dfs(root->statement->w->s->n);
			}
			
			break;
		}
		case PRINT:
		{
			if (TYPECHECK)
			{
				if (typecheckPrint(root->statement->p, root->lineno))
					TYPEERR = 1;
			}
			
			break;
		}
		case ASSGN:
		{
			if (TYPECHECK)
			{
				if (typecheckAssign(root->statement->a, root->lineno))
					TYPEERR = 1;
			}
			
			break;
		}
		case ARRASSGN:
			if (TYPECHECK)
			{
				if (typecheckArrayAssign(root->statement->aa, root->lineno))
					TYPEERR = 1;
			}
			break;
		case RET:
			if (TYPECHECK)
			{
				if (typecheckReturn(root->statement->e, root->lineno))
					TYPEERR = 1;
			}
			break;
		}
		break;
	case INDEX:
		if (TYPECHECK) 
		{
			if (typecheckIndex(root->index, root->lineno))
				TYPEERR = 1;
		}
		break;
	case EXP:
		switch (root->exp->mode)
		{	
		case BINARYOP:
		{
			if (TYPECHECK) 
			{
				if (typecheckBinaryOp(root->exp, root->lineno))
					TYPEERR = 1;
			}
			break;
		}
		case UNARYOP:
		{
			if (TYPECHECK) 
			{
				if (typecheckUnaryOp(root->exp, root->lineno))
					TYPEERR = 1;
			}
			break;
		}
		case INTEGERLITERAL:
			if (TYPECHECK) { typecheckIntegerLiteral(root->exp, root->lineno); }
			break;
		case BOOLEAN:
			if (TYPECHECK) { typecheckBoolean(root->exp, root->lineno); }
			break;
		case ARRLOOKUP:
			if (TYPECHECK) 
			{
				if (typecheckArrayLookup(root->exp, root->lineno))
					TYPEERR = 1;
			}
			break;
		case ARRLEN:
			if (TYPECHECK)
			{
				if (typecheckArrayLen(root->exp, root->lineno))
					TYPEERR = 1;
			}
			break;
		case IDENTIFIERLEN:
			if (TYPECHECK) 
			{ 
				if (typecheckIdentifierLen(root->exp, root->lineno))
					TYPEERR = 1;
			}
			break;
		case OBJECT:
		{
			if (TYPECHECK)
			{
				if (typecheckObject(root->exp, root->lineno))
					TYPEERR = 1;
			}
			break;
		}
		case PAREN:
		{
			if (TYPECHECK) { typecheckParen(root->exp, root->lineno); }
			break;
		}
		case CALL:
		{
			if (TYPECHECK)
			{
				if (typecheckCall(root->exp, root->lineno))
					TYPEERR = 1;
			}
			break;
		}
		}
		break;
	case EXPLIST:
	{
		Exp * curr = root->explist->head;
		while (curr != NULL) 
		{
			dfs(curr->n);
			curr = curr->next;
		}
		break;
	}

	default:
		//printf("NEEDS IMPLEMENTATION -> %d\n", root->mode);
		break;
	}
}