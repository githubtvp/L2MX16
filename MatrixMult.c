#include <stdio.h>
int main()
{
    int matrix1[20][20], matrix2[20][20], product[20][20];
    int *p1, *p2, *prod, m, n, p, q, d, e, f;
    //have already declared the matrices as 2D arrays ... so memory already allocated
    // now we are just pointing a int pointer to these matrices 
    //i.e. to the first element location of these matrices 
    p1 = matrix1;
    p2 = matrix2;
    prod = product;
    // clrscr();
    printf("\nEnter the size (no of rows and columns) for 1st matrix :\n");
    scanf("%d%d", &m, &n);
    printf("\nEnter the size (no of rows and columns) for 2nd matrix :\n");
    scanf("%d%d", &p, &q);
    if (n == p)
    {
        printf("\n Enter the 1st matrix elements : \n");
        for (d = 0; d < m; ++d)
            for (e = 0; e < n; ++e)
                scanf("%d", (p1 + d * n + e));

        printf("\n Enter the 2nd matrix elements : \n\n");
        for (d = 0; d < p; ++d)
            for (e = 0; e < q; ++e)
                scanf("%d", (p2 + d * q + e));

        printf("\nThe given 1st Matrix is . . . \n\n");
        for (d = 0; d < m; ++d)
        {
            for (e = 0; e < n; ++e)
                printf("\t %d", *(p1 + d * n + e));
            printf("\n\n");
        }
        printf("\nThe given 2nd Matrix is . . . \n\n");
        for (d = 0; d < p; ++d)
        {
            for (e = 0; e < q; ++e)
                printf("\t %d", *(p2 + d * q + e));
            printf("\n\n");
        }

        //initializing product matrix
        for (d = 0; d < m; ++d)
            for (e = 0; e < q; ++e)
                *(prod + d * q + e) = 0;


        printf("\nThe product Matrix is . . . \n\n");
        for (d = 0; d < m; ++d)
        {
            for (e = 0; e < q; ++e)
                printf("\t %d", *(prod + d * q + e));
            printf("\n\n");
        }

        
        for (d = 0; d < m; ++d)     // m x n
            for (e = 0; e < q; ++e) // p x q
                for (f = 0; f < n; ++f)
                    *(prod + d * q + e) += *(p1 + d * n + f) * *(p2 + f * q + e);
        printf("\n\nThe Product of two matrices using Pointer is . . . \n\n");
        for (d = 0; d < m; ++d)
        {
            for (e = 0; e < q; ++e)
                printf("\t %d", *(prod + d * q + e));
            printf("\n\n");
        }
    }
    else
        printf("\nThe Matrix sizes are not compatible for multiplication !!");
   // getchar();
    return 0;
}
