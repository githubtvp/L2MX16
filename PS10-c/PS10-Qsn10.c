#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void sortNames(char *str[], int n);
int main()
{
    int sz = 50, i;
    int n = 3;
    char *str[n];
    for(i=0; i < n; i++)
    {
      str[i] = (char*)malloc( sz * sizeof(char));
    }
    printf("\nEnter a few names :  ");
    i = 0;
    while(i < n)
    {
         //fgets(str[i], sz, stdin);
         gets(str[i]);
         i++;
    }
   // sortNames(str, n);
    i = 0;
    while(i < n )
    {
       // printf("\n Here 1");
        printf("\n%d : %s", i, *(str + i));
        i++;
    }
    printf("\n After sort");
    sortNames(str, n);
    i = 0;
    while(i < n )
    {
        printf("\n Here 1");
        printf("\n%d : %s", i, *(str + i));
        i++;
    }

printf("\nTest line");
return 0;
}

void sortNames(char *str[], int n)
{
    char *temp;
    temp = (char*)malloc(50*sizeof(char));
    printf("\n1. Test line");
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i +1; j < n; j++)
        {
            printf("\n2. Test line");
            if( strcmp(*(str + i), *(str + j)) > 0)
            {
               printf("\n3. Test line");
               strcpy(temp,*(str + i));
               strcpy(*(str + i), *(str + j));
               strcpy(*(str + j), temp);
            }
        }
    }
    free(temp);
}
