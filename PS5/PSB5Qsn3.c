#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchForFirstNo(char *ch, int aSz, int *digStPosn); //, char *ch2, int st, int len))
void getSubStr(char *ch, int aSz, char *ch2, int st, int len);

int main()
{
    char str[50]; // = "My no is 9876514567";
    char subStr[50];
    printf("\nEnter the string with the Mobile No at the end :\n");
    fgets(str, 50, stdin);
    // puts(str);
    int theStrLen = strlen(str);
    int lenSubStr = 10;
    int digStPosn = 0;
    searchForFirstNo(str, theStrLen, &digStPosn);
    getSubStr(str, theStrLen, subStr, digStPosn, lenSubStr);
    printf("\nMobile Number : %s", subStr);
    //  printf("\nTest line");
    return 0;
}
void searchForFirstNo(char *ch, int aSz, int *digStPosn)
{
    int thePosn;
    for (int i = 0; i < aSz; i++)
    {
        if (ch[i] != ' ' && ch[i] < 65)
        {
            *digStPosn = i;
            //  printf("\n%c, at %d", ch[i], *digStPosn);
            break;
        }
    }
}

void getSubStr(char *ch, int aSz, char *ch2, int st, int len)
{
    if (st >= 0 && (st + len) <= aSz)
    {
        strncpy(ch2, (ch + st), len);
    }
    ch2[len] = '\0';
}
