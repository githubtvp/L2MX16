#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100


int main()
{
    char **arr[MAX];
    int mRows, nCols;
    printf("\nEnter no of Rows :  ");
    scanf("%d", &mRows);
    printf("\nEnter no of Cols :  ");
    scanf("%d", &nCols);
    **arr = (char**)malloc(sizeof(char*[MAX]) * mRows);
    for(int i = 0; i < mRows; i++)
    {
        arr[i] = (char*)malloc(sizeof(char*) * nCols);
    }


    printf("\nTest line");
    return 0;
}
