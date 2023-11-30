#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void sortNames(char *name[], int n);
void swap(char *name1, char *name2);
int main()
{
    int n = 3;
    char *names[n];
    for(int i = 0; i < n; i++)
    {
        names[i] = (char*)malloc(sizeof(char));
    }
    printf("\nEnter names : \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%s", names[i]);
    }
 //   for(int i = 0; i < n; i++)
 //   {
 //       printf("%s  ", names[i]);
 ///   }
    sortNames(names, n);
    for(int i = 0; i < n; i++)
    {
        printf("%s ", names[i]);
    }
    for(int i = 0; i < n; i++)
    {
        free(names[i]);
    }
    printf("\nTest line");
    return 0;
}

void sortNames(char *names[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
       for(int j = i+1; j < n; j++)
        {
            if(strcmp(names[i], names[j]) > 0)
            {
               /* char *temp = (char*)malloc(sizeof(char));
                strcpy(temp,names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
                free(temp);*/
                swap(&names[i], &names[j]);
            }

        }
    }
}
void swap(char *name1, char *name2)
{
    char *temp = (char*)malloc(sizeof(char));
    *temp = *name1;
    *name1= *name2;
    *name2 = *temp;
}
