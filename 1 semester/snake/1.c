#include <stdio.h>

void fillMatrix(int N, int matrix[N][N]) {
    int value = 0;

    for (int diag = 0; diag < 2 * N - 1; ++diag) {
        int start_row, start_col;

        if (diag < N) {
            start_row = 0;
            start_col = diag;
        } else {
            start_row = diag - N + 1;
            start_col = N - 1;
        }

        int row = start_row;
        int col = start_col;

        while (row < N && col >= 0) {
            if ((N % 2 == 0 && diag % 2 == 0) || (N % 2 != 0 && diag % 2 != 0))
                matrix[N % 2 == 0 ? row : col][N % 2 == 0 ? col : row] = ++value;
            else
                matrix[N % 2 == 0 ? col : row][N % 2 == 0 ? row : col] = ++value;

            ++row;--col;
        }
    }
}

void printMatrix(int N, int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) printf("%2d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void) {

    for (int N = 4; N <= 6; ++N) {
        int matrix[N][N];

        fillMatrix(N, matrix);

        printf("N = %d:\n", N);
        printMatrix(N, matrix);
        printf("\n");
    }

    return 0;
}


