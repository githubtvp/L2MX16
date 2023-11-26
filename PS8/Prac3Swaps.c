// C function to Swap strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
The function just changes local pointer variables
 and the changes are not reflected outside the function.
*/
void swap(char *str1, char *str2)
{ // output = str1 is geeks, str2 is forgeeks
    char *temp = str1;
    str1 = str2;
    str2 = temp;
}

/* Swaps strings by swapping pointers
In a function, if we want to change a pointer
(and obviously we want changes to be reflected
outside the function) then we need to pass a
pointer to the pointer.
This method cannot be applied if strings are
stored using character arrays.  */
void swap1(char **str1_ptr, char **str2_ptr)
{
    char *temp = *str1_ptr;
    *str1_ptr = *str2_ptr;
    *str2_ptr = temp;
}

/* Swaps strings by swapping data
Method 2(Swap Data) If you are using character arrays
to store strings then preferred way is
to swap the data of both arrays using strcpy to temp var.
*/
void swap2(char *str1, char *str2)
{
    printf("\nHere");
    char *temp = (char *)malloc((strlen(str2) + 1) * sizeof(char));
    strcpy(temp, str1);
    printf("\n3. Temp is %s, str2 is %s", temp, str2);
    strcpy(str1, str2);
    printf("\n4. str1 is %s, str2 is %s", str1, str2);
    strcpy(str2, temp);
    printf("\n2. Here");
    printf("\n3. str1 is %s, str2 is %s", str1, str2);

    free(temp);
}

int main()
{
    char *str1 = "geeks";
    char *str2 = "forgeeks";
    swap(str1, str2);
    printf("1. str1 is %s, str2 is %s", str1, str2);
 //   swap1(&str1, &str2);
    printf("\n2. str1 is %s, str2 is %s", str1, str2);

    swap2(str1, str2);
    printf("\n3. str1 is %s, str2 is %s", str1, str2);
    getchar();
    
    return 0;
}