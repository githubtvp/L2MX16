#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAXWORDS 15

void getArr(char str[][MAX], int n);
void prArr(char str[][MAX], int n);
void sortArray(char str[][MAX], int n);
void pop2dArray(char str[][3][MAX], int m, int n, char str1[][MAX], int sz);
void pr2dArray(char str2[][3][MAX], int m, int n);
int main()
{
    int n = 12;
    // printf("\nEnter how many names :\n");
    //  scanf("%d", &n);
    //  char names[n][10];
    // getArr(names, n);
    char names[12][MAX] = {"name2", "name12", "name1", "name5", "name4", "name9", "name11", "name8", "name10", "name6", "name7", "name3"};
    //   prArr(names, n);
    sortArray(names, n);
    printf("\nAfter sort :");
    prArr(names, n);
    char namesArr[4][3][MAX];
    pop2dArray(namesArr, 4, 3, names, n);
    printf("\n\nAfter arranged :");
    pr2dArray(namesArr, 4, 3);
   // printf("\nTest line ");
    return 0;
}

void pop2dArray(char str2[][3][MAX], int m, int n, char str1[][MAX], int sz)
{
    int theSz = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            strcpy(str2[i][j], str1[theSz]);
            theSz++;
        }
    }
}

void pr2dArray(char str2[][3][MAX], int m, int n)
{
    printf("\nNames are : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%s  ", str2[i][j]);
        }
        printf("\n\n");
    }
}

void sortArray(char str[][MAX], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            char temp[MAX];
            if (strcmp(str[i], str[j]) > 0) // swap reqd
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
}

void getArr(char str[][MAX], int n)
{
    printf("\nEnter the names one by one : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &str[i]);// To take input from the user %s format specifier is used 
             //that takes input characters till a new line or a space is detected.
    }
}

void prArr(char str[][MAX], int n)
{
    printf("\nNames are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s  ", str[i]);
    }
}