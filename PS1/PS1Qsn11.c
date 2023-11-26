#include <stdio.h>

#define MAXSTARS 5

void doWhileLoop(int mStars);
void printStars(int maxStars);
void printBlank(int maxBlank);

int main()
{
  int maxStars = MAXSTARS;
  doWhileLoop(maxStars);
  printf("\n");
  return 0;
}

void doWhileLoop(int mStars)
{
  int maxStar = mStars;
  int maxBlank = mStars -1;
  do
  {
    printBlank(maxBlank);
    printStars(maxStar);
    printf("\n");   
    maxBlank -= 1;
  } while (maxBlank >= 0);  
}

void printStars(int maxStars)
{
  for (int j = 1; j <= maxStars; j++)
  {
    printf("*");
  }
}

void printBlank(int maxBlank)
{
  for (int i = 0; i < maxBlank; i++)
  {
    printf(" ");
  }
}
