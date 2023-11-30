#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getInt();
void staticArrOfPointers();
int **allocate(int r, int c);
void readData(int **p, int r, int c);
void printData(int **p, int r, int c);
int main()
{
    int r = 3, c = 4;
    int **p;
    p = allocate(r, c);
    readData(p, r, c);
    printData(p, r, c);
    // getInt();
    printf("\nTest line");
    return 0;
}

int **allocate(int r, int c)
{
    int **p, i;
    p = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
    {
        p[i] = (int *)malloc(c * sizeof(int));
    }
    return p;
}

void readData(int **p, int r, int c)
{
    int i, j;
    printf("\nEnter the array elements : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    return p;
}

void printData(int **p, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
    return p;
}

void staticArrOfPointers()
{
    int N = 20, M = 10;
    int n, i;
    char aWord[N], *wordArr[M]; // this is static array of pointers
    printf("\nEnter 3 number of names : \n");
    scanf("%d", &n);
    printf("\nEnter the names : \n");
    char *aWord2 = (char *)malloc(sizeof(char));
    for (i = 0; i < n; i++)
    {
        scanf("%s", aWord2);
        // wordArr[i] = (char*)malloc( (strlen(aWord)+ 1) * sizeof(char) );
        wordArr[i] = (char *)malloc(sizeof(char));
        strcpy(wordArr[i], aWord2);
    }
    for (i = 0; i < n; i++)
    {
        printf("%s ", wordArr[i]);
    }
}

void getInt()
{
    int *p, n, i;
    printf("\nEnter value for n : \n");
    scanf("%d", &n);
    printf("\nEnter value for array : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (i = 0; i < n / 2; i++)
    {
        printf("%d ", p[i]);
    }
    for (i = n - 1; i >= n / 2; i--)
    {
        printf("%d ", p[i]);
    }
}