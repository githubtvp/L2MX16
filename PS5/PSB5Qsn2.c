#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAXSZ 15
void processArr(char *ch, int aSz, char ch1, char ch2);

int main()
{
    char str[MAXSZ];
    printf("\nEnter the string again : \n");
    scanf("%s", str);
    int theStrLen = strlen(str);
    printf("\nThe string is  : %s, and length is : %d", str, theStrLen);  
    char ch1, ch2;
    printf("\nEnter the char to be replaced : \n");
    scanf("   %c", &ch1);
    printf("\nEnter the char to replace with : \n");
    scanf("   %c", &ch2);
    processArr(str, theStrLen, ch1, ch2);
    printf("\nThe string after replacements : \n %s", str); 
    return 0;
}

void processArr(char *ch, int aSz, char ch1, char ch2)
{
    for(int i = 0; i < aSz; i++)
    {
        if(ch[i] == ch1)
        {
            ch[i] = ch2;
        }
    }
}
