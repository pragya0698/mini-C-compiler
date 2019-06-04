yacc -d cd2Inter.y
lex cd2new.l
gcc y.tab.c lex.yy.c -ll -ly
./a.out
