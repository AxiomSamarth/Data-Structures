#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *left,*right;
};
struct node* createnode(int);
void insert(struct node **,struct node *);
void PrintLeafNode(struct node **);
void PrintNonLeafNode(struct node **);

main()
{
    struct node *root=NULL,*newnode;
    int ch,val;
    while(1)
    {
        printf("\n1. Insert value into the tree.\n2. Print the leaf nodes\n3. Print the non leaf nodes\n4. Exit\n   Enter the choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the choice:");
                    scanf("%d",&val);
                    newnode=createnode(val);
                    if(root==NULL)
                    {
                        root=newnode;
                    }
                    else
                    {
                        insert(&root,newnode);
                    }
                    break;

            case 2: PrintLeafNode(&root);
                    break;

            case 3: PrintNonLeafNode(&root);
                    break;

            case 4: printf("\nThank you for using my program..!!\n");
                    exit(0);

            default:printf("\nThe choice is invalid..!!\n");
                    exit(0);

        }
    }
}

struct node* createnode(int val)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->val=val;
    newnode->right=newnode->left=NULL;
    return newnode;
}

void insert(struct node **root,struct node *newnode)
{
    if(*root==NULL)
    {
        return;
    }
    if((*root)->val>newnode->val)
    {
        if((*root)->left==NULL)
        {
            (*root)->left=newnode;
        }
        else
        {
            insert(&(*root)->left,newnode);
        }
    }
    else
    {
        if((*root)->right==NULL)
        {
            (*root)->right=newnode;
        }
        else
        {
            insert(&(*root)->right,newnode);
        }
    }
}

void PrintLeafNode(struct node **root)
{
    if(*root==NULL)
    {
        return;
    }
    if((*root)->right==NULL && (*root)->left==NULL)
    {
        printf("\t%d",(*root)->val);
    }
    PrintLeafNode(&(*root)->left);
    PrintLeafNode(&(*root)->right);
}

void PrintNonLeafNode(struct node  **root)
{
    if(*root==NULL)
    {
        return;
    }
    if((*root)->left!=NULL ||(*root)->right!=NULL)
    {
        printf("\t%d",(*root)->val);
    }
    PrintNonLeafNode(&(*root)->left);
    PrintNonLeafNode(&(*root)->right);
}
