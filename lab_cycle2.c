#include<stdio.h>
#include<stdlib.h>
struct student
{
    int reg,marks[3];
    float avg;
    char name[20];
};
main()
{
    int n,i;
    struct student *p;
    printf("\nEnter the number of students : ");
    scanf("%d",&n);
    p=(struct student *)malloc(sizeof(struct student)*n);
    printf("\nNow enter the details of %d students : ",n);
    for(i=0;i<n;i++)
    {
        read(p+i);
    }
    for(i=0;i<n;i++)
    {
        display(p+i);
    }
    for(i=0;i<n;i++)
    {
        average(p+i);
    }


}
void read(struct student *s)
{
    printf("\nEnter the name of student : ");
    scanf("%s",s->name);
    printf("\nEnter the register number :");
    scanf("%d",&s->reg);
    int i;
    for(i=0;i<3;i++)
    {
        input:printf("\nEnter the marks of test %d : ",i+1);
        scanf("%d",&s->marks[i]);
        if(s->marks[i]>100||s->marks[i]<0)
        {
            printf("\nThe marks are invalid..!!\n");
            goto input;
        }
    }
}
void display(struct student *s)
{
    printf("\nName \t: %s",s->name);
    printf("\nReg no\t:%d",s->reg);
    int i;
    for(i=0;i<3;i++)
    {
        printf("\nMarks in test %d : %d",i+1,s->marks[i]);
    }
}
void average(struct student *s)
{
    int big1,big2,i;
    big1=0;
    big2=0;
    for(i=0;i<3;i++)
    {
        if(s->marks[i]>big1)
        {
            big1=s->marks[i];
        }
    }
    for(i=0;i<3;i++)
    {
        if(s->marks[i]>big2&&s->marks[i]!=big1)
        {
            big2=s->marks[i];
        }
    }
    printf("\n%d and %d\n",big1,big2);
    s->avg=(float)(big1+big2)/2;
    printf("\nThe average of the best two tests is %f\n",s->avg);
}
