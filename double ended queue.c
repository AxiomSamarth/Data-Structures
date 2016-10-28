#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int arr[10];
    int front,rear;
};
typedef struct queue queue;
void insertfront(queue *);
void insertrear(queue *);
void deletefront(queue *);
void deleterear(queue *);
void display(queue *);
main()
{
    queue q;
    q.front=0;
    q.rear=-1;
    int ch;
    while(1)
    {
        printf("\n1. Insert Front\n2. Insert rear\n3. Delete Front\n4. Delete rear\n5. Display\n6. Exit.\n Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insertfront(&q);
                    break;

            case 2: insertrear(&q);
                    break;

            case 3: deletefront(&q);
                    break;

            case 4: deleterear(&q);
                    break;

            case 5: display(&q);
                    break;

            case 6: printf("\nThank you for using my program..!!\n");
                   exit(0);

            default:printf("\nThe choice is invalid..!!\n");
                    exit(0);
        }
    }
}
void insertfront(queue *q)
{
   if(q->front==0&&q->rear==9)
   {
       printf("\nThe insertion not possible..!!\n");
       return;
   }
   else
   {
       if(q->rear==-1&&q->front==0)
       {
           printf("\nEnter the item to enqueue : ");
           scanf("%d",&q->arr[++(q->rear)]);
       }
       else
       {
            if(q->front!=0)
            {
                printf("\nEnter the item to enqueue : ");
                scanf("%d",&q->arr[--(q->front)]);
            }
            else
            {
                printf("\nThe insertion is not possible..!!\n");
                return;
            }
       }
    }
}

void insertrear(queue *q)
{
    if(q->rear==9)
    {
        printf("\nThe rear insertion not possible..!!\n");
        return;
    }
    printf("\nEnter the value to insert at front : ");
    scanf("%d",&q->arr[++(q->rear)]);
}

void deletefront(queue *q)
{
    if(q->front==0&&q->rear==-1)
    {
        printf("\nThe queue is empty..!!\n");
        return;
    }
    printf("\nThe deleted item is %d\n",q->arr[(q->front)++]);
    if(q->rear<q->front)
    {
        q->front=0;
        q->rear=-1;
    }
}
void deleterear(queue *q)
{
    if(q->rear==-1&&q->front==0)
    {
        printf("\nThe queue is empty..!!\n");
        return;
    }
    printf("\nThe deleted item is %d\n",q->arr[(q->rear)--]);
    if(q->rear<q->front)
    {
        q->front=0;
        q->rear=-1;
    }
}

void display(queue *q)
{
    if(q->front>q->rear)
    {
        printf("\nThe queue is empty..!!\n");
        return;
    }
    int i=q->front;
    printf("\nThe queue is");
    for(i;i<=q->rear;i++)
    {
        printf("\t%d",q->arr[i]);
    }
}
