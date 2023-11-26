#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15
float power(float x, int n);

int main()
{
    float x = 2.0;
    int n = 11;
    float res = 0.0;
    for (int i = 0; i <= -1; i++)
    {
        ++n;
    }
    printf("\n %d", n);
   // printf("\nEnter the value for x(base) : \n");
  //  scanf("%f", &x);
   // printf("\nEnter the value for n(power) : \n");
  //  scanf("%d", &n);
    res = power(x, n);
 //   printf("\nResult : %f", res);
    // printf("\nTest line PS7Qsn3");
    return 0;
}

float power(float x, int n)
{
    float res = 1.0;
    for (int i = n; i > 0; i--)
    {
        res = res * x;
    }
    return res;
}
