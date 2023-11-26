#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
Array of Strings in C
In C programming String is a 1-D array of characters
and is defined as an array of characters.
But an array of strings in C is a two-dimensional
array of character types.
Each String is terminated with a null character (\0).
It is an application of a 2d array.

Syntax:

char var_name[r] = {list of string};
Here,
var_name is the name of the variable in C.
r is the maximum number of string values that can be stored in a string array.
c is the maximum number of character values that can be stored in each string array.
*/
// C Program to print Array
// of strings

void PrintArray(char arr[][10], int n);

int main()
{
  char arr[3][10] = {"Geek",
                     "Geeks", "Geekfor"};
  printf("String array Elements are:\n");

  for (int i = 0; i < 3; i++)
  {
    // printf("%s\n", arr[i]);
  }
  // PrintArray(arr, 3) ;

  char *str[4] = {"name1", "namemore2", "na3", "name45"}; // an array of 4 ptrs
                                                          // the length of each word not limited here, no need to define word length like 10

  int i = 0;
  for (i = 0; i < 4; i++)
  {
    int j = 0;
    while (*(str[i] + j) != '\0')
    {
      printf("%c", *(str[i] + j));
      j++;
    }
    printf("\n");
  }

  char(*ptr)[10]; // pointer to an array of 10 char
  ptr = arr;      // from arr[3][10] above
  for (int i = 0; i < 3; i++)
  {
    printf("%s \n", ptr[i]); // notice NO *ptr[i]
  }
  /*
  Notice difference between
  char *str[4] = {"name1", "namemore2", "na3", "name45"};//an array of 4 ptrs
  AND
  char (*ptr)[10]; // pointer to an array of 10 char

  */

  char **ptr2 = NULL; // pointer to a pointer
  ptr2 = str;
  for (int row = 0; row < 4; row++)
  {
    printf("%s\n", ptr2[row]);
    // printf("%s\n", ptr2++);//does not work = error
  }

  return 0;
}



void PrintArray(char arr[][10], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%s ", arr[i]);
  }
}
/*
Invalid Operations in Arrays of Strings
We can’t directly change or assign the values
to an array of strings in C.
Example:
char arr[3][10] = {"Geek", "Geeks", "Geekfor"};
Here, arr[0] = “GFG”; // This will give an Error that says assignment to expression with an array type.

To change values we can use strcpy() function in C

strcpy(arr[0],"GFG"); // This will copy the value to the arr[0].

*/