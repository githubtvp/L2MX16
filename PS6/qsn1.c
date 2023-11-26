#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 100
int main()
{
    char str[MAX]; // = {"***###**##"};
    printf("\nEnter the string : \n");
    fgets(str, MAX, stdin);
   // printf("%s \n  sizeof str : %d\n", str, strlen(str));
    int cntStr =0, cntHas=0;
    for(int i=0; i< strlen(str);i++)
    {
      //  printf("%c  ", str[i] );
        if('*' == str[i])
        {
            cntStr++;
        }
        else if('#' == str[i])
        {
            cntHas++;
        }
    }
    printf("\nOutput : %d", (cntStr-cntHas));
    return 0;
}
