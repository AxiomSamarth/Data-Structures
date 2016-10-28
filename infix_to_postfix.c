#include<stdio.h>
#include<stdlib.h>
struct oprstk
{
    char items[30];
    int top;
};
main()
{
    char infix[30],postfix[30];
    printf("\nEnter the infix expression : ");
    scanf("%s",infix);
    infix_postfix(infix,postfix);
    printf("\nThe postfix expression is : %s\n",postfix);
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
void push(char symbol,struct oprstk *s)
{
    if(s->top==29)
    {
        printf("\nThe stack is full..!!\n");
        return;
    }
    ++(s->top);
    s->items[s->top]=symbol;
}
char pop(struct oprstk *s)
{
    if(s->items[s->top]==-1)
    {
        printf("\nThe stack is empty..!!\n");
        return;
    }
    char item;
    item=s->items[s->top];
    s->top--;
    return item;
}
void infix_postfix(char infix[],char postfix[])
{
    int i,j=0;
    struct oprstk s;
    s.top=-1;
    for(i=0;infix[i]!='\0';i++)
    {
        if(isoperand(infix[i]))
        {
            postfix[j++]=infix[i];
        }
        else
        {
            while(s.top!=-1&&stkprcd(&s.items[s.top])>=inputprcd(&infix[i]))
            {
                if(infix[i]==')')
                {
                    while(s.items[s.top]!='(')
                    {
                        postfix[j++]=pop(&s);
                    }
                    pop(&s);
                    break;
                }
                else
                {
                    postfix[j++]=pop(&s);
                }
            }
            if(infix[i]!=')')
            {
                push(infix[i],&s);
            }
        }
    }
    while(s.top!=-1)
    {
        postfix[j++]=pop(&s);
    }
    postfix[j]='\0';
}
int stkprcd(char* sym)
{
   switch(*sym)
   {
        case '+':
        case '-':   return 4;
                    break;
        case '*':
        case '/':   return 6;
                    break;

        case '$':
        case '^':   return 7;
                    break;

        case '(':   return 0;
                    break;

   }
}
int inputprcd(char *a)
{
    switch(*a)
    {
        case '(': return 9;
                  break;

        case '+':
        case '-': return 3;
                  break;

        case '/':
        case '*':return 5;

        case '$':
        case '^':return 8;

        case ')':return 0;
                 break;


    }
}
