#include<stdio.h>
int main()
{
char *cities[] = {"Delhi", "London", "Sydney"};
int **i = &cities[0];
printf("%c\n", **i);
return 0;
}
