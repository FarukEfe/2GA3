#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    /* code */
    int a = 5;
    int i = sizeof(int) * CHAR_BIT;
    while (i--) {
        printf("%d ", (a >> i) & 0x1);
    }
    printf("\n");
    return 0;
}
