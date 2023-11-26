#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>
int getLength(char *str);
void fact();
void countVowels();
void getWords();
int main()
{
    // char str[50];
    // printf("\nEnter the string : ");
    // // scanf("%s", str); // will take only first word
    // fgets(str, 50, stdin);
    // printf("%s", str);

    // int len = getLength(str);
    // printf("\nLength : %d", len);
    // fact();
    //countVowels();
    getWords();
    printf("\nTest line");
    return 0;
}

void getWords()
{
    int nWords = 5;    int i;
    char *ptr[nWords];
    for(i = 0; i < nWords; i++)
    {
          ptr[i] = (char*)malloc(100*sizeof(char));
    }
    printf("\nEnter the 5 words : ");
    for(i = 0; i < nWords; i++)
    {
       // printf("\nScan");
        scanf("%s", ptr[i]);
    }
   //printf("\nEntry done\n");
    for(i = 0; i < nWords; i++)
    {
        printf("\n%s", ptr[i]);
    }
}
void countVowels()
{
    char str[100];
    printf("\nEnter the string : ");
    // scanf("%s", str); // will take only first word
    fgets(str, 100, stdin);
    char *ptr;// = (char*)malloc(100*sizeof(char));
    ptr = str;
    printf("\n%s", ptr);
    int i = 0;
    int count = 0;
    while (*(ptr + i) != '\0')
    {
       // printf("\n1. Here");
        char ch = tolower(*(ptr + i));
        if (ch == ' ')
        {
           // printf("\n2. Here");
            i++;
            continue;
        }
        else
        {
            // printf("\n3 Here");
            if (isalpha(ch))
            {
                // printf("\n4 Here");
                if (ch == 'a' || ch =='t')
                   // printf("\nFound A ");
                count++;
               // break;
            }
        }
        i++;
    }
    printf("\nCount : %d ", count);
}
void fact()
{
    int n = 4;
    // printf("\nEnter a Number : " );
    // scanf("%d", &n);
    int *ptr = &n;
    int i = 0;
    int fact = 1;
    while (i < n)
    {
        fact = fact * ((*ptr) - i);
        i++;
    }
    printf("\nFactorial :%d", fact);
}
int getLength(char *str)
{
    int count = 0;
    while (*(str + count) != '\0')
    {
        count++;
    }
    return count - 1;
}