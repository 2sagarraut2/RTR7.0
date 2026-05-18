#include <stdio.h>

#define MY_PI 3.1415926535897932

#define AMC_STRING "Astromedicomp RTR"

// If first constant is not assigned A value, It is assumed to be 0 i.e.: 'SUNDAY' will be 0

// And The rest rest of the constants are assigned consecutive integer values from 0 onwards i.e.: Monday wil be 1, 'TUESDAY' will be 2, and so on...

// unnamed enums
enum
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

enum
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    NOVEMBER,
    DECEMBER
};

// NAMED enums
enum Numbers
{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE = 5,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN
};

enum boolean
{
    TRUE = 1,
    FALSE = 0
};

int main(void)
{
    // local constant declarations
    const double epsilon = 0.000001;

    printf("\n\n");
    printf("local constant epsilon = %lf\n\n", epsilon);

    printf("Day number of Sunday is = %d\n", SUNDAY);
    printf("Day number of Monday is = %d\n", MONDAY);
    printf("Day number of Tuesday is = %d\n", TUESDAY);
    printf("Day number of Wednesda is = %d\n", WEDNESDAY);
    printf("Day number of Thursday is = %d\n", THURSDAY);
    printf("Day number of Friday is = %d\n", FRIDAY);
    printf("Day number of Saturday is = %d\n", SATURDAY);

    printf("ONE is Enum number = %d\n", ONE);
    printf("TWO is Enum number = %d\n", TWO);
    printf("THREE is Enum number = %d\n", THREE);
    printf("FOUR is Enum number = %d\n", FOUR);
    printf("FIVE is Enum number = %d\n", FIVE);
    printf("SIX is Enum number = %d\n", SIX);
    printf("SEVEN is Enum number = %d\n", SEVEN);
    printf("EIGHT is Enum number = %d\n", EIGHT);
    printf("NINE is Enum number = %d\n", NINE);
    printf("TEN is Enum number = %d\n", TEN);

    printf("Month number of JANUARY is %d\n", JANUARY);
    printf("Month number of FEBRUARY is %d\n", FEBRUARY);
    printf("Month number of MARCH is %d\n", MARCH);
    printf("Month number of APRIL is %d\n", APRIL);
    printf("Month number of MAY is %d\n", MAY);
    printf("Month number of JUNE is %d\n", JUNE);
    printf("Month number of JULY is %d\n", JULY);
    printf("Month number of AUGUST is %d\n", AUGUST);
    printf("Month number of SEPTEMBER is %d\n", SEPTEMBER);
    printf("Month number of NOVEMBER is %d\n", NOVEMBER);
    printf("Month number of DECEMBER is %d\n", DECEMBER);

    printf("value of TRUE is = %d\n", TRUE);
    printf("value of false is = %d\n\n", FALSE);

    printf("MY_PI macro value is %.10lf\n\n", MY_PI);
    printf("Area of circle of radius 2 units = %f\n\n", (MY_PI * 2.0f * 2.0f)); // area of cicle = 2*pi*r*r
    printf("\n\n");

    printf(AMC_STRING);
    printf("\n\n");
    printf("AMC String is : %s\n", AMC_STRING);
    printf("\n\n");
    return 0;
}
