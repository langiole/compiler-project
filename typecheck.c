#include <stdio.h>
#include "y.tab.h"

extern int yylineno;

int typecheckBinaryExp(int op, int type1, int type2) {
	if (op == AND || op == OR)
	{
		if (type1 != BOOLEAN || type2 != BOOLEAN)
		{
			fprintf(stderr, "Type Violation in Line %d : operand(s) not of type boolean\n", yylineno);
			return 1;
		}
	}
	else if (op == EQ || op == NOTEQ)
	{
		if (!((type1 == BOOLEAN && type2 == BOOLEAN)
			|| (type1 == INT && type2 == INT)))
		{
			fprintf(stderr, "Type Violation in Line %d : both operands not one of boolean or int\n", yylineno);
			return 1;
		}
	}
	else if (op == LESSTHANEQ || op == GREATTHANEQ || op == LESSTHAN || op == GREATTHAN || op == PLUS || op == MINUS || op == TIMES || op == DIVIDE)
	{
		if (type1 != INT || type2 != INT)
		{
			fprintf(stderr, "Type Violation in Line %d : operand(s) not of type int\n", yylineno);
			return 1;
		}
	}
	return 0;
}

int typecheckUnaryExp(int op, int type) {
	if (op == PLUS || op == MINUS)
	{
		if (type != INT)
		{
			fprintf(stderr, "Type Violation in Line %d : operand not of type int\n", yylineno);	
			return 1;
		}
	}
	else if (op == NEGATE)
	{
		if (type != BOOLEAN)
		{
			fprintf(stderr, "Type Violation in Line %d : operand not of type boolean\n", yylineno);	
			return 1;
		}
	}
	return 0;
}