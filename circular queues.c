#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int arr[5];
    int rear,front,count;
};
typedef struct queue queue;
void enqueue(queue *);
void dequeue(queue *);
void display(queue *);
int isfull(queue *);
int isempty(queue *);
main()
{
    queue q;
    q.rear=-1;
    q.front=0;
    q.count=0;
    int ch;
    while(1)
    {
        printf("\n1. Enqueue.\n2. Dequeue.\n3. Display.\n4. Exit.\n Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue(&q);
                    break;

            case 2: dequeue(&q);
                    break;

            case 3: display(&q);
                    break;

            case 4: printf("\nThank you for using my programs..!!\n");
                    exit(0);

            default:printf("\nThe choice is invalid..!!\n");
                    exit(0);
        }
    }
}
void enqueue(queue *q)
{
    if(isfull(q))
    {
        printf("\nThe queue is full..!!\n");
        return;
    }
    int val;
    printf("\nEnter the value to be enqueued : ");
    scanf("%d",&val);
    q->count++;
    q->rear=(q->rear+1)%5;
    q->arr[(q->rear)]=val;
}

void dequeue(queue *q)
{
    if(isempty(q))
    {
        printf("\nThe queue is empty..!!\n");
        return;
    }

    printf("\nThe dequeued element is %d\n",q->arr[q->front]);
    q->count--;
    q->front=(q->front+1)%5;
}
void display(queue *q)
{
    if(isempty(q))
    {
        printf("\nThe queue is empty..!!\n");
        return;
    }
    int i,j=q->front;
    for(i=0;i<q->count;i++)
    {
        printf("\t%d",q->arr[j]);
        j=(j+1)%5;
    }

}

int isempty(queue *q)
{
    if(q->count==0)
    {
        return 1;
    }
    return 0;
}
int isfull(queue *q)
{
    if(q->count==5)
    {
        return 1;
    }
    return 0;
}





