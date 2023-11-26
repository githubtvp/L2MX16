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
  int maxBlank = 0;
  do
  {
    printBlank(maxBlank);
    printStars(maxStar);
    maxStar -= 1;
    if(maxStar > 0)  printf("\n");   
    maxBlank += 2;
  } while (maxStar >= 1);

  maxStar = 1;
  do
  {   
    maxBlank -= 2;  
    printf("\n");
    printBlank(maxBlank);
    printStars(maxStar);    
    maxStar += 1;   
  } while (maxStar <= mStars);
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
