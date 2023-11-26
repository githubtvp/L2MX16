#include <stdio.h>

// Function to rotate matrix in-place anti-clockwise by 90 degrees
void rotateAntiClockwise(int mat[][100], int m, int n) {
    for (int layer = 0; layer < (m + 1) / 2; layer++) {
        int start = layer;
        int endRow = m - 1 - layer;
        int endCol = n - 1 - layer;

        for (int i = start; i < endRow; i++) {
            int temp = mat[i][start];
            mat[i][start] = mat[endRow][i];
            mat[endRow][i] = mat[endRow - i + start][endCol];
            mat[endRow - i + start][endCol] = mat[start][endCol - i + start];
            mat[start][endCol - i + start] = temp;
        }
    }
}

// Function to print the matrix
void printMatrix(int mat[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Driver code
int main() {
    int m, n;
    printf("Enter the value of m for an m x n matrix: ");
    scanf("%d", &m);
    printf("Enter the value of n for an m x n matrix: ");
    scanf("%d", &n);

    int mat[100][100];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Matrix before rotation:\n");
    printMatrix(mat, m, n);

    rotateAntiClockwise(mat, m, n);

    printf("Matrix after rotating anti-clockwise 90 degrees in-place:\n");
    printMatrix(mat, n, m);

    return 0;
}
