typechecker:	y.tab.c lex.yy.c
		gcc -g y.tab.c lex.yy.c ast.c dfs.c typecheck.c generator.c symtbl.c -o typechecker

y.tab.c:	parser.y
		yacc -d --verbose parser.y

lex.yy.c:	parser.l
		lex parser.l

clean:
	rm -f lex.yy.c y.tab.c y.output err.log lex.yy.o lex.yy.c y.tab.h