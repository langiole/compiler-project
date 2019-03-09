#include "y.tab.h"

void interpretBinaryExp(int op, Exp * e, Exp * e1, Exp * e2) {
	switch (op)
	{
	case AND:
	{
		e->type = BOOLEAN;
		if (e1->value == 1 && e2->value == 1)
			e->value = 1;
		else
			e->value = 0;
		break;
	}
	case OR:
	{
		e->type = BOOLEAN;
		if (e1->value == 1 || e2->value == 1)
			e->value = 1;
		else
			e->value = 0;
		break;
	}
	case EQ:
	{
		e->type = BOOLEAN;
		if (e1->value == e2->value)
			e->value = 1;
		else
			e->value = 0;
		break;
	}
	case NOTEQ:
	{
		e->type = BOOLEAN;
		if (e1->value != e2->value)
			e->value = 1;
		else
			e->value = 0;
		break;
	}
	case LESSTHANEQ:
	{
		e->type = BOOLEAN;
		if (e1->value <= e2->value)
			e->value = 1;
		else
			e->value = 0;
		break;	
	}
	case GREATTHANEQ:
	{
		e->type = BOOLEAN;
		if (e1->value >= e2->value)
			e->value = 1;
		else
			e->value = 0;
		break;	
	}
	case LESSTHAN:
	{
		e->type = BOOLEAN;
		if (e1->value < e2->value)
			e->value = 1;
		else
			e->value = 0;
		break;	
	}
	case GREATTHAN:
	{
		e->type = BOOLEAN;
		if (e1->value > e2->value)
			e->value = 1;
		else
			e->value = 0;
		break;	
	}
	case PLUS:
	{
		e->type = INT;
		e->value = e1->value + e2->value;
		break;
	}
	case MINUS:
	{
		e->type = INT;
		e->value = e1->value - e2->value;
		break;
	}
	case TIMES:
	{
		e->type = INT;
		e->value = e1->value * e2->value;
		break;
	}
	case DIVIDE:
	{
		e->type = INT;
		e->value = e1->value / e2->value;
		break;
	}
	}
}

void interpretUnaryExp(int op, Exp * e, Exp * exp) {
	switch (op)
	{
	case NEGATE:
		e->type = BOOLEAN;
		e->value = !(exp->value);
		break;
	case MINUS:
		e->type = INT;
		e->value = -(exp->value);
		break;
	case PLUS:
		e->type = INT;
		e->value = +(exp->value);
		break;
	}
}






