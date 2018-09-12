#include<stdio.h>
#include<string.h>
#define DEBUG
#ifdef DEBUG
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')
#endif
main(int argc, char **argv)
{
    unsigned char number;
    int size = sizeof(unsigned char) * 8, i = 0;

    if (strstr(argv[1], "0x"))
        number = strtoul(argv[1], NULL, 16);
    else
        number = strtoul(argv[1], NULL, 10);

#ifdef DEBUG
    printf("\nargv[0] = %s\n", argv[1]);
#endif
    printf("\nnumber = %u\n", number);

    while(i < size / 2) {
#ifdef DEBUG
        printf("\n%d: 0x%x == 0x%x : 0x%x == 0x%x\n", i, number >> i, number << i, number >> i & 0x01, number << i & 0x80);
        printf(BYTE_TO_BINARY_PATTERN" == "BYTE_TO_BINARY_PATTERN,
               BYTE_TO_BINARY(number >> i), BYTE_TO_BINARY(number << i));
        printf("\n");
        printf(BYTE_TO_BINARY_PATTERN" == "BYTE_TO_BINARY_PATTERN,
               BYTE_TO_BINARY(number >> i & 0x01), BYTE_TO_BINARY(number << i & 0x80));
        printf("\n");
#endif
        if ((((number >> i & 0x01) == 0x01) && ((number << i & 0x80) == 0x80)) ||
            (((number << i & 0x80) == 0x00) && ((number >> i & 0x01) == 0x00)))
            i++;
        else
            break;
    }

    if (i >= size/2)
        printf("\nnumber is palindrome!\n");
    else
        printf("\nnumber is NOT palindrome!\n");
}
