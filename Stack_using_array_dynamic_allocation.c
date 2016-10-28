#include<stdio.h>
#include<stdlib.h>
int n,top=-1;
void push(int []);
void pop(int []);
void peep(int []);
void print(int []);
main()
{
    int ch,*a;
    printf("\nEnter the size of the stack : ");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    while(1)
    {
        printf("\n1. Push Stack.\n2. Pop Stack.\n3. Peep Stack.\n4. Display Stack.\n5. Exit.\n Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(a);
                    break;

            case 2: pop(a);
                    break;

            case 3: peep(a);
                    break;

            case 4: print(a);
                    break;

            case 5: printf("\nThank you for using my program..!!\n");
                    exit(0);

            default:printf("\nThe choice is invalid..!!");
                    exit(0);
        }
    }
}
void push(int *a)
{
    if(top==n-1)
    {
        printf("\nStack overflow..!!\n");
        return;
    }
    int val;
    printf("\nEnter the integer to push into stack : ");
    scanf("%d",&val);
    top++;
    a[top]=val;
}
void pop(int *a)
{
    if(top==-1)
    {
        printf("\nStack underflow..!!\n");
        return;
    }
    printf("\nThe popped element is %d.\n",a[top]);
    top--;
}

void peep(int *a)
{
    if(top==-1)
    {
        printf("\nThe stack is empty..!!\n");
        return;
    }
    printf("\nThe top most element of the stack is %d.\n",a[top]);
}

void print(int *a)
{
    if(top==-1)
    {
        printf("\nThe stack is empty..!!\n");
        return;
    }
    int i;
    for(i=top;i>=0;i--)
    {
        printf("\t%d",a[i]);
    }
    printf("\n");
}
