#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[20];
    struct date
    {
        char day[10],month[20];
        int year;
    }a[10];
};
#include<string.h>
main()
{
    struct student s;
    strcpy(s.name,"SAMARTH");
    strcpy(s.a[0].day,"MONDAY");
    strcpy(s.a[0].month,"MAY");
    s.a[0].year=2015;
    display(&s);

}
void display(struct student *s)
{
       printf("\n%s",s->a[0].month);
}
