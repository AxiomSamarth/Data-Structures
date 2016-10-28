#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int arr[10];
    int rear,front;
};
typedef struct queue queue;
void enqueue(queue *);
void dequeue(queue *);
void display(queue *);
main()
{
    queue q;
    q.front=0;
    q.rear=-1;
    int ch;
    while(1)
    {
        printf("\n1. Enqueue.\n2. Dequeue.\n3. Display.\n4. Exit.\n Enter your choice : ");
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

            default: printf("\nThe choice is invalid..!!\n");
                     exit(0);
        }

    }
}
void enqueue(queue *q)
{
    if(q->rear==9)
    {
        printf("\nThe queue is full..!!\n");
        return;
    }
    int val;
    printf("\nEnter the value to enqueue :");
    scanf("%d",&q->arr[++(q->rear)]);
}
void dequeue(queue *q)
{
    if(q->front==0&& q->rear==-1)
    {
        printf("\nThe queue is empty..!!\n");
        return;
    }
    q->front++;
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
    for(i=q->front;i<=q->rear;i++)
    {
        printf("\t%d",q->arr[i]);
    }
}
