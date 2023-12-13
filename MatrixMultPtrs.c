#include <stdio.h>
#include <stdlib.h>

int **allocateMemForArray(int mRows, int nCols);
int main()
{
   // int matrix1[20][20], matrix2[20][20], product[20][20];
  //  int *p1, *p2, *prod;   
    //have already declared the matrices as 2D arrays ... so memory already allocated
    // now we are just pointing a int pointer to these matrices 
    //i.e. to the first element location of these matrices 
  //  p1 = matrix1;
  //  p2 = matrix2;
  //  prod = product;
    int  m, n, p, q, d, e, f;
    printf("\nEnter the size (no of rows and columns) for 1st matrix :\n");
    scanf("%d%d", &m, &n);
    printf("\nEnter the size (no of rows and columns) for 2nd matrix :\n");
    scanf("%d%d", &p, &q);
    int **mx1, **mx2, **mx3;
    mx1 = allocateMemForArray(m, n);
    mx2 = allocateMemForArray(p, q);
    mx3 = allocateMemForArray(m, q);

    if (n == p)
    {
        printf("\n Enter the 1st matrix elements : \n");
        for (d = 0; d < m; ++d)
            for (e = 0; e < n; ++e)
                scanf("%d", &mx1[d][e]);

        printf("\n Enter the 2nd matrix elements : \n\n");
        for (d = 0; d < p; ++d)
            for (e = 0; e < q; ++e)
                scanf("%d", &mx2[d][e]);

        printf("\nThe given 1st Matrix is . . . \n\n");
        for (d = 0; d < m; ++d)
        {
            for (e = 0; e < n; ++e)
                printf("\t %d", mx1[d][e]);
            printf("\n\n");
        }
        printf("\nThe given 2nd Matrix is . . . \n\n");
        for (d = 0; d < p; ++d)
        {
            for (e = 0; e < q; ++e)
                printf("\t %d", mx2[d][e]);
            printf("\n\n");
        }

        //initializing product matrix
        for (d = 0; d < m; ++d)
            for (e = 0; e < q; ++e)
                mx3[d][e] = 0;


        printf("\nThe product Matrix is . . . \n\n");
        for (d = 0; d < m; ++d)
        {
            for (e = 0; e < q; ++e)
                printf("\t %d", mx3[d][e]);
            printf("\n\n");
        }

        //multiplying elements El += row X col
        for (d = 0; d < m; ++d)     // m x n
            for (e = 0; e < q; ++e) // p x q
                for (f = 0; f < n; ++f)
                    mx3[d][e] += mx1[d][f] * mx2[f][e]; //*(p1 + d * n + f) * *(p2 + f * q + e);
        printf("\n\nThe Product of two matrices using Pointer is . . . \n\n");
        for (d = 0; d < m; ++d)
        {
            for (e = 0; e < q; ++e)
                printf("\t %d", mx3[d][e]);
            printf("\n\n");
        }
    }
    else
        printf("\nThe Matrix sizes are not compatible for multiplication !!");
   // getchar();
    return 0;
}


int **allocateMemForArray(int mRows, int nCols)
{
    int **mx;
    mx = (int**)malloc(mRows*sizeof(int*));
    for(int i = 0; i < mRows; i++)
    {
        mx [i] = (int*)malloc(nCols * sizeof(int));
    }
    return mx;
}