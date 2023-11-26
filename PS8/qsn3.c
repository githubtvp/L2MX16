#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void popArr(int *ptr, int sz);
void findEl(int *ptr, int sz, int el);

int main()
{
    int sz, el;
    int *ptr;
    printf("\nEnter number of elements :  ");
    scanf("%d", &sz);
    ptr = (int*)malloc(sizeof(int) *sz);
    printf("\nEnter the elements :  ");
    popArr(ptr, sz);
    printf("\nEnter the element  to find : ");
    scanf("%d", &el);
    findEl(ptr, sz, el);

    printf("\nTest line PS8Qsn3");
    return 0;
}

void findEl(int *ptr, int sz, int el)
{
    bool notFound = true;
    for(int i = 0; i <sz; i++)
    {
        if(el == *(ptr+i))
        {
            notFound = false;
            printf("\nElement found at %d :", i);
            break;
        }
    }
    if(notFound)
    {
         printf("\nElement Not found!");
    }
}

void popArr(int *ptr, int sz)
{
    for(int i = 0; i < sz; i++)
    {
        scanf("%d", (ptr+i));
    }
    for(int i = 0; i < sz; i++)
    {
        printf("%d  ", *(ptr+i));
    }
}
