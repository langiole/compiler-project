%{
	#include <stdio.h>
	
	#define id 10000
	#define INTEGER_LITERAL 10001
	#define STRING_LITERAL 10002
%}
%option yylineno

letter			[A-Za-z]
digit			[0-9]
underscore		_
double_quote 		\"
id			{letter}({letter}|{digit}|{underscore})*
INTEGER_LITERAL 	({digit})*{digit}
STRING_LITERAL		{double_quote}.*{double_quote}
op 			(&&)|(\|\|)|(<)|(>)|(<=)|(>=)|(==)|(!=)|(\+)|(-)|(\*)|(\/)

%%
{id}			{ printf("Line %d:\tid found\t\t\t%s\n", yylineno, yytext); }
{INTEGER_LITERAL}	{ printf("Line %d:\tINTEGER_LITERAL found\t\t%s\n", yylineno, yytext); }
{STRING_LITERAL} 	{ printf("Line %d:\tSTRING_LITERAL found\t\t%s\n", yylineno, yytext); }
{op} 			{ printf("Line %d:\top found\t\t\t%s\n", yylineno, yytext); }
\+\+ 			{ printf("Syntax errors in line %d\n", yylineno); }
\n 			{ }
.			;
%%

int yywrap(void) { return 1; }

int main(void) {
	yylex();
	return 0;
} 
