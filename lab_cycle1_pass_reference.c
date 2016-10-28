#include<stdio.h>
#include<stdlib.h>
struct time
{
    int hour,minute,second;
};

void init(struct time );
struct time read(struct time);
void display(struct time );
struct time update(struct time );
struct time check(struct time );
main()
{
    int ch;
    struct time a;
    init(a);
    while(1)
    {
        printf("\n1. Read time.\n2. Display time.\n3. Update time.\n4. Exit.\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: a=read(a);
                    break;

            case 2: display(a);
                    break;

            case 3: a=update(a);
                    break;

            case 4: printf("\nThank you for using my program..!!\n");
                    exit(0);

            default:printf("\nThe choice is invalid..!!\n");
                    exit(0);
        }
    }
}

struct time read(struct time a)
{
    printf("\nEnter the hour-minute and time : ");
    scanf("%d%d%d",&a.hour,&a.minute,&a.second);
    a=check(a);
    return a;
}
struct time check(struct time a)
{
    printf("\nIn check\n");
    if(a.second>=60)
    {
        a.minute+=a.second/60;
        a.second=a.second%60;
    }
    if(a.minute>=60)
    {
        a.hour+=a.minute/60;
        a.minute=a.minute%60;
    }
    if(a.hour>=24)
    {
        a.hour=a.hour%24;
    }
    return a;

}
void display(struct time a)
{
    printf("\nThe time is %d hr : %d min : %d sec\n",a.hour,a.minute,a.second);
}
struct time update(struct time a)
{
    a.second++;
    a=check(a);
    return a;
}
void init(struct time a)
{
    a.hour=0;
    a.minute=0;
    a.second=0;

}













