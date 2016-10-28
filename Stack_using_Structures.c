#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int arr[10];
    int top;
};
typedef struct stack STACK;
void init(STACK *s);
void push(STACK *);
void pop(STACK *);
void peep(STACK *);
void print(STACK *);
int isfull(STACK *);
int isempty(STACK *);
main()
{
    int ch;
    STACK s;
    init(&s);
    while(1)
    {
        printf("\n1. Push stack.\n2. Pop stack.\n3. Peep stack.\n4. Display satck.\n5. Exit.\n Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(&s);
                    break;

            case 2: pop(&s);
                    break;

            case 3: peep(&s);
                    break;

            case 4: print(&s);
                    break;

            case 5: printf("\nThank you for using my program..!!\n");
                    exit(0);

            default : printf("\nThe choice is invalid..!!\n");
                      exit(0);
        }
    }
}
void init(STACK *s)
{
    s->top=-1;
}
int isfull(STACK *s)
{
    if(s->top==9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(STACK *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(STACK *s)
{
    if(isfull(s))
    {
        printf("\nThe stack is full..!!\n");
        return;
    }
    int val;
    s->top++;
    printf("\nEnter the value to push into stack : ");
    scanf("%d",&val);
    s->arr[s->top]=val;
}
void pop(STACK *s)
{
    if(isempty(s))
    {
        printf("\nThe Stack is empty..!!\n");
        return;
    }
    printf("\nThe popped value is %d.\n",s->arr[s->top]);
    s->top--;
}
void peep(STACK *s)
{
    if(isempty(s))
    {
        printf("\nThe stack is empty..!!\n");
        return;
    }
    printf("\nThe top most element of the stack is %d.\n",s->arr[s->top]);
}
void print(STACK *s)
{
    if(isempty(s))
    {
        printf("\nThe stack is empty..!!\n");
        return;
    }
    int i;
    printf("\nThe stack is ");
    for(i=s->top;i>=0;i--)
    {
        printf("\t%d",s->arr[i]);
    }
    printf("\n");
}
