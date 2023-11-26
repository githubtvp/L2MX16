#include <stdio.h>
#include <stdlib.h>

#define MAX 15

int calSteps(int n);
int main()
{
    int nSteps = 0;
    int nWays = 0;
    printf("\nEnter the no of steps to climb : \n");
    scanf("%d", &nSteps);
    if (nSteps > 0)
    {
        nWays = calSteps(nSteps);
    }
    printf("\nNo of ways : %d", nWays);
    //  printf("\n\nTest line PS7Qsn4");
    return 0;
}

int calSteps(int n)
{
    int sum;
    if (0 == n)
        return 1;
    if (1 == n)
        return 1;
    if (n > 1)
    {
        sum = calSteps(n - 1) + calSteps(n - 2);
    }
    return sum;
}
