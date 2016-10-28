#include<stdio.h>
#include<stdlib.h>
double power(int n);
main()
{
    int n;
    printf("\nEnter the power of two required :");
    scanf("%d",&n);
    double result=power(n);
    printf("\nThe value of 2 power %d is %.0lf.\n",n,result);
}
double power(int n)
{
    if(n>0)
    {
        return 2*power(n-1);
    }
    else
    {
        return 1;
    }
}
