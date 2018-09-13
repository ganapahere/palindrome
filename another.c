#include<stdio.h>

int isBitPalindrome(int x) {
    int i = 0, bit_len = sizeof(x) * 8;
    unsigned int left = 0, right = 0;

#define LSB 0x1
#define MSB 0x80000000
    while (i < bit_len / 2) {
        left = x << i & MSB;
        right = x >> i & LSB;

        if ((left == 0x0 && right == 0x0) || (left == MSB && right == LSB))
            i++;
        else
            break;
    }

    return (i == bit_len / 2) ? 1 : 0;
}

main(int argc, char **argv)
{
    unsigned int x = strtoul(argv[1], NULL, 16);

    printf("\nThe number 0x%x is%spalindrome\n", x, isBitPalindrome(x)?" ":" NOT ");
}
