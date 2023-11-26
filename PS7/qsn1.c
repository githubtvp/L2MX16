#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 25

void testData(int aNo);

int main()
{
    int aNo;
    printf("\nEnter any decimal number :\n");
    scanf("%d", &aNo);
    testData(aNo);
    //   printf("\nTest line qsn1.");
    return 0;
}

void testData(int aNo)
{
    int theNo = aNo;
    int theRem = 0;
    int theQt = 0;
    int binNo[MAX];
    bool notFinish = true;
    int cnt = 0;
    for (int i = 0; notFinish && i < MAX; i++)
    {
        theRem = theNo % 2;
        theQt = theNo / 2;
        binNo[cnt] = theRem;
        theNo = theQt;
        cnt++;
        if (0 == theQt)
        {
            notFinish = false;
            break;
        }
    }
    for (int i = cnt - 1; i >= 0; i--)
    {
        printf("%d", binNo[i]);
    }
}
