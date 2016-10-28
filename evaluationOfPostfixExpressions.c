#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct stack
{
    char items[30];
    int top;
}stack;
int isoperand(char);
int evaluate(char []);
void push(char,stack *);
int compute(int,int,char);
char pop(stack *);
main()
{
    char postfix[100];
    printf("\nEnter the postfixed expresion:");
    scanf("%s",postfix);
    int result=evaluate(postfix);
    printf("\nThe result is %d\n",result);
}
int evaluate(char postfix[])
{
    int i,res;
    char op1,op2;
    stack oprnstk;
    oprnstk.top=-1;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isoperand(postfix[i]))
        {
            push(postfix[i],&oprnstk);
        }
        else
        {
            op2=pop(&oprnstk)-'0';
            op1=pop(&oprnstk)-'0';
            res=compute(op1,op2,postfix[i]);
            push(res+'0',&oprnstk);
        }
    }
    return res;
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
        case '^':return 0;
                 break;
        default:return 1;
    }
}
void push(char a,stack *s)
{
    if(s->top==29)
    {
        printf("\nThe stack is full..!!\n");
        return;
    }
    s->items[++(s->top)]=a;
}
char pop(stack *s)
{
    if(s->top==-1)
    {
        printf("\nThe stack is empty..!!\n");
        return;
    }
    return s->items[(s->top)--];
}

int compute(int a,int b,char sym)
{
    switch(sym)
    {
        case '+':return a+b;
                 break;

        case '-':return a-b;
                 break;

        case '*':return a*b;
                 break;

        case '/':return a/b;
                 break;

        case '$':
        case '^':return pow(a,b);
                 break;
    }
}









