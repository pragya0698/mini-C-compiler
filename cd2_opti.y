%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symbol.c"

int yylex();
int yyerror();
int ob=0, cb=0; 
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
void checker(char *val1,char *val2);
void create_label(char op[5],char arg1[10],char arg2[10],char result[10]);
struct symbol *first;
char m[20], k[10], *id, *s, *id_val,lab[10];

struct quad
	{
		char op[10];
		char arg1[10];
		char arg2[10];
		char result[10];
	}QUAD[30];



	int Index=0;
	int tIndex=0; 
	int StNo;
	int Ind; 
	int tInd;
	int lIndex=0;




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

PRIMARYEXPRESSION : T_IDENTIFIER {	
								FILE *f = fopen("Error.txt","a");
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
									fprintf(f,"%s:%d:%s\n","ERROR at line",line_no,"UNDECLARED IDENTIFIER");
									exit(1);
								}
								change_line(yylval.text,line_no,l);
								
							}
					| T_CONSTANT {/*add_value(yylval.text,s,scope_count);*/ }
					| T_STRINGLITERAL {/*printf("9\n");*/ add_value(yylval.text,s,scope_count);}
					| '(' EXPRESSION ')'  {/*printf("10\n");*/}
					;

POSTFIXEXPRESSION : PRIMARYEXPRESSION {}
				  | POSTFIXEXPRESSION '[' EXPRESSION ']'
				  | POSTFIXEXPRESSION '(' ')' 	{/*printf("12\n");*/}
				  | POSTFIXEXPRESSION '(' ARGUMENTEXPRESSIONLIST ')' 	{/*printf("13\n");*/}
				  | POSTFIXEXPRESSION T_INC	{
				  		
				  							
				  							char res[40];
				  							strcpy(res,$1);
				  							l=recurse($1,scope_count);
				  							int op1=toInt(id_val);
				  							int op2=op1+1;
				  							sprintf($$,"%d",op2);
				  							sprintf(res2,"%d",op2);
				  							AddQuadruple("=",$1,"",$$,res2);
				  							
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
				  							sprintf(res2,"%d",op2); 															        			
				  							AddQuadruple("=",$1,"",$$,res2);
				  							
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
				| SHIFTEXPRESSION T_LEFT_SHIFT ADDITIVEEXPRESSION	{	checker($1,$3);
																        op4=op1<<op;
																        sprintf(res2,"%d",op4);	
																        AddQuadruple("<<",$1,$3,$$,res2);
					 													} 
				| SHIFTEXPRESSION T_RIGHT_SHIFT ADDITIVEEXPRESSION	{	checker($1,$3);
																        op4=op1>>op;
																        sprintf(res2,"%d",op4);
																        AddQuadruple(">>",$1,$3,$$,res2);}
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
					
					 ;
EQUALITYEXPRESSION : RELATIONALEXPRESSION 
					 | EQUALITYEXPRESSION T_EQ RELATIONALEXPRESSION {	checker($1,$3);
																        if(op1==op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																      
					 												AddQuadruple($2,$1,$3,$$,res2);}
					 												
					 | EQUALITYEXPRESSION T_NE RELATIONALEXPRESSION{	checker($1,$3);
					 												printf("OP1 %d op %d \n",op1,op);
																        if(op1!=op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																        printf("RESULT %s\n",res2);
					 												AddQuadruple($2,$1,$3,$$,res2);}
					 ;


ANDEXPRESSION : EQUALITYEXPRESSION 
				| ANDEXPRESSION '&' EQUALITYEXPRESSION	{				checker($1,$3);
					 												  
																        if(op1&op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																      
					 												AddQuadruple("&",$1,$3,$$,res2);}
				;
EXCLUSIVEOREXPRESSION : ANDEXPRESSION 
					   | EXCLUSIVEOREXPRESSION '^' ANDEXPRESSION	{	checker($1,$3);
					 												
																        if(op1^op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																      
					 												AddQuadruple("^",$1,$3,$$,res2);}
					   ;

INCLUSIVEOREXPRESSION :EXCLUSIVEOREXPRESSION 
					  | INCLUSIVEOREXPRESSION '|' EXCLUSIVEOREXPRESSION	{checker($1,$3);
					 												
																        if(op1|op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																      
					 												AddQuadruple("|",$1,$3,$$,res2);}
					  ;

LOGICALANDEXPRESSION : INCLUSIVEOREXPRESSION 
					 | LOGICALANDEXPRESSION T_AND INCLUSIVEOREXPRESSION{checker($1,$3);
					 												  
																        if(op1&&op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																      
					 												AddQuadruple("&&",$1,$3,$$,res2);}
					 ;

LOGICALOREXPRESSION : LOGICALANDEXPRESSION 
					| LOGICALOREXPRESSION T_OR LOGICALANDEXPRESSION	{checker($1,$3);
					 												  
																        if(op1||op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																      
					 												AddQuadruple("||",$1,$3,$$,res2);}
					;

CONDITIONALEXPRESSION : LOGICALOREXPRESSION 
						| LOGICALOREXPRESSION '?' EXPRESSION ':' CONDITIONALEXPRESSION
						;

ASSIGNMENTEXPRESSION : CONDITIONALEXPRESSION {}
					 | UNARYEXPRESSION ASSIGNMENTOPERATOR ASSIGNMENTEXPRESSION {
					 	strcpy(QUAD[Index].op,"=");
					 	int l=recurse($3,scope_count);
					 	if(l==1)
							strcpy(QUAD[Index].arg1,id_val);
						else
							strcpy(QUAD[Index].arg1,$3);
						strcpy(QUAD[Index].arg2,"");
						strcpy(QUAD[Index].result,$1);
						strcpy($$,QUAD[Index++].result);
					 	int check;
					 	check=check_type($3);
					 	if(check==0)
					 		strcpy($3,res2);
					 	l=recurse($1, scope_count);
					 	if(l!=-1)
						 	add_value($3,$1,l);
					 }
					 ;
ASSIGNMENTOPERATOR : '=' {/*printf("146\n");*/} | T_SHORT_MUL | T_SHORT_DIV | T_SHORT_MOD | T_SHORT_ADD | T_SHORT_SUB | T_SHORT_LEFT | T_SHORT_SHIFT | T_SHORT_AND | T_SHORT_XOR | T_SHORT_OR ;

EXPRESSION : ASSIGNMENTEXPRESSION { /*printf("147\n");*/}
			| EXPRESSION ',' ASSIGNMENTEXPRESSION 
			;
			
CONSTANTEXPRESSION : CONDITIONALEXPRESSION
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
			  // printf("INTDECl\n");
			   		char *idname = $1, *value = $3;
			   		add_value(value,idname,scope_count);
			   		strcpy(QUAD[Index].op,"=");
					strcpy(QUAD[Index].arg1,$3);
					strcpy(QUAD[Index].arg2,"");
					strcpy(QUAD[Index].result,$1);
					strcpy($$,QUAD[Index++].result);
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
DECLARATOR : DIRECTDECLARATOR
		   ;

DIRECTDECLARATOR : T_IDENTIFIER  {	FILE *f = fopen("Error.txt","a");
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
								char type[10];
								strcpy(type,k);
								if(l==0){
								create_node(&first,"ID",type,s,1000,scope_count,line_no,"0",line_no);}
								else
									{	
										fprintf(f,"%s:%d:%s\n","ERROR at line",line_no,"REDECLARATION OF IDENTIFIER");										
										exit(1);
									}

							}
		   | '(' DECLARATOR ')' 
		   | DIRECTDECLARATOR '[' CONSTANTEXPRESSION ']'
	       	   | DIRECTDECLARATOR '[' ']'
		   | DECLARATOR '(' PARAMETERTYPELIST ')' 
		   | DECLARATOR '(' IDENTIFIERLIST ')'
		   | DECLARATOR '('')' 
		   ;


PARAMETERTYPELIST : PARAMETERLIST 
				  | PARAMETERLIST ',' T_ELLIPSIS 
				  ;

PARAMETERLIST : PARAMETERDECLARATION 
			  | PARAMETERLIST ',' PARAMETERDECLARATION
			  ;

PARAMETERDECLARATION : DECLARATIONSPECIFIERS DECLARATOR 
					 | DECLARATIONSPECIFIERS ABSTRACTDECLARATOR
					 | DECLARATIONSPECIFIERS
					 ;

IDENTIFIERLIST : T_IDENTIFIER 
			   | IDENTIFIERLIST ',' T_IDENTIFIER
			   ;
			   
ABSTRACTDECLARATOR : DIRECTABSTRACTDECLARATOR
				   ;

DIRECTABSTRACTDECLARATOR : '(' ABSTRACTDECLARATOR ')'
						 | '[' ']'
						 | '[' CONSTANTEXPRESSION ']'
						 | DIRECTABSTRACTDECLARATOR '[' ']'
						 | DIRECTABSTRACTDECLARATOR '[' CONSTANTEXPRESSION ']'
						 | '(' ')'
						 | '(' PARAMETERTYPELIST ')'
						 | DIRECTABSTRACTDECLARATOR '(' ')'
						 | DIRECTABSTRACTDECLARATOR '(' PARAMETERTYPELIST ')'
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
		

			}
		 ;

new_scope_end : {
					cb++;
					scope--;
					
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

SELECTIONSTATEMENT :   //T_IF '(' EXPRESSION ')' STATEMENT 
				   	T_IF '(' EXPRESSION CREATE_LABEL2 ')' STATEMENT CREATE_LABEL3 T_ELSE STATEMENT CREATE_LABEL4
				 
				       ;
							//else label
CREATE_LABEL2 : {create_label("ifFalse",QUAD[Index-1].result,"","");}
			;
					//outside label
CREATE_LABEL3 : {create_label("LABEL","","","");sprintf(lab,"%d",lIndex-1);create_label("GOTO","","",lab); sprintf(lab,"%d",lIndex-2);create_label("LABEL","","",lab);}
				;
CREATE_LABEL4:{sprintf(lab,"%d",lIndex-1);create_label("GOTO","","",lab);create_label("LABEL","","",lab);}



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
	display(first);
	printf("\n\n");
	printf("\n\t\t%s\t\t|\t\t%s\t\t|\t\t%s\t\t|\t\t%s\t\t|\t\t%s","pos","op","arg1","arg2","result");
	printf("\n\t---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	for(int i=0;i<Index;i++)
	{
		printf("\n\t\t%d\t\t|\t\t%s\t\t|\t\t%s\t\t|\t\t%s\t\t|\t\t%s", i,QUAD[i].op, QUAD[i].arg1,QUAD[i].arg2,QUAD[i].result);
	}
	printf("\n\n");
}


int yyerror()
{
printf("Terminated because of Error\n");
FILE *f = fopen("Error.txt","w");
extern int column;
	if(column==1)
		fprintf(f,"%s\n","error at line 1");
	else
		fprintf(f,"%s:%d\n","Error at line ",column-1);
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
  	{
  		recurse(val2,scope_count);
		op =toInt(id_val);}
	else{
		op=toInt(val2);
		}
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
	int l=recurse(arg1,scope_count);
	
	if(l==1){
		strcpy(QUAD[Index].arg1,id_val);
		}
	else
	{strcpy(QUAD[Index].arg1,arg1);}
	int l1=recurse(arg2,scope_count);
	if(l1==1){
		strcpy(QUAD[Index].arg2,id_val);}
	else
	{strcpy(QUAD[Index].arg2,arg2);}
	sprintf(QUAD[Index].result,"t%d",tIndex++);
	strcpy(result,QUAD[Index++].result);
	create_node(&first,"temp","temp",result,10000,scope_count,-1,res,-1);
}

void create_label(char op[10],char arg1[10],char arg2[10],char result[10])
{

	strcpy(QUAD[Index].op,op);
	strcpy(QUAD[Index].arg1,arg1);
	strcpy(QUAD[Index].arg2,arg2);
	if(strlen(result)==0)
		sprintf(QUAD[Index].result,"L%d",lIndex++);
	else
		sprintf(QUAD[Index].result,"L%d",toInt(result));
	Index++;
	
}
