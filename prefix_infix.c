#include<stdio.h>
#include<stdlib.h>

struct stack2
{
    char items[30][30];
    int top;
};

typedef struct stack2 stack2;
void push2(char [],stack2 *);
char* pop2(stack2 *);
void prefix_infix(char [],char []);
int isoperand(char);
main()
{
    char infix[30],prefix[30];
    printf("\nEnter the prefix expression : ");
    scanf("%s",prefix);
    prefix_infix(prefix,infix);
    printf("\nThe infixed expression is %s.\n",infix);
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
        case '(':
        case ')':return 0;
                 break;
        default:return 1;
                break;

    }
}

void push2(char a[],stack2 *s)
{
    if(s->top==29)
    {
        printf("\nNot a valid Prefix expression..!!\n");
        return;
    }
    s->top++;
    strcpy(s->items[s->top],a);
}
char* pop2(stack2 *s)
{
    if(s->top==-1)
    {
        printf("\nThe prefix expression is incorrect..!!\n");
        return;
    }
    char *item;
    item=s->items[s->top];
    s->top--;
    return item;
}
void prefix_infix(char prefix[],char infix[])
{
    int i;
    char *op1,*op2,opr,t1[2],t2[2];
    stack2 oprnstk;
    oprnstk.top=-1;
    for(i=strlen(prefix)-1;i>=0;i--)
    {
        if(isoperand(prefix[i]))
        {
            t2[0]=prefix[i];
            t2[1]='\0';
            push2(t2,&oprnstk);
        }
        else
        {
            opr=prefix[i];
            t1[0]=opr;
            t1[1]='\0';
            op1=pop2(&oprnstk);
            op2=pop2(&oprnstk);
            strcpy(infix,"(");
            strcat(infix,op1);
            strcat(infix,t1);
            strcat(infix,op2);
            strcat(infix,")");
            push2(infix,&oprnstk);
        }
    }
}













