#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int arr[10];
    int front,rear;
};
typedef struct queue queue;
void dequeue(queue *);
void enqueue(queue *);
void display(queue *);

main()
{
    queue q;
    q.front=0;
    q.rear=-1;
    int ch;
    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n Enter the choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue(&q);
                    break;

            case 2: dequeue(&q);
                    break;

            case 3: display(&q);
                    break;

            case 4: printf("\nThank you for using my program..!!\n");
                    exit(0);

            default:printf("\nThe choice is invalid..!!\n");
                    exit(0);
        }
    }
}
void enqueue(queue *q)
{
    if(q->rear==9&&q->front==0)
    {
        printf("\nThe queue is full..!\n");
        return;
    }
    int i,item;
    printf("\nEnter the value to enqueue : ");
    scanf("%d",&item);
    for(i=q->rear;i>=0&&item<q->arr[i];i--)
    {
        q->arr[i+1]=q->arr[i];
    }
    q->arr[i+1]=item;
    q->rear++;
}
void dequeue(queue *q)
{
    if(q->rear==-1&&q->front==0)
    {
        printf("\nThe queue is empty..!!\n");
        return;
    }
    printf("\nThe dequeued element is %d\n",q->arr[(q->front)++]);
    if(q->front>q->rear)
    {
        q->rear=-1;
        q->front=0;
    }
}

void display(queue *q)
{
    if(q->rear==-1&&q->front==0)
    {
        printf("\nThe queue is empty..!!\n");
        return;
    }
    int i;
    printf("\nThe queue is");
    for(i=q->front;i<=q->rear;i++)
    {
        printf("\t%d",q->arr[i]);
    }
    printf("\n");
}











