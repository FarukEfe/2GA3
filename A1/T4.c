#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define SIGN_BIT 1
#define BIASED_EXPONENT 3
#define MANTISSA 4

// TASK 4.b
char toFloat(float f, int silent) {

    // Extract decimal as positive
    float decimal = (f - (int)f)*((f >= 0) ? 1 : -1);
    // Add 128 to final (for last bit value) in case it's negative
    float final = 0; final = final + ((f >= 0)) ? 0 : 128;
    // Add carry in each step from decimal to final
    // It's important to note that we're assuming that the final representation will be in 8-bit integer binary,
    // which we're directly converting to decimal in each step. This way we can use the decimal final to
    // get ASCII character.
    for (int i=0;i<MANTISSA;i++) {
        // Avoid unnecessary iterations
        if (decimal == 0) {
            break;
        }
        // Multiply decimal for carry
        float res = decimal * 2;
        // Current step for decimal
        double step = pow(2,i);
        // See if carry is 0 or 1
        int carry = (res >= 1);
        // Calculate addition
        float addition = (step)*(carry);
        //printf("%.4f -- %d -- %f /// ", decimal, carry, addition);
        // Make final addition and decimal update
        final = final + addition;
        decimal = res - (int)res;
    }
    // It doesn't matter if we convert the integer part of f to binary, since we'll use it for the ASCII
    // We don't need to compute binary only to recompute back to its old self, just add it up.
    // We've already accounted for the negative, so always take positive value.
    final += (int)abs(f);
    printf("\n%f\n",final);
    // Assign final value to character
    char c = final;
    // If final value is out of ASCII range of 0 - 256, then display message and default to '0'.
    if (final < 0 || final > 255) {
        printf((silent == 1) ? "" : "Value out of ASCII range, defaulting to 0 as placeholder character...\n");
        return '0';
    } else if ((int)c < 0) {
        // Take precaution against multi-character character constant for unassigned ASCII characters
        printf((silent == 1) ? "" : "Couldn't find a match with associated ascii, defaulting to 0...\n");
        return '0';
    }
    // If no errors are apparent, return the computed character.
    return c;
}

// TASK 4.c
void displayBits(char c) {
    unsigned int ascii = c;
    printf("Char: '%c' -- ASCII: %d -- Binary: ", c, ascii);

    int i = sizeof(c) * CHAR_BIT;
    // Convert ascii to bit according to the size of character
    while (i--) {
        printf ("%d ", (ascii >> i) & 0x1);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{   
    // ASCII results with unassigned characters are meant to default to '0' as a character
    float tests[10] = {
        51.50, 0, 86.35, 43.25, 82.046, 62.59, 29.368, -34, -54.46, -300.569
    };
    for (int i=0;i<10;i++) {
        float item = tests[i];
        char c = toFloat(item,1);
        displayBits(c);
    }
    return 1;
}
