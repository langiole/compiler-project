#include "y.tab.h"
#include <stdio.h>
#include "typecheck.h"

void dfs(AST_Node * root) {
	switch (root->mode) 
	{
	case PROGRAM:
		//printf("\n(%p) Program:\n", root->program);
		//printf("\tMainClass (%p)\n", root->program->m);
		//printf("\tClassDeclList (%p)\n", root->program->cl);

		dfs(root->program->m->n);
		dfs(root->program->cl->n);
		break;
	case MAINCLASS:
		//printf("\n(%p) MainClass:\n", root->mainclass);
		//printf("\tIdentifier 1 (%p)\n", root->mainclass->i1);
		//printf("\tIdentifier 2 (%p)\n", root->mainclass->i2);
		//printf("\tStatement (%p)\n", root->mainclass->s);

		dfs(root->mainclass->i1->n);
		dfs(root->mainclass->i2->n);
		dfs(root->mainclass->s->n);
		break;
	case CLASSDECLLIST:
	{
		//printf("\n(%p) ClassDeclList:\n", root->classdecllist);
		//printf("\thead (%p)\n", root->classdecllist->head);
		//printf("\ttail (%p)\n", root->classdecllist->tail);

		ClassDecl * curr = root->classdecllist->head;
		while (curr != NULL) 
		{
			dfs(curr->n);
			curr = curr->next;
		}
		break;
	}
	case CLASSDECL:
		//printf("\n(%p) ClassDecl:\n", root->classdecl);
		switch (root->classdecl->mode) 
		{
		case CLASSDECLSIMPLE:
			//printf("\n(%p) ClassDeclSimple:\n", root->classdecl->cs);
			//printf("\tIdentifier (%p)\n", root->classdecl->cs->i);
			//printf("\tVarDeclList (%p)\n", root->classdecl->cs->vl);
			//printf("\tMethodDeclList (%p)\n", root->classdecl->cs->ml);

			dfs(root->classdecl->cs->i->n);
			dfs(root->classdecl->cs->vl->n);
			dfs(root->classdecl->cs->ml->n);
			break;
		case CLASSDECLEXTENDS:
			//printf("\n(%p) ClassDeclExtends:\n", root->classdecl->ce);
			//printf("\tIdentifier 1 (%p)\n", root->classdecl->ce->i1);
			//printf("\tIdentifier 2 (%p)\n", root->classdecl->ce->i2);
			//printf("\tVarDeclList (%p)\n", root->classdecl->ce->vl);
			//printf("\tMethodDeclList (%p)\n", root->classdecl->ce->ml);

			dfs(root->classdecl->ce->i1->n);
			dfs(root->classdecl->ce->i2->n);
			dfs(root->classdecl->ce->vl->n);
			dfs(root->classdecl->ce->ml->n);
			break;
		}
		break;
	case VARDECLLIST:
	{
		//printf("\n(%p) VarDeclList:\n", root->vardecllist);
		//printf("\thead (%p)\n", root->vardecllist->head);
		//printf("\ttail (%p)\n", root->vardecllist->tail);

		VarDecl * curr = root->vardecllist->head;
		while (curr != NULL) 
		{
			dfs(curr->n);
			curr = curr->next;
		}
		break;
	}
	case VARDECL:
		//printf("\n(%p) VarDecl:\n", root->vardecl);
		//printf("\tType (%p)\n", root->vardecl->t);
		//printf("\tIdentifier (%p)\n", root->vardecl->i);
		
		dfs(root->vardecl->t->n);
		dfs(root->vardecl->i->n);
		break;
	case METHODDECLLIST:
	{
		//printf("\n(%p) MethodDeclList:\n", root->methoddecllist);
		//printf("\thead (%p)\n", root->methoddecllist->head);
		//printf("\ttail (%p)\n", root->methoddecllist->tail);

		MethodDecl * curr = root->methoddecllist->head;
		while (curr != NULL) 
		{
			dfs(curr->n);
			curr = curr->next;
		}
		break;
	}
	case METHODDECL:
		//printf("\n(%p) MethodDecl:\n", root->methoddecl);
		//printf("\tType (%p)\n", root->methoddecl->t);
		//printf("\tIdentifier (%p)\n", root->methoddecl->i);
		//printf("\tFormalList (%p)\n", root->methoddecl->fl);
		//printf("\tVarDeclList (%p)\n", root->methoddecl->vl);
		if (root->methoddecl->sl != NULL)
		{
			//printf("\tStatementList (%p)\n", root->methoddecl->sl);
		}
		//printf("\tExp (%p)\n", root->methoddecl->e);
		
		dfs(root->methoddecl->t->n);
		dfs(root->methoddecl->i->n);
		dfs(root->methoddecl->fl->n);
		dfs(root->methoddecl->vl->n);
		if (root->methoddecl->sl != NULL)
		{
			dfs(root->methoddecl->sl->n);	
		}
		dfs(root->methoddecl->e->n);
		break;
	case FORMALLIST:
		//printf("\n(%p) FormalList:\n", root->formallist);
		//printf("\tType (%p)\n", root->formallist->t);
		//printf("\tIdentifier (%p)\n", root->formallist->i);
		//printf("\tFormalRestList (%p)\n", root->formallist->fr);

		dfs(root->formallist->t->n);
		dfs(root->formallist->i->n);
		dfs(root->formallist->fr->n);
		break;
	case FORMALRESTLIST:
	{
		//printf("\n(%p) FormalRestList:\n", root->formalrestlist);
		//printf("\thead (%p)\n", root->formalrestlist->head);
		//printf("\ttail (%p)\n", root->formalrestlist->tail);

		FormalRest * curr = root->formalrestlist->head;
		while (curr != NULL) 
		{
			dfs(curr->n);
			curr = curr->next;
		}
		break;
	}
	case FORMALREST:
		//printf("\n(%p) FormalRest:\n", root->formalrest);
		//printf("\tType (%p)\n", root->formalrest->t);
		//printf("\tIdentifier (%p)\n", root->formalrest->i);

		dfs(root->formalrest->t->n);
		dfs(root->formalrest->i->n);
		break;
	case TYPE:
		//printf("\n(%p) Type:\n", root->type);
		switch(root->type->mode)
		{
		case PRIMTYPE:
			//printf("\tPrimType (%p)\n", root->type->pt);
			dfs(root->type->pt->n);
			break;
		case ARRAYTYPE:
			//printf("\n(%p) ArrayType:\n", root->type->at);
			//printf("\tType (%p)\n", root->type->at->t);
			dfs(root->type->at->t->n);
			break;
		}
		break;
	case PRIMTYPE:
		//printf("\n(%p) PrimType:\n", root->primtype);
		switch (root->primtype->mode)
		{
		case INT:
			//printf("\n(%p) IntegerType:\n", root->primtype->it);
			break;
		case BOOLEAN:
			//printf("\n(%p) BooleanType:\n", root->primtype->bt);
			break;
		case IDENTIFIER:
			//printf("\tIdentifier (%p)\n", root->primtype->i);
			dfs(root->primtype->i->n);
			break;
		}
		break;
	case STATEMENTLIST:
	{
		//printf("\n(%p) StatementList:\n", root->statementlist);
		//printf("\thead (%p)\n", root->statementlist->head);
		//printf("\ttail (%p)\n", root->statementlist->tail);

		Statement * curr = root->statementlist->head;
		while (curr != NULL) 
		{
			dfs(curr->n);
			curr = curr->next;
		}
		break;
	}
	case STATEMENT:
		//printf("\n(%p) Statement:\n", root->statement);
		switch (root->statement->mode)
		{
		case BLOCK:
			//printf("\n(%p) Block:\n", root->statement->b);
			if (root->statement->b->sl != NULL) 
			{
				//printf("\tStatementList (%p)\n", root->statement->b->sl);
				dfs(root->statement->b->sl->n);
			}
			break;
		case IF:
			//printf("\n(%p) If:\n", root->statement->i);
			//printf("\tExp (%p)\n", root->statement->i->e);
			//printf("\tStatement 1 (%p)\n", root->statement->i->s1);
			//printf("\tStatement 2 (%p)\n", root->statement->i->s2);

			dfs(root->statement->i->e->n);
			dfs(root->statement->i->s1->n);
			dfs(root->statement->i->s2->n);
			break;
		case WHILE:
			//printf("\n(%p) While:\n", root->statement->w);
			//printf("\tExp (%p)\n", root->statement->w->e);
			//printf("\tStatement (%p)\n", root->statement->w->s);

			dfs(root->statement->w->e->n);
			dfs(root->statement->w->s->n);
			break;
		case PRINT:
			//printf("\n(%p) Print:\n", root->statement->p);
			switch (root->statement->p->mode)
			{
			case EXP:
				//printf("\tExp (%p)\n", root->statement->p->e);
				dfs(root->statement->p->e->n);
				break;
			case STRINGLITERAL:
				//printf("\tStringLiteral (%p)\n", root->statement->p->sl);
				dfs(root->statement->p->sl->n);
				break;
			}
			break;
		case ASSGN:
			//printf("\n(%p) Assign:\n", root->statement->a);
			//printf("\tIdentifier (%p)\n", root->statement->a->i);
			//printf("\tExp (%p)\n", root->statement->a->e);

			dfs(root->statement->a->i->n);
			dfs(root->statement->a->e->n);
			break;
		case ARRASSGN:
			//printf("\n(%p) ArrayAssign:\n", root->statement->aa);
			//printf("\tIdentifier (%p)\n", root->statement->aa->i);
			//printf("\tIndex (%p)\n", root->statement->aa->ix);
			//printf("\tExp (%p)\n", root->statement->aa->e);

			dfs(root->statement->aa->i->n);
			dfs(root->statement->aa->ix->n);
			dfs(root->statement->aa->e->n);
			break;
		case RET:
			//printf("\tExp (%p)\n", root->statement->e);
			dfs(root->statement->e->n);
			break;
		}
		break;
	case INDEX:
		//printf("\n(%p) Index:\n", root->index);
		switch (root->index->mode)
		{
		case EXP:
			//printf("\tExp (%p)\n", root->index->e);
			dfs(root->index->e->n);
			break;
		case MULTIINDEX:
			//printf("\n(%p) MultiIndex:\n", root->index->mi);
			//printf("\tIndex (%p)\n", root->index->mi->ix);
			//printf("\tExp (%p)\n", root->index->mi->e);

			dfs(root->index->mi->ix->n);
			dfs(root->index->mi->e->n);
			break;
		}
		break;
	case OBJECT:
		//printf("\n(%p) Object:\n", root->object);
		switch (root->object->mode)
		{
		case IDENTIFIER:
			//printf("\tIdentifier (%p)\n", root->object->i);
			dfs(root->object->i->n);
			break;
		case THIS:
			//printf("\n(%p) This:\n", root->object->t);
			break;
		case NEWOBJ:
			//printf("\n(%p) NewObject:\n", root->object->no);
			//printf("\tIdentifier (%p)\n", root->object->no->i);

			dfs(root->object->no->i->n);
			break;
		case NEWARR:
			//printf("\n(%p) NewArray:\n", root->object->na);
			//printf("\tPrimType (%p)\n", root->object->na->pt);
			//printf("\tIndex (%p)\n", root->object->na->ix);

			dfs(root->object->na->pt->n);
			dfs(root->object->na->ix->n);
			break;
		}
		break;
	case EXP:
		//printf("\n(%p) Exp:\n", root->exp);
		switch (root->exp->mode)
		{
		case BINARYOP:
			//printf("\n(%p) BinaryOp:\n", root->exp->bo);
			switch (root->exp->bo->op)
			{
			case AND:
				//printf("\nAND\n");
				break;
			case OR:
				//printf("\nOR\n");
				break;
			case EQ:
				//printf("\nEQ\n");
				break;
			case NOTEQ:
				//printf("\nNOTEQ\n");
				break;
			case LESSTHANEQ:
				//printf("\nLESSTHANEQ\n");
				break;
			case GREATTHANEQ:
				//printf("\nGTREATTHANEQ\n");
				break;
			case LESSTHAN:
				//printf("\nLESSTHAN\n");
				break;
			case GREATTHAN:
				//printf("\nGREATTHAN\n");
				break;
			case PLUS:
				//printf("\nPLUS\n");
				break;
			case MINUS:
				//printf("\nMINUS\n");
				break;
			case TIMES:
				//printf("\nTIMES\n");
				break;
			case DIVIDE:
				//printf("\nDIVIDE\n");
				break;
			}
			//printf("\tExp 1 (%p)\n", root->exp->bo->e1);
			//printf("\tExp 2 (%p)\n", root->exp->bo->e2);


			// explore subtrees
			dfs(root->exp->bo->e1->n);
			dfs(root->exp->bo->e2->n);

			// begin program interpretation
			if (!TYPEERR)
			{
				// program interpretation
			}
			break;
		case UNARYOP:
			//printf("\n(%p) UnaryOp:\n", root->exp->uo);
			switch (root->exp->uo->op)
			{
			case NEGATE:
				//printf("\nNEGATE\n");
				break;
			case PLUS:
				//printf("\nPLUS\n");
				break;
			case MINUS:
				//printf("\nMINUS\n");
				break;
			}
			//printf("\tExp (%p)\n", root->exp->uo->e);
			dfs(root->exp->uo->e->n);
			break;
		case INTEGERLITERAL:
			//printf("\tIntegerLiteral (%p)\n", root->exp->il);
			dfs(root->exp->il->n);
			break;
		case BOOLEAN:
			//printf("\n(%p) Boolean:\n", root->exp->b);
			if (root->exp->b->value)
			{
				//printf("\tTRUE\n");
			}
			else
			{
				//printf("\tFALSE\n");
			}
			break;
		case ARRLOOKUP:
			//printf("\n(%p) ArrayLookup:\n", root->exp->alook);
			//printf("\tIdentifier (%p)\n", root->exp->alook->i);
			//printf("\tIndex (%p)\n", root->exp->alook->ix);

			dfs(root->exp->alook->i->n);
			dfs(root->exp->alook->ix->n);
			break;
		case ARRLEN:
			//printf("\n(%p) ArrayLength:\n", root->exp->alen);
			//printf("\tIdentifier (%p)\n", root->exp->alen->i);
			//printf("\tIndex (%p)\n", root->exp->alen->ix);

			dfs(root->exp->alen->i->n);
			dfs(root->exp->alen->ix->n);
			break;
		case IDENTIFIERLEN:
			//printf("\n(%p) IdentifierLength:\n", root->exp->ilen);
			//printf("\tIdentifier (%p)\n", root->exp->ilen->i);

			dfs(root->exp->ilen->i->n);
			break;
		case OBJECT:
			//printf("\tObject (%p)\n", root->exp->o);
			dfs(root->exp->o->n);
			break;
		case PAREN:
			//printf("\n(%p) ParenExp:\n", root->exp->pe);
			//printf("\tExp (%p)\n", root->exp->pe->e);

			dfs(root->exp->pe->e->n);
			break;
		case CALL:
			//printf("\n(%p) Call:\n", root->exp->c);
			//printf("\tObject (%p)\n", root->exp->c->o);
			//printf("\tIdentifier (%p)\n", root->exp->c->i);
			//printf("\tExpList (%p)\n", root->exp->c->el);

			dfs(root->exp->c->o->n);
			dfs(root->exp->c->i->n);
			dfs(root->exp->c->el->n);
			break;
		}
		break;
	case EXPRESTLIST:
	{
		//printf("\n(%p) ExpRestList:\n", root->exprestlist);
		//printf("\thead (%p)\n", root->exprestlist->head);
		//printf("\ttail (%p)\n", root->exprestlist->tail);

		ExpRest * curr = root->exprestlist->head;
		while (curr != NULL) 
		{
			dfs(curr->n);
			curr = curr->next;
		}
		break;
	}
	case EXPREST:
		//printf("\n(%p) ExpRest:\n", root->exprest);
		//printf("\tExp (%p)\n", root->exprest->e);

		dfs(root->exprest->e->n);
		break;
	case EXPLIST:
		//printf("\n(%p) ExpList:\n", root->explist);
		//printf("\tExp (%p)\n", root->explist->e);
		//printf("\tExpRestList (%p)\n", root->explist->erl);

		if (root->explist->e->n != NULL && root->explist->erl->n != NULL)
		{
			dfs(root->explist->e->n);
			dfs(root->explist->erl->n);
		}
		break;
	case INTEGERLITERAL:
		//printf("\n(%p) InegerLiteral:\n", root->integerliteral);
		//printf("\tValue (%d)\n", root->integerliteral->value);
		break;
	default:
		//printf("NEEDS IMPLEMENTATION -> %d\n", root->mode);
		break;
	}
}