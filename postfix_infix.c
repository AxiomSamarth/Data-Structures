#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack2
{
    char items[30][30];
    int top;
};

typedef struct stack2 stack2;

void push2(char [],stack2 *);

char* pop2(stack2 *);
void postfix_infix(char [],char []);
int isoperand(char);
main()
{
    char infix[30],postfix[30];
    printf("\nEnter the postfix expression:");
    scanf("%s",postfix);
    postfix_infix(infix,postfix);
    printf("\nThe infix expression is %s\n",infix);
}
void postfix_infix(char infix[],char postfix[])
{
    int i;
    char t2[2],t1[2],*op1,*op2,opr;
    stack2 oprnstk;

    oprnstk.top=-1;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isoperand(postfix[i]))
        {
            t2[0]=postfix[i];
            t2[1]='\0';
            push2(t2,&oprnstk);
        }
        else
        {
            op2=pop2(&oprnstk);
            op1=pop2(&oprnstk);
            opr=postfix[i];
            t1[0]=opr;
            t1[1]='\0';
            strcpy(infix,"(");
            strcat(infix,op1);
            strcat(infix,t1);
            strcat(infix,op2);
            strcat(infix,")");
            push2(infix,&oprnstk);
        }
    }


}



void push2(char a[],stack2 *s)
{
    if(s->top==29)
    {
        printf("\nThe stack is full..\n");
        return;
    }
    ++(s->top);
    strcpy(s->items[s->top],a);
}

char* pop2(stack2 *s)
{
    if(s->top==-1)
    {
        printf("\nThe stack is empty..!!\n");
        return;
    }
    char *item;
    item=s->items[s->top];
    s->top--;
    return item;
}
int isoperand(char a)
{
    switch(a)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '$':
        case '^': return 0;
                  break;
        default : return 1;

    }
}





