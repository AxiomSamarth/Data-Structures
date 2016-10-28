#include<stdio.h>
#include<stdlib.h>
main()
{
    int n,fact;
    printf("\nEnter the integer whose factorial is to be found: ");
    scanf("%d",&n);
    fact=(factorial(n));
    printf("\nThe factorial of %d is %d\n",n,fact);
}
int factorial(int n)
{
    if(n>1)
    {
        return n*factorial(n-1);
    }
    else
    {
        return 1;
    }
}
