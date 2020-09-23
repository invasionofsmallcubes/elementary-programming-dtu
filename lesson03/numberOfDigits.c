/*
So, there was no bug in the program per say but there was an issue with the type used.
You can use `limits.h` to know what are the limits on your machine.
Check the following code.

In case of UINT_MAX the limit on my machine for unsigned int is `UINT_MAX: 4294967295` whereas unsigned long is `ULONG_MAX: 18446744073709551615`

This is an example of running the code with unsigned long:
```
Enter a nonnegative integer: 18446744073709551615
The number has 20 digits
```

Check also how I changed the conversion specifiers. For example for an unsigned long is `"%lu"`. If you don't change the conversion specificer you will get a random number in the range of the specifier.

Here's the code:
*/

#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("Enter a nonnegative integer: ");
    unsigned long inputValue;
    scanf("%lu", &inputValue);
    printf("%lu", inputValue);
    int numberDoesntOverflow = inputValue <= ULONG_MAX;
    int numberIsPositive = inputValue >= 0;
    if (numberDoesntOverflow && numberIsPositive) {
        int digitsCount = 0;
        do {
            inputValue = inputValue / 10;
            digitsCount += 1;
        } while (inputValue > 0);
        printf("\nThe number has %d digits\n", digitsCount);
    } else {
        printf("Number too big\n");
        printf("ULONG_MAX is %lu\n", ULONG_MAX);
    }
}