#include <stdio.h>

int max_cyclic_shift(int dec) {
    int original = dec;
    int bit_position = 0;

    while (dec != 1) {
        dec >>= 1;
        bit_position++;
    }

    for (int count = 1; dec != original; count++) {
        int last_bit = original & 1;
        original = (original >> 1) | (last_bit << bit_position);
    }

    return bit_position + 1;
}

int main(void) {
    int dec;
    printf("Enter your number: ");
    scanf("%d", &dec);

    int result = max_cyclic_shift(dec);
    printf("%d\n", result);

    return 0;
}

