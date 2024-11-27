#include "mathlib.h"
#include "messages.h"
#include "operators.h"
#include "stack.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    printf("Abs(5.0): %f\n", Abs(5.0));
    printf("Sqrt(16.0): %f\n", Sqrt(16.0));
    printf("Sin(0.0): %f\n", Sin(0.0));
    printf("Cos(0.0): %f\n", Cos(0.0));
    printf("Tan(pi/4): %f\n", Tan(M_PI / 4));
    printf("operator_add(2.0, 3.0): %f\n", operator_add(2.0, 3.0));
    printf("operator_sub(5.0, 3.0): %f\n", operator_sub(5.0, 3.0));
    printf("operator_mul(2.0, 3.0): %f\n", operator_mul(2.0, 3.0));
    printf("operator_div(6.0, 3.0): %f\n", operator_div(6.0, 3.0));

    return 0;
}
