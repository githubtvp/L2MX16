#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 15
int main()
{
    char *ptr = (char *)malloc(MAX * sizeof(char));
    printf("Enter name : ");
    gets(ptr);
    int len=strlen(ptr);
    printf("%d", len);
    printf("\n%s", ptr);
    //intInput();
    printf("\nTestline ");
    free(ptr);
    return 0;

}

/*void intInput()
{
    int sz;
    printf("\nEnter no of elements :");
    scanf("%d", &sz);
    int *ptr1 = (int *)malloc(MAX * sizeof(int));
    printf("\nEnter the array elements :");
    for(int i = 0; i < sz; i++)
    {
        scanf("%d", ptr1+ i);
    }
    for(int i = 0; i < sz; i++)
    {
        printf("%d", *(ptr1+i));
    }
}*/

