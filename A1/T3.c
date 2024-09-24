#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void bit_represent(int i) {
    int lim = i;

    int num = -126;
    int num_comp = 126;

    char str[i];
    char str_comp[i];
    int idx = 0;

    while (i--) {
        // Get bit value for both numbers
        int bit = (num >> i) & 0x1;
        int bit_comp = (num_comp >> i) & 0x1;
        // Convert current bits to characters
        char ch = (bit == 0) ? 48 : 49;
        char ch_comp = (bit_comp == 0) ? 48 : 49;
        // Assign both characters to their respective string
        str[idx] = ch;
        str_comp[idx] = ch_comp;
        // Proceed to next index in both str's
        idx++;
    }
    printf("Comparing %d and %d character-by-character:\n", num, num_comp);
    for (int a=0;a<lim;a++) {
        char ch1 = str[a];
        char ch2 = str_comp[a];
        printf("\n%c --- %c\n", ch1, ch2);
    }
    printf("\nWe observe that %d is the inverse of all the bits in %d, added +1.\n", num, num_comp);
    printf("From this, we can deduce that the computer stores negative numbers in thet two's complement representation.\n");
}

int main(int argc, char const *argv[])
{   
    /* Task 3 (a) */
    printf("\nT3 (a)\n\n");
    // An 'int' type object contains 4 bytes (16 bits) to store a single integer.
    // Making a list of length N = 16 allocates 4 * 16 = 64 bytes of memory.
    int N = 16;
    int *nums = (int*)malloc(sizeof(int)*N);
    for (int i=0;i<N;i++) {
        nums[i] = i;
        printf("%d ",nums[i]);
    }
    printf("\n");

    /* Task 3 (b) */
    printf("\nT3 (b)\n\n");
    int hex_num = 0x04030201;
    int byte_size = sizeof(hex_num);
    printf("The hexadecimal number 0x%x (%d in decimal) takes up %d bytes of memory space.\n",hex_num, hex_num, byte_size);
    int i = byte_size * CHAR_BIT;
    while (i--) {
        printf ("%d ", (hex_num >> i) & 0x1);
    }
    printf("\nFrom the order of bytes, we can conclude that the byte arrangement is in Big Endian since the most significant byte of integer came in the 1st entry.\n");

    /* Task 3 (c) */
    printf("\nT3 (c)\n\n");
    bit_represent(byte_size * CHAR_BIT);
    printf("\n(End of Task 3)\n\n");
}