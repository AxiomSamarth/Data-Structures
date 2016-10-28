#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    char a[100];
    int top;
}STACK;
void init(STACK *);
void push(STACK *,char);
char pop(STACK *);
main()
{
    char a[100];
    STACK s;
    init(&s);
    printf("\nEnter the expression : ");
    scanf("%s",a);
    int i;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='('||a[i]=='['||a[i]=='{')
        {
            push(&s,a[i]);
        }
        else if(a[i]==')')
        {
            if(pop(&s)=='(')
            {
                continue;
            }
            else
            {
                printf("\nThe ( expression is not properly not paranthesized..!!\n");
                exit(0);
            }
        }
        else if(a[i]==']')
        {
            if(pop(&s)=='[')
            {
                continue;
            }
            else
            {
                printf("\nThe [ expression is not properly not paranthesized..!!\n");
                exit(0);
            }
        }
        else if(a[i]=='}')
        {
            if(pop(&s)=='{')
            {
                continue;
            }
            else
            {
                printf("\nThe { expression is not properly not paranthesized..!!\n");
                exit(0);
            }
        }
    }

    if(s.top!=-1)
    {
        printf("\nThe expression is not properly paranthesized..!!\n");
        return;
    }
    printf("\nThe expression is properly paranthesized..!\n");
}

void init(STACK *s)
{
    s->top=-1;
}
void push(STACK *s,char val)
{
    if(s->top==99)
    {
        printf("\nThe stack is full..!!\n");
        return;
    }
    s->top++;
    s->a[s->top]=val;
}
char pop(STACK *s)
{
    if(s->top==-1)
    {
        printf("\nStack underflow..!!\n");
        return;
    }
    s->top--;
    return s->a[s->top+1];
}








