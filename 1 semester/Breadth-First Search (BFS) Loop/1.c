#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15
#define F -1
#define S -2
#define OBS -3
#define NUMO (N * N * 0.4)

void printField(int a[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == S)
                printf("  S");
            else if (a[i][j] == F)
                printf("  F");
            else if (a[i][j] == OBS)
                printf("  *");
            else if (a[i][j] == 0)
                printf("  .");
            else
                printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}

void initializeField(int a[N][N]) {
    srand(time(0));

    for (int k = 0; k < NUMO; k++) {
        int i = rand() % N;
        int j = rand() % N;

        if (a[i][j] == 0) {
            a[i][j] = OBS;
        } else {
            k--;
            continue;
        }
    }

    a[6][6] = S;
    a[N-2][N-1] = F;
}

int searchForF(int a[N][N]) {
    int n = 0;
    int count;
    int bf = 0;

    while (1) { // TODO
        int find_s = (n == 0 ? S : n);
        count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (a[i][j] != find_s) continue;

                if (j <= N-2 && a[i][j+1] == 0) {a[i][j+1] = n + 1; count++;}
                if (j > 0    && a[i][j-1] == 0) {a[i][j-1] = n + 1; count++;}
                if (i <= N-2 && a[i+1][j] == 0) {a[i+1][j] = n + 1; count++;}
                if (i > 0    && a[i-1][j] == 0) {a[i-1][j] = n + 1; count++;}

                if (j <= N-2 && a[i][j+1] == F) {bf = 1; break;}
                if (j > 0    && a[i][j-1] == F) {bf = 1; break;}
                if (i <= N-2 && a[i+1][j] == F) {bf = 1; break;}
                if (i > 0    && a[i-1][j] == F) {bf = 1; break;}
            }
            if (bf == 1) break;
        }
        if (bf == 1) break;
        if (count == 0) break;
        n++;
    }

    return count;
}

int main(void) {
    int a[N][N] = {0};

    initializeField(a);

    int count = searchForF(a);

    if (count == 0)
        printf("F not found\n");
    else
        printf("F found\n");

    printField(a);

    return 0;
}
