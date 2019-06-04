D			[0-9]
L			[a-zA-Z_]
lib         "<stdio.h>"|"<stdlib.h>"|"<str.h>"|"<math.h>"|"<time.h>"|"<ctype.h>"

%{
	#include<stdio.h>
	#include "y.tab.h"
	void multicomment();
	void line_num();
%}
%%


\/\/.* ;			//ignoring single line comment
\/\*(.*\n)*.*\*\/ ;		//ignoring multiline comment
"#include"{lib}  { line_num(); return(T_INCLUDE); } 

"main()"			{ line_num();strcpy(yylval.str,yytext); return(T_MAIN); } 
"if"   			 { line_num(); return(T_IF); } 
"for"  		 { line_num();return(T_FOR);}
"char"    		 { line_num(); yylval.str=strdup(yytext); return(T_CHAR);}
"int" 	         { line_num();yylval.str=strdup(yytext);return(T_INT);}
"float"   		 { line_num();yylval.str=strdup(yytext); return(T_FLOAT);}
"double"   		 { line_num();yylval.str=strdup(yytext); return(T_DOUBLE);}
"else"   		 { line_num(); yylval.str=strdup(yytext);return(T_ELSE);}
"void"   		 {line_num();yylval.str=strdup(yytext); return(T_VOID);}
"break"   	 	{line_num(); return(T_BREAK);}
"continue"                   { line_num(); return(T_CONTINUE);}
"return"   	 	{line_num(); return(T_RETURN);}
"while"              {line_num();return(T_WHILE);}
{L}({L}|{D})*		{ line_num(); yylval.str=strdup(yytext);return(T_IDENTIFIER); }

{D}*			{line_num();yylval.str=strdup(yytext); return(T_CONSTANT);}

L?\"(\\.|[^\\'])*\"	{ line_num();yylval.str=strdup(yytext); return(T_STRINGLITERAL); }

"..."                   {line_num(); return(T_ELLIPSIS);}
">>="			{ line_num(); return(T_SHORT_SHIFT); }
"<<="			{line_num();  return(T_SHORT_LEFT); }
"+="			{line_num(); return(T_SHORT_ADD); }
"-="			{line_num();  return(T_SHORT_SUB); }
"*="			{line_num(); return(T_SHORT_MUL); }
"/="			{line_num();  return(T_SHORT_DIV); }
"%="			{line_num(); return(T_SHORT_MOD); }
"&="			{line_num();  return(T_SHORT_AND); }
"^="			{line_num(); return(T_SHORT_XOR); }
"|="			{line_num();  return(T_SHORT_OR); }
">>"			{line_num(); return(T_RIGHT_SHIFT); }
"<<"			{line_num(); return(T_LEFT_SHIFT); }
"++"			{line_num(); return(T_INC); }
"--"			{line_num(); return(T_DEC); }
"&&"			{line_num(); return(T_AND); }
"||"			{line_num(); return(T_OR); }
"<="			{line_num(); yylval.str=strdup(yytext); return(T_LE); }
">="			{line_num(); yylval.str= strdup(yytext);return(T_GE); }
"=="			{line_num(); yylval.str=strdup(yytext); return(T_EQ); }
"!="			{line_num(); yylval.str=strdup(yytext);return(T_NE); }
";"		        {line_num(); return(';'); }
"{"	            {line_num();  return('{'); }
"}"				{line_num(); return('}'); }
","			{line_num(); return(','); }
":"			{line_num(); return(':'); }
"="		{line_num(); return('='); }
"("		{line_num(); return('('); }
")"			{line_num();  return(')'); }
"["			{line_num(); return('['); }
"]"			{line_num(); return(']'); }
"."			{line_num(); return('.'); }
"&"			{line_num(); return('&'); }
"!"			{line_num(); return('!'); }
"~"			{ line_num(); return('~'); }
"-"			{line_num();  yylval.str=strdup(yytext); return('-'); }
"+"			{ line_num(); yylval.str=strdup(yytext); return('+'); }
"*"			{ line_num(); yylval.str=strdup(yytext);return('*'); }
"/"			{ line_num(); yylval.str=strdup(yytext); return('/'); }
"%"			{ line_num();yylval.str=strdup(yytext); return('%'); }
"<"			{line_num(); yylval.str=strdup(yytext); return('<'); }
">"			{line_num(); yylval.str=strdup(yytext); return('>'); }
"^"			{ line_num(); return('^'); }
"|"			{line_num();  return('|'); }
"?"			{line_num();   return('?'); }
[ \t\v\n\f]	{line_num(); }

%%

int column = 1;
void line_num()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++){
		
		if (yytext[i] == '\n')
			column =column+1;
		else
			continue;
	}
	//printf("line_num:%d\n",column);
	ECHO;
}


void multicomment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}
