%{
	#include <stdio.h>
%}
%option yylineno

letter		[A-Za-z]
digit		[0-9]
underscore	_
id		{letter}({letter}|{digit}|{underscore})*

%%
{id}		{ printf("Line %d:\tid found\n", yylineno); }
{digit}		{ printf("Line %d:\tdigit found\n", yylineno); }
.		;
%%

int yywrap(void) { return 1; }

int main(void) {
	yylex();
	return 0;
} 
