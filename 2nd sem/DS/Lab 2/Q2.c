/*2. Write a program to implement Boolean matrix operations join, meet, and Boolean product*/

include <stdio.h>

#define SIZE 3

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void join(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = A[i][j] || B[i][j];
        }
    }
}

void meet(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = A[i][j] && B[i][j];
        }
    }
}

void booleanProduct(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] = result[i][j] || (A[i][k] && B[k][j]);
            }
        }
    }
}

int main() {
    int A[SIZE][SIZE] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 1, 0}
    };

    int B[SIZE][SIZE] = {
        {0, 1, 1},
        {1, 0, 1},
        {0, 0, 1}
    };

    int joinResult[SIZE][SIZE];
    int meetResult[SIZE][SIZE];
    int productResult[SIZE][SIZE];

    join(A, B, joinResult);
    meet(A, B, meetResult);
    booleanProduct(A, B, productResult);

    printf("Matrix A:\n");
    printMatrix(A);

    printf("Matrix B:\n");
    printMatrix(B);

    printf("Join of A and B:\n");
    printMatrix(joinResult);

    printf("Meet of A and B:\n");
    printMatrix(meetResult);

    printf("Boolean Product of A and B:\n");
    printMatrix(productResult);

    return 0;
}
