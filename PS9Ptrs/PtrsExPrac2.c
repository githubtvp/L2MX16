#include<stdio.h>
int main()
{
int a = 10, b = 6;
int *ptr;
ptr = &b;
printf("%d", a **ptr);
return 0;
}
