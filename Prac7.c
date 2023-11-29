#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getInt();
int main()
{
    int N = 20, M=10;
    int n, i;
    char aWord[N], *wordArr[M];
   /* printf("\nEnter 3 number of names : \n");
    scanf("%d", &n);
    printf("\nEnter the names : \n");
    for(i = 0; i < n; i++)
    {       
        scanf("%s", aWord);
        wordArr[i] = (char*)malloc( (strlen(aWord)+ 1) * sizeof(char) );
        strcpy(wordArr[i], aWord);
    }
    for(i = 0; i < n; i++)
    {       
        printf("%s ", wordArr[i]);
    }*/
    getInt();
    printf("\nTest line");
    return 0;
}

void getInt()
{
    int *p, n, i;
    printf("\nEnter value for n : \n");
    scanf("%d", &n);
    printf("\nEnter value for array : \n");
    for(i = 0; i < n; i++)
    {       
        scanf("%d", &p[i]);
    }
    for(i = 0; i < n/2; i++)
    {       
        printf("%d ", p[i]);
    }
    for(i = n-1; i >= n/2; i--)
    {       
        printf("%d ", p[i]);
    }
}