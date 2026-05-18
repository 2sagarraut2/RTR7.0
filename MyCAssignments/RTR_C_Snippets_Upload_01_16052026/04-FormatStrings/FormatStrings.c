#include <stdio.h>

int main(void)
{
    printf("\n\n");

    printf("*********************************************\n\n");

    printf("Hello World!\n\n");

    // SSR - Sagar Sambhaji Raut
    int SSR_number = 13;

    printf("Integer Decimal value of SSR_number = %d \n", SSR_number);
    printf("Integer Octal value of SSR_number = %o\n", SSR_number);
    printf("integer Hexadecimal value of SSR_number (Hexadecimal letters in lower case) = %x\n", SSR_number);
    printf("integer hexadecimal value of SSR_number = (Hexadecimal Letters in Upper case) = %X\n\n", SSR_number);

    char SSR_ch = 'A';
    printf("Character SSR_ch = %c\n", SSR_ch);
    char SSR_str[] = "Astromedicomp's RTR7 Render group";
    printf("String SSR_str = %s\n\n", SSR_str);

    long SSR_long_number = 38674657L;
    printf("Long Integer = %ld\n\n", SSR_long_number);

    unsigned int SSR_unsigned_number = 7;
    printf("Long Integer SSR_unsigned_number = %u\n\n", SSR_unsigned_number);

    float SSR_f_number = 3034.345435f;
    printf("Floating point number with just %%f SSR_f_num = %f\n", SSR_f_number);
    printf("Floating point number with %%4.2f SSR_f_num = %4.2f\n", SSR_f_number);
    printf("Floating point number with %%6.5f SSR_f_num = %6.5f\n", SSR_f_number);

    double SSR_d_pi = 3.12345467898765456744;
    printf("Double precision floating point number without exponential = %g\n", SSR_d_pi);
    printf("Double precision floating point number with exponential (Lower case) = %e\n", SSR_d_pi);
    printf("Double precision floating point number with exponential (Upper case) = %E\n", SSR_d_pi);
    printf("Double hexadecimal value of SSR_d_pi (Hexadecimal letters in Lower case) = %a\n", SSR_d_pi);
    printf("Double hexadecimal value of SSR_d_pi (Hexadecimal letters in Upper case) = %A\n", SSR_d_pi);

    printf("*************************************************\n\n");

    return 0;
}
