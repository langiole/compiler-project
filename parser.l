%{
	#include <stdio.h>
	#include "y.tab.h"	
	#define PRINTDEBUG(x, y) fprintf(stderr, "\nDBG: %s, lineno: %d\n", x,y);
%}
%option yylineno

letter			[A-Za-z]
digit			[0-9]
NoStar 			[^*]
NoStarDash 		[^*/]
NoQuoteDashNl 		[^\"\\\n]
id			{letter}({letter}|{digit}|_)*
INTEGER_LITERAL 	({digit})*{digit}
STRING_LITERAL		\"(\\.|{NoQuoteDashNl})*\"
op 			(&&)|(\|\|)|(<=)|(>=)|(==)|(!=)
single_char 		[+\-!{}[\]();,=.<>*/]
sl_comment 		(\/\/.*)
ml_comment 		(\/\*)({NoStar}|\*+{NoStarDash})*\*+\/
SYNTAX_ERR 		(\+\+)|(--)

%%
"for" 			{ return FOR; }
"class" 		{ return CLASS; }
"public" 		{ return PUBLIC; }
"static" 		{ return STATIC; }
"void" 			{ return VOID; }
"main" 			{ return MAIN; }
"String" 		{ return STRING; }
"int" 			{ return INT; }
"boolean" 		{ return BOOLEAN; }
"extends" 		{ return EXTENDS; }
"return" 		{ return RETURN; }
"if" 			{ return IF; }
"else" 			{ return ELSE; }
"while" 		{ return WHILE; }
"System.out.println" 	{ return PRINT; }
"length" 		{ return LENGTH; }
"true" 			{ return TRUE; }
"false" 		{ return FALSE; }
"this" 			{ return THIS; }
"new" 			{ return NEW; }
{id}			{ return id; }
{INTEGER_LITERAL}	{ return INTEGER_LITERAL; }
{STRING_LITERAL} 	{ return STRING_LITERAL; } 
{op} 			{ return op; }
{single_char} 		{ return *yytext; }
{sl_comment} 		{ }
{ml_comment} 		{ }
{SYNTAX_ERR} 	 	{ printf("Syntax errors in %d\n", yylineno); }
[ \n\t\r] 		{ }
.			{ printf("Syntax errors in %d\n", yylineno); }
%%

int yywrap(void) { return 1; }
