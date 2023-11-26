#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAXLEN 100
int main()
{
    char s[] = "  \n\n  \t This is the way.";

    int cnt = 0;
    while(s[cnt] == ' '|| s[cnt] == '\n' || s[cnt] =='\t')
    {
        cnt++;
    }
    printf("\n%s", s);
    printf("\n%d", cnt);
    if(cnt !=0)
    {
        int i = 0;
        while(s[i + cnt] != '\0')
        {
            s[i] = s[i+cnt];
            i++;
        }
        s[i] = '\0';
    }
    printf("\n%s", s);
    printf("\nNew line \n");
    char s1[] = "This is the way.    \n\n  \t  ";
    printf("\n%d", strlen(s1));
    int len = strlen(s1);
    int end = len-1;
    while(end > 0)
    {
        if(s[end] == '\0' || s[end] == '\n' || s[end] == '\t')
        {
            end--;
        }
        else break;
    }
    s[end] = '\0';
    printf("\nAfter trim : %s", s1);
    return 0;


}
