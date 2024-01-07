#include "stdio.h"
#include "stdlib.h"
#define B 1
#define K 2
#define X 3

int main() {
    int d[8][8] = {0};
    int pB[2] = {2,2}, pK[2] = {5,5};
    d[pB[0]][pB[1]] = B;
    d[pK[0]][pK[1]] = K;

    for (int l = 0; l < 64; ++l) {
        int i = l/8, j = l % 8;

        if ((i == pB[0] && j == pB[1]) ||
            (i == pK[0] && j == pK[1]))
            continue;

        // b (b-->(i,j); k (K-->(i,j)) bk (b-->K)
        int b[2] = {i - pB[0], j - pB[1]},
            k[2] = {i - pK[0], j - pK[1]},
            bk[2] = {pK[0] - pB[0], pK[1] - pB[1]};

        if (abs(k[0] * k[1]) == 2) d[i][j] = X;
        /* vector product [A,B] = AxBy - AyBx;
         * equal union of parallel vectors
         * (A,B) = AxBx + AyBy > 0 one way
         * A = bk, B = b
         */
        if (abs(b[0]) ==  abs(b[1])) {
            int vecProd = k[0] * b[0] - k[1] * b[1],
                dotProd = k[0] * b[0] + k[1] * b[1];
            int lb = abs(b[0]) + abs(b[1]),
                // lk = abs(k[0]) + abs(b[1]);
                lk = abs(bk[0]) + abs(bk[1]);
            int flag = (vecProd == 0) &&
                    (dotProd > 0) &&
                    lb > lk;
            if (!flag)
                d[i][j] = X;
        }
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            printf("%c  ",
                   d[i][j] == B ? 'B' :
                   d[i][j] == K ? 'K' :
                   d[i][j] == X ? 'X' :
                   (i+j) % 2 ? '.' : ' ');
        }
        printf("\n");
    }

    return 0;
}