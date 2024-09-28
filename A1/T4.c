#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGN_BIT 1
#define BIASED_EXPONENT 3
#define MANTISSA 4

int convert_b2(int i) {
    return 0;
}

char toFloat(float f) {

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
    // If final value is out of ASCII range of 0 - 256, then display message and default to '0'.
    if (final < 0 || final > 256) {
        printf("Value out of ASCII range, defaulting to 0 as placeholder character...\n");
        return '0';
    }
    char c = final;
    return c;
}

int main(int argc, char const *argv[])
{   
    float myNum = 52.38;

    char c = toFloat(myNum);
    printf("%c\n",c);
    return 1;
}
