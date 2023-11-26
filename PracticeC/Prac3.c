#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAXLEN 100
int getALine(char **aStr, int *aSz);
int main()
{
    char *string = NULL;
    size_t size = 0;
    ssize_t chars_read;
    // read a long string with getline
    puts("Enter a really long string:");
    chars_read = getline(&string, &size, stdin);
    printf("getline returned %ld\n", chars_read);

    /* size_t theLineLen = 100;
     char *str = NULL;
    // str = (char*)malloc(theLineLen);

 //    int byteRead = getALine(str, &theLineLen);
     printf("\nEnter a sentence : \n");

     size_t byteRead = getline(&str, &theLineLen, stdin);
     */
    /* if(0==byteRead)
     {
         puts("\nError!");
     }
     else
     {
         puts("\nYou entered : \n");
         puts(str);
     }*/
    return 0;
}

int getALine(char **aStr, int *aSz)
{
    printf("\nEnetr a sentence : \n");
    int byteRead; // = getline(aStr, *aSz, stdin);
    int cnt = 0;
    while (aStr[cnt] != '\0')
    {
        cnt++;
    }
    *aSz = cnt;
    printf("\nNo of char in line : %d", *aSz);
    return byteRead;
}
