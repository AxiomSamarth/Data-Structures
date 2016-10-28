#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node* createnode();
void insert(struct node *);
void del(struct node *);
void display(struct node *);
main()
{
    struct node head;
    head.val=0;
    head.next=NULL;
    int ch;
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n Enter the choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert(&head);
                    break;

            case 2: del(&head);
                    break;

            case 3: display(&head);
                    break;

            case 4: printf("\nThak you for using my program..!!\n");
                    exit(0);

            default:printf("\nThe choice is invalid..!!\n");
                    exit(0);
        }
    }
}
struct node* createnode()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value :");
    scanf("%d",&newnode->val);
    newnode->next=NULL;
    return newnode;
}

void del(struct node *head)
{
    if((head)->next==NULL)
    {
        printf("\nThe list isempty..\n");
        return;
    }
    struct node *temp=(head)->next;
    (head)->next=(head)->next->next;
    free(temp);
}

void display(struct node *head)
{
    if(head->next==NULL)
    {
        printf("\nThe list is empty..!!\n");
        return;
    }
    struct node *link=head->next;
    for(link;link!=NULL;link=link->next)
    {
        printf("\t%d",link->val);
    }
}

void insert(struct node *head)
{
    struct node *newnode=createnode();
    if(head->next==NULL)
    {
        head->next=newnode;
        return;
    }
    struct node *link=head;
    for(link;link->next!=NULL;link=link->next)
    {
        if(newnode->val<link->next->val)
        {
            newnode->next=link->next;
            link->next=newnode;
            return;
        }
    }
    for(link=head->next;link->next!=NULL;link=link->next);
    link->next=newnode;
}
