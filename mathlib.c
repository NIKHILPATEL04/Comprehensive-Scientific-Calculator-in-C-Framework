#include "mathlib.h"

#include "stack.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double Abs(double x) {
    double a;
    if (x < 0) {
        a = (x / -1);
    } else {
        a = x;
    }
    return a;
}

double Sqrt(double x) {
    if (x < 0) {
        return nan("nan");
    }
    double new = 1.0;
    double old = 0.0;
    while (Abs(old - new) > EPSILON) {
        old = new;
        new = 0.5 * (old + (x / old));
    }
    return new;
}

double Sin(double x) {
    while (x < 0) {
        x = x + 2 * M_PI;
    }
    while (x > 2 * M_PI) {
        x = x - 2 * M_PI;
    }
    double output = x;
    double input = x;
    double xx = x * x;
    int a = 1;
    while (fabs(input) > EPSILON) {
        input *= (-1) * xx / ((2 * a) * (2 * a + 1));
        output = output + input;
        a = a + 1;
    }

    return output;
}

double Cos(double x) {
    while (x < 0) {
        x = x + 2 * M_PI;
    }
    while (x > 2 * M_PI) {
        x = x - 2 * M_PI;
    }
    double output = 1.0;
    double input = 1.0;
    double xx = x * x;

    int b = 1;
    while (fabs(input) > EPSILON) {
        input = input * (-1) * xx / ((2 * b - 1) * (2 * b));
        output = output + input;
        b = b + 1;
    }

    return output;
}
double Tan(double x) {
    x = Sin(x) / Cos(x);
    return x;
}
