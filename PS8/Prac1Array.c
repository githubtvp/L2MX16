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
  char arr[3][10] = {"Geek1",
                     "Geeks2", "Geekfor3"};
  printf("String array Elements are:\n");

  for (int i = 0; i < 3; i++)
  {
    // printf("%s\n", arr[i]);
  }
  PrintArray(arr, 3);
  return 0;
}

void PrintArray(char arr[][10], int n)
{
  printf("\n");
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