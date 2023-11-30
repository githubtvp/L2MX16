#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 1024

void trimSp (char *line, int len);
int main()
{
    //char *line[MAX]; //= (char*)malloc(sizeof(char) * MAX);
    char *line = (char*)malloc(sizeof(char) * MAX);
    printf("\nEnter a sentence :\n");
    fgets(line, MAX, stdin);
    int len = strlen(line);
    printf("\nLength of line : %d", len);
    trimSp(line, len);
   // printf("%s\n",line);
   /// printf("\ntest line ");
    free(line);
    return 0;
}

void trimSp (char *line, int len)
{
   // char *temp = (char*)malloc(sizeof(char) * MAX);
  //  temp = line;
    int j = 0;
    int i = 0;
    while(line[j] == ' ')
    {
        j++;
    }
    printf("\n J value after loop %d", j);
    while( (i + j) < len)
    {
        line[i] = line[i+j];
        i++;
    }
    printf("\n I value after loop %d\n", i);
    i-=2;
    while( i > 0 && line[i] == ' ')
    {
        printf("%d ", i);
        line[i] = '\0';
        i--;
    }

   // printf("\n%s",line);// printf("\nHere \n");
    i = 0;
    while(line[i] != '\0')
    {
        printf("\n%d  :  %c", i, line[i]);
        i++;
    }

 //  int newLen = strlen(line);
    printf("\nNew length : %d", (i-1));
}
