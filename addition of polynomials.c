#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef,px,py;
    struct node *next;
};

struct node* createnode(int,int,int);
void read(struct node **);
void add(struct node **,struct node **,struct node **);
void display(struct node **);

main()
{
    struct node *p1=NULL,*p2=NULL,*p3=NULL;
    read(&p1);
    printf("\n");
    display(&p1);
    printf("\n");
    read(&p2);
    printf("\n");
    display(&p2);
    add(&p1,&p2,&p3);
    printf("\nThe sum of polynomials is :\t");
    display(&p3);
    printf("\n");
}

struct node* createnode(int coef,int px,int py)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->coef=coef;
    newnode->px=px;
    newnode->py=py;
    newnode->next=NULL;
    return newnode;
}

void read(struct node **head)
{
    int c,x,y;
    struct node *link=*head;
    for(;;)
    {
        printf("\nEnter term and 0 to terminate :");
        scanf("%d",&c);
        if(c==0)
        {
            return;
        }
        printf("\nEnter powers of x and y :");
        scanf("%d%d",&x,&y);
        struct node *newnode=createnode(c,x,y);
        link=*head;
        if(*head==NULL)
        {
            *head=newnode;
        }
        else
        {
            for(link;link->next!=NULL;link=link->next);
            link->next=newnode;
        }
    }
}

void display(struct node **head)
{
    if(*head==NULL)
    {
        printf("\nThe stuff is incomplete..!!\n");
        return;
    }
    struct node *link=*head;
    for(link;link!=NULL;link=link->next)
    {
        printf("%d x^%d y^%d ",link->coef,link->px,link->py);

        if(link->coef>0 && link->next!=NULL)
        {
            printf(" + ");
        }
    }
}

void add(struct node **head1,struct node **head2,struct node **head3)
{

    struct node *temp1,*temp2,*temp3;
    for(temp1=*head1;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=*head2;temp2!=NULL;temp2=temp2->next)
        {
            if(temp1->px==temp2->px&&temp1->py==temp2->py)
            {

                struct node *newnode=createnode(temp1->coef+temp2->coef,temp1->px,temp1->py);
                struct node *link=*head3;
                if(*head3==NULL)
                {
                    *head3=newnode;
                }
                else
                {
                    for(link=*head3;link->next!=NULL;link=link->next);
                    link->next=newnode;
                }
            }
            else
            {
                continue;
            }
        }
    }

    temp1=*head1;
    temp2=*head2;
    temp3=*head3;
    int flag;

    for(temp1;temp1!=NULL;temp1=temp1->next)
    {
        flag=0;

        for(temp3=*head3;temp3!=NULL;temp3=temp3->next)
        {
            if(temp1->px==temp3->px&&temp1->py==temp3->py)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            struct node *link=*head3;
            struct node *newnode=createnode(temp1->coef,temp1->px,temp1->py);
            if(*head3==NULL)
            {
                *head3=newnode;
            }
            else
            {
                for(link=*head3;link->next!=NULL;link=link->next);
                link->next=newnode;
            }
        }
    }

    for(temp2;temp2!=NULL;temp2=temp2->next)
    {
        flag=0;
        for(temp3=*head3;temp3!=NULL;temp3=temp3->next)
        {
            if(temp2->px==temp3->px&&temp2->py==temp3->py)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            struct node *link=*head3;
            struct node *newnode=createnode(temp2->coef,temp2->px,temp2->py);
            if(*head3==NULL)
            {
                *head3=newnode;
            }
            else
            {
                for(link=*head3;link->next!=NULL;link=link->next);
                link->next=newnode;
            }
        }
    }
}









