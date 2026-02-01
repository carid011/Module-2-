#include <stdio.h>

void to_base_n(unsigned int num, unsigned int base);

int main(void)
{
    unsigned int number, base;

    printf("Enter a positive integer: ");
    scanf("%u", &number);

    printf("Enter a base (2–16): ");
    scanf("%u", &base);

    if (base < 2 || base > 16)
    {
        printf("Error: Base must be between 2 and 16.\n");
        return 1;
    }

    if (base == 8)
        printf("Octal: 0");
    else if (base == 16)
        printf("Hexadecimal: 0x");
    else
        printf("Base %u: ", base);

    to_base_n(number, base);
    printf("\n");

    return 0;
}

void to_base_n(unsigned int num, unsigned int base)
{
    char digits[] = "0123456789ABCDEF";

    if (num >= base)
        to_base_n(num / base, base);

    putchar(digits[num % base]);
}
