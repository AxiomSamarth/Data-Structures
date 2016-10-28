#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack1
{
    char items[30];
    int top;
};
struct stack2
{
    char items[30][30];
    int top;
};
typedef struct stack1 stack1;
typedef struct stack2 stack2;

void push1(char,stack1 *);
char pop1(stack1 *);
void push2(char [],stack2 *);
char* pop2(stack2 *);
int inputprcd(char);
int stackprcd(char);
int isoperand(char);
void infix_prefix(char [],char []);
main()
{
    char infix[30],prefix[30];
    printf("\nEnter the infix expression : ");
    scanf("%s",infix);
    infix_prefix(infix,prefix);
    printf("\nThe prefixed expression is %s\n",prefix);
}
void infix_prefix(char infix[],char prefix[])
{
    int i;
    stack1 oprstk;
    stack2 oprnstk;
    oprstk.top=-1;
    oprnstk.top=-1;
    char *op1,*op2,opr,t1[2],t2[2];
    for(i=0;infix[i]!='\0';i++)
    {
        if(isoperand(infix[i]))
        {
            t2[0]=infix[i];
            t2[1]='\0';
            push2(t2,&oprnstk);
        }
        else
        {
            while(oprstk.top!=-1&&stackprcd(oprstk.items[oprstk.top])>=inputprcd(infix[i]))
            {
                if(infix[i]==')')
                {
                    while(oprstk.items[oprstk.top]!='(')
                    {
                        opr=pop1(&oprstk);
                        op2=pop2(&oprnstk);
                        op1=pop2(&oprnstk);
                        t1[0]=opr;
                        t1[1]='\0';
                        strcpy(prefix,t1);
                        strcat(prefix,op1);
                        strcat(prefix,op2);
                        push2(prefix,&oprnstk);
                    }
                    pop1(&oprstk);
                    break;
                }
                else
                {
                        opr=pop1(&oprstk);
                        op2=pop2(&oprnstk);
                        op1=pop2(&oprnstk);
                        t1[0]=opr;
                        t1[1]='\0';
                        strcpy(prefix,t1);
                        strcat(prefix,op1);
                        strcat(prefix,op2);
                        push2(prefix,&oprnstk);

                }

            }
            if(infix[i]!=')')
            {
                  push1(infix[i],&oprstk);
            }
        }
    }

    while(oprstk.top!=-1)
    {

                        opr=pop1(&oprstk);
                        op2=pop2(&oprnstk);
                        op1=pop2(&oprnstk);
                        t1[0]=opr;
                        t1[1]='\0';
                        strcpy(prefix,t1);
                        strcat(prefix,op1);
                        strcat(prefix,op2);
                        push2(prefix,&oprnstk);
    }

}
void push1(char a, stack1 *s)
{
    if(s->top==29)
    {
        printf("\nThe stack is full..!!\n");
        return;
    }
    s->top++;
    s->items[s->top]=a;


}
void push2(char a[],stack2 *s)
{
    if(s->top==29)
    {
        printf("\nThe stack is full..!!\n");
        return;
    }
    s->top++;
    strcpy(s->items[s->top],a);

}
char pop1(stack1 *s)
{
    if(s->top==-1)
    {
        printf("\nThe operator stack is empty..!!\n");
        return;
    }
    char item;
    item=s->items[s->top];

    (s->top)--;
    return item;
}
char* pop2(stack2 *s)
{
    if(s->top==-1)
    {
        printf("\nThe operand stack is empty..!!\n");
        return;
    }
    char *item;
    item=s->items[s->top];

    (s->top)--;
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
        case '$':
        case '^':
        case ')':
        case '(':return 0;
                 break;
        default:return 1;
    }
}

int inputprcd(char a)
{
    switch(a)
    {
        case ')':return 0;
                 break;

        case '+':
        case '-':return 3;
                 break;

        case '*':
        case '/':return 5;
                 break;

        case '$':
        case '^':return 8;
                 break;

        case '(':return 9;
                 break;

    }
}
int stackprcd(char a)
{
    switch(a)
    {
        case '(':return 0;
                 break;

        case '+':
        case '-':return 4;
                 break;

        case '*':
        case '/':return 6;
                 break;

        case '$':
        case '^':return 7;
                 break;
    }
}





