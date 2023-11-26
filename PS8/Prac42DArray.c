#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX 10
void getArr(char str[][MAX], int n);
void prArr(char str[][MAX], int n);
int main()
{
    int n;
    printf("\nEnter how many names :\n");
    scanf("%d", &n);
    char names[n][10];
    getArr(names, n);
    prArr(names,n);
    printf("\nTest line ");
    return 0;
}

void getArr(char str[][MAX], int n)
{
    printf("\nEnter the names one by one : \n");
    for(int i =0; i < n; i++)
    {
        scanf("\n%s", &str[i]);
    }
}

void prArr(char str[][MAX], int n)
{
    printf("\nNames are : \n");
    for(int i =0; i < n; i++)
    {
        printf("\n%s  ", str[i]);
    }
}