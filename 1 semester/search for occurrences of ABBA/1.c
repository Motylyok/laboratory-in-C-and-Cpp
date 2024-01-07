/*
 * the search is carried out using a ladder (not diagonally)
 * the length of the ladder is 4
 */

#include <stdio.h>

int find_Rec(char pr_symbol, int count, int line, int column, const char matrix[8][9]) {
    if (line < 0 || line >= 8 || column < 0 || column >= 8)
        return 0;

    if (count == 4 && matrix[line][column] == 'A' && pr_symbol == 'B')
        return 1;
    if (count >= 4)
        return 0;

    const char cur_symbol = matrix[line][column];

    if ((cur_symbol == 'A' && (pr_symbol == '0' || pr_symbol == 'B')) ||
        (cur_symbol == 'B' && (pr_symbol == 'B' || pr_symbol == 'A'))) {
        const int d[4][2] = {{1,  0},
                             {0,  -1},
                             {-1, 0},
                             {0,  1}};
        int c = 0;
        for (int k = 0; k < 4; k++) {
            int ni = line + d[k][0],
                nj = column + d[k][1];
            c += find_Rec(cur_symbol, count + 1, ni, nj, matrix);
        }
        return c;
    } else
        return 0;
}

int count_word(int sample[8]) {
    char matrix[8][9];
    int count = 0;

    for (int i = 0; i < 8; ++i)
        sprintf(matrix[i], "%08X", sample[i]);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            printf("%2c", matrix[i][j]);
            count += find_Rec('0', 1, i, j, matrix);
        }
        printf("\n");
    }

    return count >> 1;
}

int main(void) {
    int sample1[8] = {-1413863686, -1146374827,
                      -1162027246,-1442185216,
                      184549376,11534336,
                      655360,179026592};

    int sample2[8] = {-1430650880, -1157627904,
                      3145728, -1442185216,
                      184549376, 11534336,
                      655360, 3840};

    printf("%d\n", count_word(sample1));
    printf("%d\n", count_word(sample2));

    return 0;
}

