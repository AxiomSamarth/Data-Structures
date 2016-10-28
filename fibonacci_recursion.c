#include<stdio.h>
#include<stdlib.h>
void fibonacci(int );
main()
{
    int n;
    printf("\nEnter the number of Fibonacci terms required : ");
    scanf("%d",&n);
    printf("\n");
    fibonacci(n);
    printf("\n");
}
void fibonacci(int n)
{
    static a=0,b=1,c;
    if(n>0)
    {
        printf("\t%d",a);
        c=a+b;
        b=a;
        a=c;
        fibonacci(n-1);
    }
    else
    {
        return;
    }
}
