#include<stdio.h>
#include<stdlib.h>
struct stack
{
    char arr[100];
    int top;
};
typedef struct stack STACK;
void init(STACK *);
void push(STACK *,char );
char pop(STACK *);
void print(STACK *);
main()
{
    STACK s;
    char a[100];
    init(&s);
    printf("\nEnter the string : ");
    scanf("%s",a);
    int i;

    /*Now push the characters on to stack*/

    for(i=0;a[i]!='\0';i++)
    {
        push(&s,a[i]);
    }

    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!=pop(&s))
        {
            printf("\nNot a palindrome..!!\n");
            exit(0);
        }
    }
    printf("\nYes the string %s is a palindrome..!!\n",a);
}
void push(STACK *s,char val)
{
    if(s->top==99)
    {
        printf("\nThe stack is full..!!\n");
        return;
    }
    (s->top)++;
    s->arr[s->top]=val;
}

char pop(STACK *s)
{
    if(s->top==-1)
    {
        printf("\nThe stack is empty..!!\n");
        return;
    }
    s->top--;
    return s->arr[s->top+1];

}

void init(STACK *s)
{
    s->top=-1;
}













