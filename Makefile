build: parser

dbg: parser diagram

diagram: parser
	dot -Tpng y.dot > out.png

parser:		y.tab.c lex.yy.c
		gcc -g y.tab.c lex.yy.c -o parser

y.tab.c:	parser.y
		yacc -d -g --debug --verbose parser.y

lex.yy.c:	parser.l
		lex parser.l

clean:
	rm -f lex.yy.c y.tab.c
