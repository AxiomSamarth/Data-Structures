#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack
{
    char items[30][30];
    int top;
};
typedef struct stack stack;
int isoperand(char);
char* pop(stack *);
void push(char [],stack *);
void postfix_prefix(char [],char []);
main()
{
    char postfix[30],prefix[30];
    printf("\nEnter the postfixed expression :");
    scanf("%s",postfix);
    postfix_prefix(postfix,prefix);
    printf("\nThe prefixed expression is %s\n",prefix);
}

int isoperand(char a)
{
    switch(a)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '$':
        case '^':return 0;
                 break;
        default:return 1;
    }
}

void push(char a[],stack *s)
{
    if(s->top==29)
    {
        printf("\nThe stack is full..!!\n");
        return;
    }
    strcpy(s->items[++(s->top)],a);
}
char* pop(stack *s)
{
    if(s->top==-1)
    {
        printf("\nThe stack is empty..!!\n");
        return;
    }
    return s->items[(s->top)--];
}
void postfix_prefix(char postfix[],char prefix[])
{
    int i;
    char *op1,*op2,t2[2],t1[2],opr;
    stack s;
    s.top=-1;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isoperand(postfix[i]))
        {
            t2[0]=postfix[i];
            t2[1]='\0';
            push(t2,&s);
        }
        else
        {
            opr=postfix[i];
            t1[0]=opr;
            t1[1]='\0';
            strcpy(prefix,t1);
            op2=pop(&s);
            op1=pop(&s);
            strcat(prefix,op1);
            strcat(prefix,op2);
            push(prefix,&s);
        }
    }
}
