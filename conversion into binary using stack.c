#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node* createnode(int);
void push(struct node **,struct node *);
void display(struct node *);
main()
{
    struct node *head=NULL,*newnode;
    int n;
    printf("Enter the number to be converted to binary format : ");
    scanf("%d",&n);
    while(n>0)
    {
        newnode = createnode(n%2);
        push(&head,newnode);
        n/=2;
    }
    printf("\nThe binary format is :\n");
    display(head);
}

struct node* createnode(int a)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->val=a;
    newnode->next=NULL;
    return newnode;
}

void push(struct node **head,struct node *newnode)
{
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        newnode->next=(*head);
        *head=newnode;
    }
}

void display(struct node *head)
{
    if(head==NULL)
    {
        printf("\nEmpty stack of bits\n");
    }
    else
    {
        struct node *link=head;
        while(link!=NULL)
        {
            printf("%d",link->val);
            link=link->next;
        }
    }
}

