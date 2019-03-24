#include "y.tab.h"
#include <stdio.h>
#include "typecheck.h"
#include "interpreter.h"
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
		else { interpretMethodDecl(root->methoddecl); }
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
		else { dfs(curr->n); }
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
			}
			else { interpretIf(root->statement->i); }
			break;
		}
		case WHILE:
		{
			if (TYPECHECK)
			{
				if (typecheckWhile(root->statement->w, root->statement->w->e->n->lineno))
					TYPEERR = 1;
			}
			else 
			{ 
				interpretWhile(root->statement->w); 

				// interpret next statement
				if (root->statement->next != NULL)
					dfs(root->statement->next->n);
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
			else
			{ 
				interpretPrint(root->statement->p);

				// interpret next statement
				if (root->statement->next != NULL)
					dfs(root->statement->next->n);
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
			else 
			{ 
				interpretAssign(root->statement->a); 

				// interpret next statement
				if (root->statement->next != NULL)
					dfs(root->statement->next->n);
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
			else { interpretReturn(root->statement->e); }
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
			else { interpretBinaryOp(root->exp); }
			break;
		}
		case UNARYOP:
		{
			if (TYPECHECK) 
			{
				if (typecheckUnaryOp(root->exp, root->lineno))
					TYPEERR = 1;
			}
			else { interpretUnaryOp(root->exp); }
			break;
		}
		case INTEGERLITERAL:
			if (TYPECHECK) { typecheckIntegerLiteral(root->exp, root->lineno); }
			else { interpretIntegerLiteral(root->exp); }
			break;
		case BOOLEAN:
			if (TYPECHECK) { typecheckBoolean(root->exp, root->lineno); }
			else { interpretBoolean(root->exp); }
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
			else { interpretObject(root->exp); }
			break;
		}
		case PAREN:
		{
			if (TYPECHECK) { typecheckParen(root->exp, root->lineno); }
			else { interpretParen(root->exp); }
			break;
		}
		case CALL:
		{
			if (TYPECHECK)
			{
				if (typecheckCall(root->exp, root->lineno))
					TYPEERR = 1;
			}
			else { interpretCall(root->exp); }
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