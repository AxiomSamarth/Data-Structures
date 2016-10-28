
/*
Title   : C program to insert values in a Binary Search Tree and traverse it in Preorder,
Postorder and inorder traversal methods

Author  : Samarth Deyagond

Date    : 08/11/2015   */



#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *left,*right;
};
struct node* createnode(int);
void insert(struct node **,struct node *);
void preorder(struct node **);
void postorder(struct node **);
void inorder(struct node **);
void CountLeafNodes(struct node **,int *);
void CountNodes(struct node **,int *);

main()
{
    struct node *root=NULL,*newnode;
    int ch,val,countl=0,countn=0;
    while(1)
    {
        printf("\n1. Insert value\n2. Preorder traversal\n3. Postorder traversal\n4. Inorder traversal\n5. Count leaves\n6. Count nodes\n7. Exit\n   Enter the choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the value to insert :");
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

            case 2: preorder(&root);
                    break;

            case 3: postorder(&root);
                    break;

            case 4: inorder(&root);
                    break;

            case 5: CountLeafNodes(&root,&countl);
                    printf("\n\nThere are totally %d leaf nodes in the tree..!!\n\n",countl);
                    break;

            case 6: CountNodes(&root,&countn);
                    printf("\nThere are totally %d nodes in the tree..!!\n\n",countn);
                    break;

            case 7: printf("\nThank you for using my program..!!\n");
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
    newnode->left=newnode->right=NULL;
    return newnode;
}

void insert(struct node  **root,struct node *newnode)
{
    if(*root==NULL)
    {
        return;
    }
    if(newnode->val>=(*root)->val)
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
    else
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
}

void preorder(struct node **root)
{
    if(*root==NULL)
    {
        return;
    }
    printf("\t%d",(*root)->val);
    preorder(&(*root)->left);
    preorder(&(*root)->right);
}

void inorder(struct node **root)
{
    if(*root==NULL)
    {
        return;
    }
    inorder(&(*root)->left);
    printf("\t%d",(*root)->val);
    inorder(&(*root)->right);
}

void postorder(struct node **root)
{
    if(*root==NULL)
    {
        return;
    }
    postorder(&(*root)->left);
    postorder(&(*root)->right);
    printf("\t%d",(*root)->val);
}

void CountLeafNodes(struct node **root,int *count)
{
    if(*root==NULL)
    {
        return;
    }
    if((*root)->left==NULL && (*root)->right==NULL)
    {
        (*count)++;
    }
    CountLeafNodes(&(*root)->left,count);
    CountLeafNodes(&(*root)->right,count);
}

void CountNodes(struct node **root,int *count)
{
    if(*root==NULL)
    {
        return;
    }
    (*count)++;
    CountNodes(&(*root)->left,count);
    CountNodes(&(*root)->right,count);
}




