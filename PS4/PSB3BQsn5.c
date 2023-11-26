#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAXNO 999
void special_number(int aNo);

int main()
{
    int theNo;
    printf("\nEnter a 3 digit number : ");
    scanf("%d", &theNo);
    printf("\nThe number entered is : %d", theNo);
    printf("\n");
    special_number(theNo);
    return 0;
}

void special_number(int aNo)
{
    int rtDig1, rtDig2, rtDig3 = 0;
    int theNo = aNo;
    rtDig1 = theNo % 10;
    theNo = theNo / 10;
    rtDig2 = theNo % 10;
    theNo = theNo / 10;
    rtDig3 = theNo % 10;
    theNo = theNo / 10;
    if (rtDig1 == (rtDig3 + rtDig2))
    {
        printf("\n%d is a Special number ", aNo);
    }
    else
    {
        printf("\n%d is Not a Special number ", aNo);
    }
}
