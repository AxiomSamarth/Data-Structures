#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node * createnode();
void insert(struct node **);
void display(struct node *);
void displayReverse(struct node *);

main()
{
    int ch;
    struct node *head=NULL;
    while(1)
    {
        printf("\n1. Insert\n2. Display\n3. Display in reverse order\n4. Exit\n Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert(&head);
                    break;

            case 2: display(head);
                    break;

            case 3: displayReverse(head);
                    break;

            case 4: printf("\nThank you for using my program..!\n");
                    exit(0);

            default:printf("\nThe choice is invalid..!!\n");
        }
    }
}

struct node* createnode()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value :");
    scanf("%d",&newnode->val);
    newnode->next = NULL;
    return newnode;
}

void insert(struct node **head)
{
    struct node *newnode = createnode();
    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *link = *head;
        for(link;link->next!=NULL;link=link->next);
        link->next=newnode;
    }
}

void display(struct node *head)
{
    if(head==NULL)
    {
        return;
    }
    else
    {
        printf("\t%d",head->val);
        display(head->next);
    }
}

void displayReverse(struct node *head)
{
    if(head==NULL)
    {
        return;
    }
    else
    {
        displayReverse(head->next);
        printf("\t%d",head->val);
    }
}









