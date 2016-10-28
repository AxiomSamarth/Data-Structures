#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct stack
{
    char items[30];
    int top;
};
typedef struct stack stack;
void push(char,stack *);
int isoperand(char);
char pop(stack *);
int compute(char []);
int evaluate(int,int,char);
main()
{
    char prefix[30];
    printf("\nEnter the prefix expression : ");
    scanf("%s",prefix);
    int result=compute(prefix);
    printf("\nThe result is %d\n",result);
}
int compute(char prefix[])
{
    int i;int res;
    stack s;
    s.top=-1;
    char op1,op2;
    for(i=strlen(prefix)-1;i>=0;i--)
    {
        if(isoperand(prefix[i]))
        {
            push(prefix[i],&s);
        }
        else
        {
            op1=pop(&s)-'0';
            op2=pop(&s)-'0';
            res=evaluate(op1,op2,prefix[i]);
            push(res+'0',&s);
        }
    }
    return res;
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
int evaluate(int a,int b,char sym)
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











