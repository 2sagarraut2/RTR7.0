#include <stdio.h>

int main(void)
{
    printf("\n\n");
    printf("Going to next Line... Using \\n Escape Sequence\n\n");

    printf("Demonstrating \t Horizontal \t tab \t using \t \\t escape sequence !!! \n\n");

    printf("\"This is a Double quoted output\" Done using \\\" \\\" Escape sequence \n\n");

    printf("\'This is a single quoted output\' Done using \\\' \\\' escape sequence\n\n");

    printf("Backspace turned to BACKSPACE\b using escape sequence \\b\n\n");

    printf("\r Demonstrating carriage return using \\r escape sequence\n");
    printf("Demonstrating \r carriage return \\r escape sequence\n");
    printf("Demonstrating carriage \r return using \\r escae sequence\n\n");

    printf("demonstrating \x41 using \\xhh escapes sequence \n\n"); // 0x41 Is the hexadecimal for for letter 'A', 'xhh' is a placeholder for x followed by 2 digits (hh), altogether forming a Hexadecimal number.
    printf("Demonstrating \102 uisng \\ooo escape sequence\n\n");   // 102 is the octal code for letter 'B'. 'ooo' is the placeholder for 3 digit forming and octal number.
    return 0;
}
