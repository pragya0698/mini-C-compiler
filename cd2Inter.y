%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symbol.c"

int yylex();
int yyerror();
int ob=0, cb=0; //opening bracket and closing bracket
int scope=0, scope_count = 0, line_no, op,op4,op1, for_loop_exp2 = 0, l, res = 0, valid=1;
char res2[10];

int recurse(char *text, int);
int search(char *text,int );
char keywords[8][7]={"char","int","float","void","main","for","if","else"};

void sym_init(struct symbol **second);
void change_line(char *id,int line_no,int scope);
void add_value(char *value, char *id_name,int scope);
void AddQuadruple(char op[5],char arg1[10],char arg2[10],char result[10],char res[10]);
int toInt(char *a);	
int check_type(char*);
void optimisation();
void checker(char *val1,char *val2);
void create_label(char op[5],char arg1[10],char arg2[10],char result[10]);
struct symbol *first;
char m[20], k[10], *id, *s, *id_val,lab[20];

struct quad
	{
		char op[5];
		char arg1[10];
		char arg2[10];
		char result[10];
	}QUAD[30];

struct stack 
	{
		int items[100];
		int top;
	}stk;


	int Index=0;
	int tIndex=0; 
	int lIndex=0;
	int StNo;
	int Ind; 
	int tInd;




%}

%union
{
	int value;
	char *text;
	char *str;
	
}
%token T_IDENTIFIER T_CONSTANT T_STRINGLITERAL T_INCLUDE T_MAIN 
%token T_INC T_DEC T_LEFT_SHIFT T_RIGHT_SHIFT T_LE T_GE T_EQ T_NE
%token T_AND T_OR T_SHORT_MUL T_SHORT_DIV T_SHORT_MOD T_SHORT_ADD

%token T_SHORT_SUB T_SHORT_LEFT T_SHORT_SHIFT T_SHORT_AND
%token T_SHORT_XOR T_SHORT_OR TYPE_NAME T_ELLIPSIS T_NEWLINE

%token T_CHAR T_INT T_FLOAT T_DOUBLE T_VOID
%token T_IF T_ELSE T_FOR T_BREAK T_RETURN T_CONTINUE T_WHILE
 
%type <str> ADDITIVEEXPRESSION CONDITIONALEXPRESSION  LOGICALOREXPRESSION EQUALITYEXPRESSION ANDEXPRESSION  EXCLUSIVEOREXPRESSION INCLUSIVEOREXPRESSION LOGICALANDEXPRESSION RELATIONALEXPRESSION PRIMARYEXPRESSION T_SHORT_XOR T_SHORT_OR TYPE_NAME T_ELLIPSIS T_NEWLINE T_SHORT_SUB T_SHORT_LEFT T_SHORT_SHIFT T_SHORT_AND T_LE T_GE T_EQ T_NE T_LEFT_SHIFT T_AND T_OR T_SHORT_MUL T_SHORT_DIV T_SHORT_MOD T_SHORT_ADD SHIFTEXPRESSION T_RIGHT_SHIFT T_IDENTIFIER MULTIPLICATIVEEXPRESSION CASTEXPRESSION POSTFIXEXPRESSION EXPRESSIONSTATEMENT EXPRESSION INITDECLARATOR DECLARATOR INITIALIZER ASSIGNMENTEXPRESSION ASSIGNMENTOPERATOR INITIALIZERLIST UNARYEXPRESSION '+' '='


%start PROGRAM



%%



PROGRAM : PREPROCESS S {/*printf("\n1\n");*/}
		| PROGRAM S {//printf("2\n");
		}
		;

PREPROCESS : T_INCLUDE {
					//printf("3\n");
					}
		   ;

S: DECLARATION {
					//printf("4\n");
					}
	| fundef {
			//printf("5\n");
			}
	;
returntype : T_VOID
		|
		T_INT
	;
fundef : returntype T_MAIN COMPOUNDSTATEMENT {/*printf("6\n");*/}
	   ;

PRIMARYEXPRESSION : T_IDENTIFIER {//printf("PRIMARY EXPRESSION\n");
								extern int column;
								line_no = column;
								s=yylval.text;
								//printf("S:%s\n",s);
								if(ob>0 && cb ==0)
									scope_count=ob;
								else if(ob-cb==1)
									scope_count=scope;

								else
									scope_count=ob;
								
								l=recurse(s,scope_count);
								//printf("l:%d\n",l);
								char type[10];
								if(strcmp(s,"printf")==0)
								{
									strcpy(k,"printf");
									
									//printf("strcmp:%s\n",k);
									strcpy(type,"printf");
								}
								else
									strcpy(type,k);
								//printf("S: %s\n",type);
								if(l==-1 && !strcmp(s,"printf")){
									//printf("CREATING PRINTF\n");
									create_node(&first,"ID",type,s,10000,scope_count,line_no,"0",line_no); 
									}
								else if(l==-1)
								{
									printf("ERROR!!! at line %d unDECLARed IDENTIFIER %s\n",line_no,yylval.text);
									exit(1);
								}
								change_line(yylval.text,line_no,l);
								
							}
					| T_CONSTANT {/*add_value(yylval.text,s,scope_count);*/ }
					| T_STRINGLITERAL {/*printf("9\n");*/ add_value(yylval.text,s,scope_count);}
					| '(' EXPRESSION ')'  {/*printf("10\n");*/}
					;

POSTFIXEXPRESSION : PRIMARYEXPRESSION {}
				  | POSTFIXEXPRESSION '(' ')' 	{printf("12\n");}
				  | POSTFIXEXPRESSION '(' ARGUMENTEXPRESSIONLIST ')' 	{printf("13\n");}
				  | POSTFIXEXPRESSION T_INC	{
				  							
				  							char res[40];
				  							strcpy(res,$1);
				  							l=recurse($1,scope_count);
				  							int op1=toInt(id_val);
				  							int op2=op1+1;
				  							sprintf($$,"%d",op2);
				  							if (l!=-1)
					  							add_value($$,res,l);
				  						}
				  | POSTFIXEXPRESSION T_DEC	{
				  							
				  							char res[40];
				  							strcpy(res,$1);
				  							l=recurse($1,scope_count);
				  							int op1=toInt(id_val);
				  							int op2=op1-1;
				  							sprintf($$,"%d",op2);
				  							if(l!=-1)
				  								add_value($$,res,l);
				  						}
				  ;

ARGUMENTEXPRESSIONLIST : ASSIGNMENTEXPRESSION 	{/*printf("16\n");*/}
					   | ARGUMENTEXPRESSIONLIST ',' ASSIGNMENTEXPRESSION	{/*printf("17\n");*/}
					   ;

UNARYEXPRESSION : POSTFIXEXPRESSION {/*printf("18\n");*/}
				| T_INC UNARYEXPRESSION {/*printf("19\n");*/}
				| T_DEC UNARYEXPRESSION	{/*printf("20\n");*/}
				| UNARYOPERATOR CASTEXPRESSION	{/*printf("21\n");*/}
				;

UNARYOPERATOR : '&' {/*printf("22\n");*/}
			  | '*' {/*printf("23\n");*/}
			  | '+' {/*printf("24\n");*/}
			  | '-' {/*printf("25\n");*/}
			  | '~' {/*printf("26\n");*/}
			  | '!' {/*printf("27\n");*/}
			  ;

CASTEXPRESSION : UNARYEXPRESSION {/*printf("28\n");*/}
				| '(' TYPENAME ')' CASTEXPRESSION	{/*printf("29\n");*/}
				;

MULTIPLICATIVEEXPRESSION : CASTEXPRESSION  {/*printf("30\n");*/}
						  |MULTIPLICATIVEEXPRESSION '*' CASTEXPRESSION 	{ 
					 													checker($1,$3);
																        	op4=op*op1;
																                sprintf(res2,"%d",op4); 
																		AddQuadruple("*",$1,$3,$$,res2);														
																	    
						  /*printf("31\n");*/}
						  | MULTIPLICATIVEEXPRESSION '/' CASTEXPRESSION { 		checker($1,$3);								 																			if(op!=0)
																        	op4=op1/op;
																        	else{
																        	printf("divide by zero\n");
																        	exit(1);
																        	}
																		sprintf(res2,"%d",op4); 															        			AddQuadruple("/",$1,$3,$$,res2);
																 } 
																	    
						  | MULTIPLICATIVEEXPRESSION '%' CASTEXPRESSION{ 	
					 													checker($1,$3);
																       	 	op4=op%op1;
																		sprintf(res2,"%d",op4);		
																										          																			AddQuadruple("%",$1,$3,$$,res2); 
																	   
																  } 
ADDITIVEEXPRESSION :  MULTIPLICATIVEEXPRESSION 		{}	
					 |ADDITIVEEXPRESSION '+' MULTIPLICATIVEEXPRESSION {		checker($1,$3);
																	   	op4=op+op1;
																	   	sprintf(res2,"%d",op4); 															        		        AddQuadruple("+",$1,$3,$$,res2);
																 } 
																
					| ADDITIVEEXPRESSION '-' MULTIPLICATIVEEXPRESSION {		 checker($1,$3);
																		 op4=op1-op;
																  		 sprintf(res2,"%d",op4);
									     								         AddQuadruple("-",$1,$3,$$,res2);
																} 	 
					;

SHIFTEXPRESSION : ADDITIVEEXPRESSION 
				| SHIFTEXPRESSION T_LEFT_SHIFT ADDITIVEEXPRESSION	{/*AddQuadruple($2,$1,$3,$$);*/} 
				| SHIFTEXPRESSION T_RIGHT_SHIFT ADDITIVEEXPRESSION	{/*AddQuadruple($2,$1,$3,$$);*/}
				;

RELATIONALEXPRESSION : SHIFTEXPRESSION 
					 | RELATIONALEXPRESSION '<' SHIFTEXPRESSION 	{ 		checker($1,$3);
																        if(op1<op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																        AddQuadruple("<",$1,$3,$$,res2);}

					 | RELATIONALEXPRESSION '>' SHIFTEXPRESSION 	{		checker($1,$3);
																        if(op1>op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																        AddQuadruple(">",$1,$3,$$,res2);
					 													
					 												}
					/* | RELATIONALEXPRESSION T_LE SHIFTEXPRESSION 	{AddQuadruple($2,$1,$3,$$);}
					 | RELATIONALEXPRESSION T_GE SHIFTEXPRESSION	{AddQuadruple($2,$1,$3,$$);}*/
					 ;
EQUALITYEXPRESSION : RELATIONALEXPRESSION 
					 | EQUALITYEXPRESSION T_EQ RELATIONALEXPRESSION {	checker($1,$3);
					 												  //op=toInt($3);
					 												 // printf("OP1 %d op %d \n",op1,op); 
																        if(op1==op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																      
					 												AddQuadruple($2,$1,$3,$$,res2);}
					 												
					 | EQUALITYEXPRESSION T_NE RELATIONALEXPRESSION{	checker($1,$3);
					 												printf("OP1 %d op %d \n",op1,op); 
					 												//op=toInt($3);
																        if(op1!=op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																        printf("RESULT %s\n",res2);
					 												AddQuadruple($2,$1,$3,$$,res2);}
					 ;


ANDEXPRESSION : EQUALITYEXPRESSION 
				| ANDEXPRESSION '&' EQUALITYEXPRESSION	{/*AddQuadruple("&",$1,$3,$$);*/}
				;
EXCLUSIVEOREXPRESSION : ANDEXPRESSION 
					   | EXCLUSIVEOREXPRESSION '^' ANDEXPRESSION	{/*AddQuadruple("^",$1,$3,$$);*/}
					   ;

INCLUSIVEOREXPRESSION :EXCLUSIVEOREXPRESSION 
					  | INCLUSIVEOREXPRESSION '|' EXCLUSIVEOREXPRESSION	{/*AddQuadruple("|",$1,$3,$$);*/}
					  ;

LOGICALANDEXPRESSION : INCLUSIVEOREXPRESSION 
					 | LOGICALANDEXPRESSION T_AND INCLUSIVEOREXPRESSION	{/*AddQuadruple($2,$1,$3,$$);*/}
					 ;

LOGICALOREXPRESSION : LOGICALANDEXPRESSION 
					| LOGICALOREXPRESSION T_OR LOGICALANDEXPRESSION	{/*AddQuadruple($2,$1,$3,$$);*/}
					;

CONDITIONALEXPRESSION : LOGICALOREXPRESSION 
						| LOGICALOREXPRESSION '?' EXPRESSION ':' CONDITIONALEXPRESSION
						;

ASSIGNMENTEXPRESSION : CONDITIONALEXPRESSION {}
					 | UNARYEXPRESSION ASSIGNMENTOPERATOR ASSIGNMENTEXPRESSION {
					 	strcpy(QUAD[Index].op,"=");
						strcpy(QUAD[Index].arg1,$3);
						strcpy(QUAD[Index].arg2,"");
						strcpy(QUAD[Index].result,$1);
						strcpy($$,QUAD[Index++].result);
					 	//printf("ASSIGNEMNT EXPRESSION $3 :%s %s \n",$3,$$);
					 	//int checl if its temp variable or value to be assigned.
					 	int check;
					 	check=check_type($3);
					 	if(check==0)
					 		strcpy($3,res2);
					 	//printf("ASSIGNEMNT EXPRESSION22 $3 :%s %s\n",$3,$$);
					 	l=recurse($1, scope_count);
					 	if(l!=-1)
						 	add_value($3,$1,l);
					 }
					 ;
ASSIGNMENTOPERATOR : '=' {/*printf("146\n");*/} | T_SHORT_MUL | T_SHORT_DIV | T_SHORT_MOD | T_SHORT_ADD | T_SHORT_SUB | T_SHORT_LEFT | T_SHORT_SHIFT | T_SHORT_AND | T_SHORT_XOR | T_SHORT_OR ;

EXPRESSION : ASSIGNMENTEXPRESSION { /*printf("147\n");*/}
			| EXPRESSION ',' ASSIGNMENTEXPRESSION 
			;
DECLARATION : DECLARATIONSPECIFIERS ';'
			| DECLARATIONSPECIFIERS INITDECLARATORLIST ';'
			;

DECLARATIONSPECIFIERS : TYPESPECIFIER 
					  | TYPESPECIFIER DECLARATIONSPECIFIERS
					  ;
INITDECLARATORLIST :INITDECLARATOR 
				   | INITDECLARATORLIST ',' INITDECLARATOR
				   ;

INITDECLARATOR : DECLARATOR  {}
			   | DECLARATOR '=' INITIALIZER {
			   		char *idname = $1, *value = $3;
			   		add_value(value,idname,scope_count);
			   		strcpy(QUAD[Index].op,"=");
					strcpy(QUAD[Index].arg1,$3);
					strcpy(QUAD[Index].arg2,"");
					strcpy(QUAD[Index].result,$1);
					strcpy($$,QUAD[Index++].result);
					//AddQuadruple("=",$1,$3,$$);
			   		}

			   
			   
			   ;

TYPESPECIFIER : T_VOID {strcpy(k,"void");/*k="void";*/}
				| T_CHAR{strcpy(k,"char");/*k="char";*/} 
				| T_INT {strcpy(k,"int"); /*k="int";*/}
				| T_FLOAT{strcpy(k,"float");/*k="float";*/} 
				; 

TYPENAME : TYPESPECIFIER 
		 | TYPESPECIFIER TYPENAME
		 ;

DECLARATOR : T_IDENTIFIER  {
								extern int column;
								line_no=column;	
								s=yylval.text;
								//printf("20000\n");
								if(ob>0 && cb ==0)
									scope_count=ob;
								else if(ob-cb==1)
									scope_count=scope;

								else
									scope_count=ob;

								l=search(s,scope_count);
								//printf("return of recurse is ------------------------%d\n",l );
								char type[10];
								strcpy(type,k);
								//printf("vlaue of k is ---------------%s\n", k);
								if(l==0){
								create_node(&first,"ID",type,s,1000,scope_count,line_no,"0",line_no);}
								else
									{	
										printf("ERROR!!! at line %d\n REDECLARATION of IDENTIFIER %s\n",line_no,yylval.text);
										exit(1);
									}

							}
		   | '(' DECLARATOR ')' 
		   | DECLARATOR '('')' 
		   | DECLARATOR '(' PARAMETERTYPELIST ')' 
		   | DECLARATOR '(' IDENTIFIERLIST ')'
		   ;


PARAMETERTYPELIST : PARAMETERLIST 
				  | PARAMETERLIST ',' T_ELLIPSIS 
				  ;

PARAMETERLIST : PARAMETERDECLARATION 
			  | PARAMETERLIST ',' PARAMETERDECLARATION
			  ;

PARAMETERDECLARATION : DECLARATIONSPECIFIERS DECLARATOR 
					 | DECLARATIONSPECIFIERS
					 ;

IDENTIFIERLIST : T_IDENTIFIER 
			   | IDENTIFIERLIST ',' T_IDENTIFIER
			   ;

INITIALIZER : ASSIGNMENTEXPRESSION 
			| '{' INITIALIZERLIST '}'
			| '{' INITIALIZERLIST ',' '}'
			;

INITIALIZERLIST : INITIALIZER 
				| INITIALIZERLIST ',' INITIALIZER
				;

STATEMENT : COMPOUNDSTATEMENT 
		  | EXPRESSIONSTATEMENT 
		  | SELECTIONSTATEMENT 
		  | ITERATIONSTATEMENT 
		  | JUMPSTATEMENT 
		  ;

COMPOUNDSTATEMENT	: '{' '}' 
					| '{' new_scope block_item_list '}' new_scope_end
					;

new_scope: { //scope = NEWSCOPE;
			ob++;
			scope++;
			//scope_count++;
			//printf("scope started %d\n",scope_count);

			}
		 ;

new_scope_end : {
					cb++;
					scope--;
					//
					//printf("scope ended\n");
					//write and pop (write the functions)
				}
			  ;

block_item_list : block_item
				| block_item_list block_item
				;

block_item : DECLARATION { /*printf("DECLARATION::  \n" );*/}
		   | STATEMENT { /*printf("STATEMENT::  \n" );*/}
		   ;


EXPRESSIONSTATEMENT : ';'  | EXPRESSION ';' { /*res = $$ ; printf("200\n");*/} 
				    ;

SELECTIONSTATEMENT :   T_IF '(' EXPRESSION ')' STATEMENT 
				   	|T_IF '(' CREATE_LABEL1 EXPRESSION CREATE_LABEL2 ')' STATEMENT CREATE_LABEL3 T_ELSE STATEMENT{create_label("GOTO","","","");}
				 
				       ;
CREATE_LABEL1 : {create_label("LABEL","","","");}
			;
			
CREATE_LABEL2 : {create_label("ifFalse",QUAD[Index-1].result,"","");create_label("GOTO","","","");create_label("LABEL","","","");}
			;

CREATE_LABEL3 : {create_label("GOTO","","","");sprintf(lab,"%d",lIndex-3);create_label("LABEL","","",lab);}
				;



ITERATIONSTATEMENT : T_WHILE{create_label("LABEL","","","");} '(' EXPRESSION ')'{create_label("ifFalse",QUAD[Index-1].result,"","");create_label("GOTO","","","");}STATEMENT{sprintf(lab,"%d",lIndex-3);create_label("GOTO","","",lab);sprintf(lab,"%d",lIndex-2);create_label("LABEL","","",lab);}
				 
				     | T_FOR '(' EXPRESSION ';' {create_label("LABEL","","","");}EXPRESSION {create_label("ifFalse",QUAD[Index-1].result,"","");create_label("GOTO","","","");}';'{create_label("LABEL","","","");} EXPRESSION {sprintf(lab,"%d",lIndex-4);create_label("GOTO","","",lab);}')' {sprintf(lab,"%d",lIndex-2);create_label("LABEL","","",lab);}STATEMENT{sprintf(lab,"%d",lIndex-3);create_label("LABEL","","",lab);}
				   ;
JUMPSTATEMENT : T_CONTINUE ';' 
			  | T_BREAK ';' 
			  | T_RETURN ';' 
			  | T_RETURN EXPRESSION ';'
			  ;
%%

extern int yylex();
extern int yyparse();
extern FILE *yyin;


int main()
{
	
first=NULL;
sym_init(&first);
display(first);
char *b = "123";
//printf("--------------------------------------------------------------------------------------------%d",toInt(b));

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
	display(first);
	//printf("hello from the other side\n");
	printf("\n\n");
	printf("\n\t%s\t|\t%s\t|\t%s\t|\t%s\t|\t%s","pos","op","arg1","arg2","result");
	printf("\n\t-----------------------------------------------------------------------");
	for(int i=0;i<Index;i++)
	{
		printf("\n\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s", i,QUAD[i].op, QUAD[i].arg1,QUAD[i].arg2,QUAD[i].result);
	}
	printf("\n\n\n");

	
}


int yyerror()
{
extern int column;
	if(column==1)
		printf("\n error at line 1\n");
	else
		printf("\n error at line %d\n",column-1);
	return 0;
}


int search(char *text,int scope_count)
{


	struct symbol *p;
	p=first;
	//display(first);
	int flag=0;
	while(p!=NULL)
	{
		if(strcmp(p->symb,text)==0)
		{
			//printf("symbol and scope_count %s %d\n",p->symb,p->var_scope );
			if(p->var_scope==scope_count) // already there and scope matches -> re
			{	
				//printf("symbol and scope_count %s %d\n",p->symb,p->var_scope );
				id_val=p->value;
				flag =1;
				break;
			}
			else  //there but scope doesnt match
			{
				//printf("elseeeeee\n");
				flag = 0;
				p=p->next;
			}
		}
		else{  //not found at all
			//printf("flaggggggg 22222222\n");
			p=p->next;
			flag = 2;
		}
		
	}

	if(flag == 0 || flag == 2)
		return 0;
	else
		return 1;

	
}
void sym_init(struct symbol **second)
{
	
	printf("label\t\ttype\t\value\t\taddr\t\tscope\t\tlineNo\t\tvalue\n");
	printf("------------------------------------------------------------");
	for(int i=0;i<8;i++)
	{ 
        create_node(second,"keyword","KEYWORD" ,keywords[i],1000+i+4,0,0,"0",0);
	}
	
}

void change_line(char *id,int line_no,int scope)
{
	struct symbol *p;
	p=first;
	while(p!=NULL)
	{
		if(strcmp(p->symb,id)==0){
			if(p->var_scope==scope)
			{p->live_line = line_no;
			return;}
			else
				p=p->next;
		}
		else
			p=p->next;
	}	
}



void add_value(char *value, char *id_name, int scope)
{
//printf("ADD VALUE VALUE %s\n",value);
	struct symbol *p;
	p = first;
	while(p!=NULL)
	{
		
		if(strcmp(p->symb,id_name)==0)
		{	

			if(p->var_scope==scope)
				{
					strcpy(p->value,value);
					return;
				}
			else
				{
					p = p->next;
				}
		}
		else
			p = p->next;
	}
}

int toInt(char *a) 
{
  int c, sign, offset, n;
 
  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }
 
  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }
 
  n = 0;
 
  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }
 
  if (sign == -1) {
    n = -n;
  }
 
  return n;
}

int check_type(char *op1)	//return 1 if digit else return 0
{
	if(op1[0]>=48 && op1[0]<58)
		return 1;
	else 
		return 0;
}

void checker(char *val1,char *val2)
{
	printf(" -------------%s %s\n", val1,val2);
	int p=check_type(val2);
 	int p1=check_type(val1);
 
    if(p==0)
  	{//printf("in IF op val2 %d\n",op);
  		recurse(val2,scope_count);
		op =toInt(id_val);}
	else{
		//printf("in else op val2 %d\n",op);
		op=toInt(val2);
		}
	//printf("op val2 %d\n",op);
	if(p1==0){
		recurse(val1,scope_count);
		op1 =toInt(id_val);}	
	else
		op1=toInt(val1);
}

int recurse(char *text, int scope_count_func)
{
	int t=0;
	while(t!=1 && scope_count_func!=-1)
	{

		t=search(text, scope_count_func);

		scope_count_func--;
	}
	if(t==1)
		return scope_count_func+1;
	else
		return -1;
}

void AddQuadruple(char op[5],char arg1[10],char arg2[10],char result[10],char res[10])
{
	extern int column;
	strcpy(QUAD[Index].op,op);
	strcpy(QUAD[Index].arg1,arg1);
	strcpy(QUAD[Index].arg2,arg2);
	sprintf(QUAD[Index].result,"t%d",tIndex++);
	strcpy(result,QUAD[Index++].result);
	create_node(&first,"temp","temp",result,10000,scope_count,-1,res,-1);
}
void create_label(char op[10],char arg1[10],char arg2[10],char result[10])
{
printf("Create label\n");
	strcpy(QUAD[Index].op,op);
	strcpy(QUAD[Index].arg1,arg1);
	strcpy(QUAD[Index].arg2,arg2);
	if(strlen(result)==0)
		sprintf(QUAD[Index].result,"L%d",lIndex++);
	else
		sprintf(QUAD[Index].result,"L%d",toInt(result));
	Index++;
	
}


