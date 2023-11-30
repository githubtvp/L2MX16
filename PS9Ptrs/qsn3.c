#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int *ptr, i=0, j=0, n = 6;
    int nos[] = {3, 5, 2, 6, 1, 4};
   /* printf("\n1. Nos are : \n");
    while(nos[i] != 0){
    printf("%d ", nos[i]);
    i++;
    }*/
    ptr = (int *)malloc(n*sizeof(int));
ptr = nos;
/*while(*(ptr+i) != 0)
{
    scanf("%d", (ptr + i));
    i++;
}
*/

for(i= 0; i <n-1; i++)
{
    for(j= i+1; j <n; j++)
    {
        if( *(ptr + i) >  *(ptr + j))
        {
           // printf("Swap ");
            int temp = 0;
            temp = *(ptr + i);
            *(ptr + i) = *(ptr + j);
            *(ptr + j) = temp;
        }

    }
}

printf("\n2. Nos are : \n");
i = 0;
while(i < n)
{
    printf("%d ", *(ptr + i));
    i++;
}


printf("\nTest line");
return 0;
}
