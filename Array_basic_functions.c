#include<stdio.h>
#include<stdlib.h>
void read(int [],int );
void print(int [],int);
void search(int [],int);
void sort(int [],int);
void insert(int [],int *);
void rem(int [],int *);
main()
{
    int ch,a[100],n;
    printf("\nEnter the size ofthe array : ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1. Create array.\n2. Display.\n3. Search.\n4. Sort.\n5. Insert.\n6. Delete.\n7. Exit.\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: read(a,n);
                    break;

            case 2: print(a,n);
                    break;

            case 3: search(a,n);
                    break;

            case 4: sort(a,n);
                    break;

            case 5: insert(a,&n);
                    break;

            case 6: rem(a,&n);
                    break;

            case 7: printf("\nThank you for using my program..!!\n");
                    exit(0);

            default: printf("\nThe choice is invalid.!!\n");
                     exit(0);
        }
    }

}

void read(int a[],int n)
{
    printf("\nEnter %d elements into the array : ",n);
    int i;
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=",i);
        scanf("%d",&a[i]);
    }
}

void print(int a[],int n)
{
    int i;
    printf("\nThe array is : ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
}

void search(int a[],int n)
{
    int key,i;
    printf("\nEnter the search key : ");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("\nThe key %d found at position %d\n",key,i+1);
            return;
        }
    }
    printf("\nThe key %d is not found..!!\n",key);
}

void sort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                a[j]=a[j+1]-a[j]+(a[j+1]=a[j]);
            }
        }
    }

    print(a,n);
}

void insert(int a[],int *n)
{
    int pos,val,i;
    printf("\nEnter position of insertion [0 based numbers]: ");
    scanf("%d",&pos);
    if(pos<0||pos>*n+1)
    {
        printf("\nInvalid insertion position folk..!!\n");
        return;
    }
    printf("\nEnter the value to be inserted : ");
    scanf("%d",&val);

    if(pos==*n)
    {
        a[pos]=val;
        (*n)++;
        print(a,*n);
        return;
    }

    for(i=*n-1;i>=pos;i--)
    {
        a[i+1]=a[i];
    }
    a[pos]=val;
    (*n)++;

   print(a,*n);

}

void rem(int a[],int *n)
{
    int pos,i;
    printf("\nEnter the position of deletion :");
    scanf("%d",&pos);
    if(pos<0||pos>=*n)
    {
        printf("\nThe position is invalid..!!\n");
        return;
    }

    for(i=pos;i<*n-1;i++)
    {
        a[i]=a[i+1];
    }
    (*n)--;
}

















