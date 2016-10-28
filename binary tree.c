#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *left,*right;
};
struct node* createnode();
void insert(struct node **,struct node *);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);

main()
{
    int ch;
    struct node *root=NULL,*newnode;
    while(1)
    {
        printf("\n1. Insert\n2. Preorder traversal\n3. Inorder traversal\n4. Postorder traversal\n5. Exit\n  Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: newnode = createnode();
                    if(root==NULL)
                    {
                        root = newnode;
                    }
                    else
                    {
                        insert(&root,newnode);
                    }
                    break;

            case 2: preorder(root);
                    break;

            case 3: inorder(root);
                    break;

            case 4: postorder(root);
                    break;

            case 5: printf("\nThank you for using my program..!!\n");
                    exit(0);

            default:printf("\nThe choice is invalid..!");
        }
    }
}


struct node* createnode()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value :");
    scanf("%d",&newnode->val);
    newnode->left=newnode->right=NULL;
    return newnode;
}

void insert(struct node **root, struct node *newnode)
{
    if(newnode->val > (*root)->val)
    {
        if((*root)->right == NULL)
        {
            (*root)->right = newnode;
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
            (*root)->left = newnode;
        }
        else
        {
            insert(&(*root)->left,newnode);
        }
    }
}

void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("\t%d",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("\t%d",root->val);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("\t%d",root->val);
    }
}







