#include<stdio.h>
#include<stdlib.h>
#define size 10
void print(int [],int);
void push(int [],int *);
void pop(int [],int *);
void peep(int [],int);
main()
{
    int ch,a[size],top=-1;
    for(;;)
    {
        printf("\n1. Push stack.\n2. Pop stack.\n3. Peep stack.\n4. Display stack.\n5. Exit.\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(a,&top);
                    break;

            case 2: pop(a,&top);
                    break;

            case 3: peep(a,top);
                    break;

            case 4: print(a,top);
                    break;

            case 5: printf("\nThank you for using my program..!!\n");
                    exit(0);

            default:printf("\nThe choice is invalid..!!\n");
                    exit(0);

        }
    }
}

void push(int a[],int *top)
{
    if(*top==size-1)
    {
        printf("\nStack overflow..!!\n");
        return;
    }
    int val;
    (*top)++;
    printf("\nEnter the integer to be pushed : ");
    scanf("%d",&val);
    a[*top]=val;
}

void pop(int a[],int *top)
{
    if(*top==-1)
    {
        printf("\nStack underflow..!!\n");
        return;
    }
    printf("\nThe popped element is %d.\n",a[*top]);
    (*top)--;
}

void peep(int a[],int top)
{
    if(top==-1)
    {
        printf("\nThe stack is empty..!!\n");
        return;
    }
    printf("\nThe top most element of the stack is %d\n",a[top]);
}

void print(int a[],int top)
{
    if(top==-1)
    {
        printf("\nThe stack is empty..!!\n");
        return;
    }
    int i;
    printf("\nThe stack is");
    for(i=top;i>=0;i--)
    {
        printf("\t%d",a[i]);
    }
}






