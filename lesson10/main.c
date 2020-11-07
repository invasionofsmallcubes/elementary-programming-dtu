#include <stdio.h>
#include "stringNormalization.h"
#include "stringObfuscation.h"

int main(void) {
    const char *strNorm = stringNormalization("hello");
    printf("%s", strNorm);
    const char *strObs = stringObfuscation("hello");
    printf("%s", strObs);
}