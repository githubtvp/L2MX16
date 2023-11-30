#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void removespaces(char *str);
int main()
{
    int sz = 100;
    char *str;
    printf("\nEnter a sentence :  ");
    fgets(str, sz,stdin);
   // printf("\n%s",str);
    removespaces(str);


printf("\nTest line");
return 0;
}

void removespaces(char *str)
{
    // printf("\n%s",str);
     int count;
     while(*str != '\0' && isspace(*str))
     {
         str++;
        // count++;
     }
    // printf("\nCount : %d\n", count);
     char *end = str;
    // printf("\n%s",end);
     while(*end !='\0')
     {
         end++;
     }
     end--;
     while(isspace(*end))
     {
         end--;
     }
     printf("\nString : \n%s", str);
}
