
#include "operators.h"

#include "messages.h"
#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef double (*binary_operator_fn)(double lhs, double rhs);

typedef double (*unary_operator_fn)(double x);

bool apply_binary_operator(binary_operator_fn op) {
    double x;
    double y;
    if (stack_size > 1) {
        stack_pop(&x);
        stack_pop(&y);
        double input = op(y, x);
        stack_push(input);
        return true;
    } else {
        fprintf(stderr, "%s", ERROR_BINARY_OPERATOR);
        return false;
    }
}

bool apply_unary_operator(unary_operator_fn op) {
    if (stack_size < 1) {
        fprintf(stderr, "%s", ERROR_UNARY_OPERATOR);
        return false;
    }
    double x;
    assert(stack_pop(&x));
    double result = op(x);
    assert(stack_push(result));
    return true;
}

double operator_add(double lhs, double rhs) {
    double a;
    a = lhs + rhs;
    return a;
}

double operator_div(double lhs, double rhs) {
    double d;
    d = lhs / rhs;
    return d;
}

double operator_sub(double lhs, double rhs) {
    double b;
    b = lhs - rhs;
    return b;
}

double operator_mul(double lhs, double rhs) {
    double c;
    c = lhs * rhs;
    return c;
}

bool parse_double(const char *s, double *d) {
    char *endptr;
    double result = strtod(s, &endptr);
    if (endptr != s) {
        *d = result;
        return true;
    } else {
        return false;
    }
}
