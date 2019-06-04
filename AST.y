%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include <stdarg.h>
	#include "graph.c"
	void yyerror(const char*);
	int yylex();
	
	/* prototypes */
	int ex (nodeType *p, int flag);
	/* function prototype to create a node for an operation */ 
	nodeType *opr(int oper, int nops, ...);
	/* function prototype to create a node for an identifier */
	nodeType *id(char *identifier);
	/* function prototype to create a node for a constat */
	nodeType *con(char *value);

	int if_assign = 1;

%}

%union
{
	int ival;
	nodeType *nPtr;
	char string[128];
}

%token T_HASH T_INCLUDE T_DEFINE T_STDIO T_STDLIB T_MATH T_STRING T_TIME

%token	T_IDENTIFIER T_INTEGER_LITERAL T_FLOAT_LITERAL T_STRING_LITERAL T_HEADER_LITERAL

%token	T_INC_OP T_DEC_OP T_LE_OP T_GE_OP T_EQ_OP T_NE_OP

%token	T_ADD_ASSIGN T_SUB_ASSIGN

%token	T_CHAR T_INT T_FLOAT T_VOID T_MAIN

%token	T_STRUCT

%token	T_FOR T_WHILE T_IF T_ELSE

%type <string> T_IDENTIFIER T_INTEGER_LITERAL T_FLOAT_LITERAL T_STRING_LITERAL 

%type <nPtr> primary_expression postfix_expression multiplicative_expression

%type <nPtr> unary_expression additive_expression relational_expression

%type <nPtr> equality_expression conditional_expression assignment_expression

%type <nPtr> statement compound_statement expression_statement selection_statement block_item

%type <nPtr> expression init_declarator init_declarator_list

%type <nPtr> iteration_statement block_item_list translation_unit

%type <nPtr> external_declaration declaration 


%start translation_unit

%%
headers
	: T_HASH T_INCLUDE T_HEADER_LITERAL 
	| T_HASH T_INCLUDE '<' libraries '>'
	;

libraries
	: T_STDIO
	| T_STDLIB
	| T_MATH
	| T_STRING
	| T_TIME
	;

primary_expression
	: T_IDENTIFIER		{$$ = id($1);}
	| T_INTEGER_LITERAL	{$$ = con($1);}
	| T_FLOAT_LITERAL		{$$ = con($1);}
	| T_STRING_LITERAL	{$$ = con($1);}
	| '(' expression ')'	{$$ = $2;}
	;

postfix_expression
	: primary_expression	{$$ = $1;}
	| postfix_expression '(' ')'
	| postfix_expression '.' T_IDENTIFIER {
											char *tmp = strcat($1->id.name,".");
											tmp = strcat(tmp, $3);
											printf(" %s\n", tmp); 			
											$$ = id(tmp);
										}
	| postfix_expression T_INC_OP			{
											$$ = opr('=', 2, $1, opr('+', 2, $1, con("1") ) );
										}
	| postfix_expression T_DEC_OP			{
											$$ = opr('=', 2, $1, opr('-', 2, $1, con("1") ) );										
										}
	| T_INC_OP primary_expression			{
											$$ = opr('=', 2, $2, opr('+', 2, $2, con("1") ) );										
										}
	| T_DEC_OP primary_expression			{
											$$ = opr('=', 2, $2, opr('-', 2, $2, con("1") ) );										
										}

	;

unary_expression
	: postfix_expression 			{$$ = $1;}
	| '+' unary_expression			{$$ = opr('+', 1, $2);}
	| '-' unary_expression			{$$ = opr('+', 1, $2);}	
	;

multiplicative_expression
	: unary_expression						{$$ = $1;}
	| multiplicative_expression '*' unary_expression		{$$ = opr('*', 2, $1, $3);}
	| multiplicative_expression '/' unary_expression		{$$ = opr('/', 2, $1, $3);}		
	| multiplicative_expression '%' unary_expression		{$$ = opr('%', 2, $1, $3);}
	;

additive_expression
	: multiplicative_expression					{$$ = $1;}
	| additive_expression '+' multiplicative_expression		{$$ = opr('+', 2, $1, $3);}
	| additive_expression '-' multiplicative_expression		{$$ = opr('-', 2, $1, $3);}
	;

relational_expression
	: additive_expression
	| relational_expression '<' additive_expression			{$$ = opr('<', 2, $1, $3);}
	| relational_expression '>' additive_expression			{$$ = opr('>', 2, $1, $3);}
	| relational_expression T_LE_OP additive_expression		{$$ = opr(T_LE_OP, 2, $1, $3);}
	| relational_expression T_GE_OP additive_expression		{$$ = opr(T_GE_OP, 2, $1, $3);}
	;

equality_expression
	: relational_expression						{$$ = $1;}
	| equality_expression T_EQ_OP relational_expression 		{$$ = opr(T_EQ_OP, 2, $1, $3);}
	| equality_expression T_NE_OP relational_expression		{$$ = opr(T_NE_OP, 2, $1, $3);}
	;

conditional_expression
	: equality_expression						{$$ = $1;}
	| equality_expression '?' expression ':' conditional_expression	{$$ = opr('?', 2, $1, opr(':', 2, $3, $5) );}
	;

assignment_expression
	: conditional_expression					{$$ = $1;}
	| unary_expression '=' assignment_expression {$$ = opr('=', 2, $1, $3);}
	| unary_expression T_ADD_ASSIGN assignment_expression {$$ = opr('=', 2, $1, opr('+', 2, $1, $3) );}
	| unary_expression T_SUB_ASSIGN assignment_expression {$$ = opr('=', 2, $1, opr('-', 2, $1, $3) );}
	;

expression
	: assignment_expression						{$$ = $1;}
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression					{}
	;

declaration
	: type_specifier ';'								//{$$ = opr(';', 1, $1);}
	| type_specifier init_declarator_list ';'			{$$ = opr(';', 1, $2);}
	;

init_declarator_list
	: init_declarator									{$$ = $1;}
	| init_declarator_list ',' init_declarator			{$$ = opr(',', 2, $1, $3);}
	;

init_declarator
	: T_IDENTIFIER '=' assignment_expression 				{$$ = opr('=', 2, id($1), $3);}
	| T_IDENTIFIER										{$$ = id($1);}
	;

type_specifier
	: T_VOID
	| T_CHAR
	| T_INT
	| T_FLOAT
	| struct_specifier				{if_assign = 0;}
	;

struct_specifier
	: T_STRUCT '{' struct_declaration_list '}'
	| T_STRUCT T_IDENTIFIER '{' struct_declaration_list '}'
	| T_STRUCT T_IDENTIFIER
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list ';'	/* for anonymous struct/union */
	| specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: ':' constant_expression
	| T_IDENTIFIER ':' constant_expression
	| T_IDENTIFIER
	;

statement
	: compound_statement	{$$ = $1;}
	| expression_statement	{$$ = $1;}
	| iteration_statement	{$$ = $1;}
	| selection_statement   {$$ = $1;}
	;

compound_statement
	: '{' '}'
	| '{' block_item_list '}'	{$$ = $2;}
	;

block_item_list
	: block_item	{$$ = $1;}
	| block_item_list block_item {$$ = opr(';', 2, $1, $2);}
	;

block_item
	: declaration	{$$ = $1;}
	| statement		{$$ = $1;}
	;

expression_statement
	: ';'			
	| expression ';' {$$ = $1;}
	;

selection_statement
	: T_IF '(' expression ')' statement {$$ = opr(T_IF, 2, $3, $5);}
	| T_IF '(' expression ')' statement T_ELSE statement {$$ = opr(T_IF,3,$3, $5, $7);}
	;

iteration_statement
	: T_WHILE '(' expression ')' statement {$$ = opr(T_WHILE, 2, $3,$5);}
	| T_FOR '(' expression_statement expression_statement expression ')' statement {$$ = opr(T_FOR, 4, $3, $4, $5, $7);}
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration 	;

external_declaration
	: type_specifier T_MAIN '(' ')' compound_statement	{ex($5, 0); /*freeNode($2);*/}
	| declaration							{
												if(if_assign)
												{											
													ex($1, 2); /*freeNode($2);*/
												}
											}	
	| headers 	
	;

%%

void yyerror(const char *str)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", str);
}



extern int yylex();
extern int yyparse();
extern FILE *yyin;


int main()
{

	FILE *in = fopen("test.c", "r");
	if(!in)
	{
		printf("Better Stop Cuz No Input!");
		return -1;
	}
	yyin = in;	
	do{
	yyparse();
	}while (!feof(yyin));
	printf("Done parsing\n");

}

nodeType *con(char *value)
{
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeCon;
	strcpy(p->con.value, value);
	return p;
}
nodeType *id(char *identifier) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeId;
	strcpy(p->id.name,identifier);
//	printf("The copied identifier %s\n", p->id.name);
	return p;
}

nodeType *opr(int oper, int nops, ...)
{
	va_list ap;
	nodeType *p;
	int i;
	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) +(nops-1) * sizeof(nodeType *))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
		p->opr.op[i] = va_arg(ap, nodeType*);
	va_end(ap);
	return p;
}
