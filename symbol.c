#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct symbol
{
	char label[15];
	char symb[15];
    int addr;
    int var_scope;
    int line_no;
    char type[10];
    char value[10];
    int live_line;
    struct symbol *next;
};

void insert();
void display();


void create_node(struct symbol **f,char *lab,char *type,char *sym,int addr,int var_scope,int line_no,char *value,int live_line);

void create_node(struct symbol **f,char *lab,char *type,char *sym,int addr,int var_scope,int line_no,char *value,int live_line)
{
    //printf("SYMBOL TRING TO CREATE IS :%s\n",sym);
    struct symbol *p,*q;
    p=(struct symbol*)malloc(sizeof(struct symbol));
	
    strcpy(p->label,lab);  
    //printf("P->label done\n");
    strcpy(p->symb,sym);
    //printf("P->symb done\n");
    strcpy(p->type,type);
    //printf("P->typedone\n");
    p->addr=addr;
    p->var_scope=var_scope;
    p->line_no=line_no;
    strcpy(p->value,value);
    //printf("P->value done\n");
    p->live_line=live_line;
    

    p->next=NULL;
      /* 4. If the Linked List is empty, then make the new node as head */
    if (*f == NULL) 
    { 
        *f = p;}   
    
    else
    {
    	q=*f;
        //printf("%s\n",q->label);
        while (q->next != NULL) 
        {
            //printf("symbol%s\n",q->symb );
            q = q->next; 
        }
   
    /* 6. Change the next of last node */
    q->next = p;
    //printf("%s\n",p->label ); 
    //free(q);
    return; 
    }
	
	
}
 void display(struct symbol *p)//struct symbol **last)
 {
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("label\t\t\ttype\t\t\tsymbol\t\t\tscope\t\t\tlineNo\t\t\tvalue\t\t\tlive_line\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

 	while(p!=NULL)
 	{
 		printf("%s\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t%d\t\t\t%s\t\t\t\t%d\n",p->label,p->type,p->symb,p->var_scope,p->line_no,p->value,p->live_line);
 		p=p->next;
 	}

 }
