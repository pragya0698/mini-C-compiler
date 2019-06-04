%{
	#include "header.h"
	#include <stdio.h>
	#include "y.tab.h"
	#include<string.h>
	extern void yyerror(const char *); 

	extern int sym_type(const char *);  
	#define sym_type(identifier) T_IDENTIFIER 

	static void comment(void);

	static int check_type(void);
	
	int line = 0;

%}

%option yylineno

D   		[0-9]
L   		[a-zA-Z_]
A   		[a-zA-Z_0-9]
WS  		[ \t\v\n\f]


%%
"/*"		{ comment(); }
"//"[^\n]*	{ /* Consume Comment */ }

	/* Data Types */
int			{ strcpy(yylval.string,yytext); return(T_INT); }
float		{ strcpy(yylval.string,yytext); return(T_FLOAT); }
char		{ strcpy(yylval.string,yytext); return(T_CHAR); }
void		{ strcpy(yylval.string,yytext); return(T_VOID); }
main		{ strcpy(yylval.string,yytext); return(T_MAIN); }

	/* User Defined Data Types */
struct		{ strcpy(yylval.string,yytext); return(T_STRUCT); }

	/* Headers */
"#"		{ return T_HASH; }
include		{ return T_INCLUDE; }
define		{ return T_DEFINE; }

	/* C Libraries */
"math.h"	{ return T_MATH; }
"stdio.h"	{ return T_STDIO; }
"stdlib.h"	{ return T_STDLIB; }
"string.h"	{ return T_STRING; }
"time.h"	{ return T_TIME; }

	/* Control Structures */
for		{ return(T_FOR); }
while   { return(T_WHILE);}
if      { return(T_IF);}
else    { return(T_ELSE);}

	/* User Defined Data Types, Identifiers */
{L}{A}*						{	 strcpy(yylval.string,yytext); return T_IDENTIFIER;}
{D}+							{ strcpy(yylval.string,yytext); return T_INTEGER_LITERAL;}
{D}+\.{D}+						{ strcpy(yylval.string,yytext); return T_FLOAT_LITERAL;}
\"{A}+(".h"|".c")\"				{return T_HEADER_LITERAL;}
L?\"(\\.|[^\\"])*\"	{ return(T_STRING_LITERAL); }

	/* Assignment Operators */
"+="		{return(T_ADD_ASSIGN); }
"-="		{return(T_SUB_ASSIGN); }


	/* Relational Operators */
"++"		{return(T_INC_OP); }
"--"		{return(T_DEC_OP); }
"<="		{ strcpy(yylval.string,yytext); return(T_LE_OP); }
">="		{ strcpy(yylval.string,yytext); return(T_GE_OP); }
"=="		{ strcpy(yylval.string,yytext); return(T_EQ_OP); }
"!="		{ strcpy(yylval.string,yytext); return(T_NE_OP); }

	/* Basic Syntax */
";"		{return(';'); }
"{"	{return('{'); }
"}"	{return('}'); }
","		{return(','); }
":"		{return(':'); }
"="		{return('='); }
"("		{return('('); }
")"		{return(')'); }
("["|"<:")	{return('['); }
("]"|":>")	{return(']'); }
"."		{return('.'); }
"&"		{return('&'); }
"!"		{return('!'); }
"~"		{return('~'); }
"-"		{ strcpy(yylval.string,yytext);return('-'); }
"+"		{ strcpy(yylval.string,yytext);return('+'); }
"*"		{ strcpy(yylval.string,yytext);return('*'); }
"/"		{ strcpy(yylval.string,yytext);return('/'); }
"%"		{ strcpy(yylval.string,yytext);return('%'); }
"<"		{ strcpy(yylval.string,yytext);return('<'); }
">"		{ strcpy(yylval.string,yytext);return('>'); }
"^"		{return('^'); }
"|"		{return('|'); }
"?"		{return('?'); }


{WS}+		{ /* whitespace separates tokens */}
	
.		{ printf("No Match, Invalid Expression %s\n", yytext); }
%%

int yywrap(void)
{
	return 1;
}


static void comment(void)
{
    int c;

    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
    yyerror("unterminated comment");
}
