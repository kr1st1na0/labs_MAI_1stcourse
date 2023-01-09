#include <stdio.h>
#include <math.h>

typedef double dbl;

dbl epsilon(dbl x) {
    dbl eps = 1.0;
    while (x + eps / 2.0 != x)
        eps /= 2.0;
    return eps;
}

dbl F2(dbl x) {
    return cos(x) - exp(-pow(x, 2) / 2) + x - 1;
}

dbl F2_x(dbl x) {
    return 1 + exp(-pow(x, 2) / 2) - cos(x);
}

dbl F2_x_first_derivative(dbl x) {
    return sin(x) - x * exp(-pow(x, 2) / 2);
}

dbl F2_first_derivative(dbl x) {
    return -sin(x) + x * exp(-pow(x, 2) / 2) + 1;
}

dbl F2_second_derivative(dbl x) {
    return -cos(x) + exp(-pow(x, 2) / 2) - pow(x,2) * exp(-pow(x, 2) / 2);
}

dbl F3(dbl x) {
    return 1 - x + sin(x) - log(1 + x);
}

dbl F3_x(dbl x) {
    return 1 + sin(x) - log(1 + x);
}

dbl F3_x_first_derivative(dbl x) {
    return cos(x) - 1/(1 + x);
}

dbl F3_first_derivative(dbl x) {
    return cos(x) - 1 - 1/(1 + x);
}

dbl F3_second_derivative(dbl x) {
    return 1/((1 + x) * (1 + x)) - sin(x);
}

void dichotomy(dbl F(dbl), dbl a, dbl b) {
    dbl x = (a + b) / 2;
    dbl eps = epsilon(x);
    if (F(a) * F(b) < 0){
        while (fabs(a - b) > eps) {
            x = (a + b) / 2;
            if (F(x) * F(a) < 0) {
                b = x;
            }
            else {
                a = x;
            }
        }
        printf("The root obtained by the dichotomy method: %.10f\n", x);
    }
    else {
        printf("The dechotomy method isn't suitable\n");
    }
}

void iterations(dbl F_x(dbl), dbl F_x_first_derivative(dbl), dbl a, dbl b) {
    dbl x = (a + b) / 2;
    dbl eps = epsilon(x);
    if (fabs(F_x_first_derivative(x)) < 1) {
        while (fabs(F_x(x) - x) >= eps) {
            x = F_x(x);
        }
        printf("The root obtained by the iterations method: %.10f\n", x);
    }
    else {
        printf("The iterations method isn't suitable\n");
    }
}

void newton(dbl F(dbl), dbl F_first_derivative(dbl), dbl F_second_derivative(dbl), dbl a, dbl b) {
    dbl x = (a + b / 2);
    dbl eps = epsilon(x);
    if (fabs(F(x) * F_second_derivative(x)) < (F_first_derivative(x) * F_first_derivative(x))) {
        while (fabs(F(x) / F_first_derivative(x)) > eps) {
            x -= F(x) / F_first_derivative(x);
        }
        printf("The root obtained by the Newton's method: %.10f\n", x);
    }
    else {
        printf("The Newton's method isn't suitable\n");
    }
}

int main() {
    dbl a2 = 1, b2 = 2;
    dbl a3 = 1, b3 = 1.5;
    printf("Function cos(x) - exp(-0.5*x^2) + x - 1\n");
    dichotomy(F2, a2, b2);
    iterations(F2_x, F2_x_first_derivative, a2, b2);
    newton(F2, F2_first_derivative, F2_second_derivative, a2, b2);
    printf("\n");
    printf("Function 1 - x + sin(x) - ln(1 + x)\n");
    dichotomy(F3, a3, b3);
    iterations(F3_x, F3_x_first_derivative, a3, b3);
    newton(F3, F3_first_derivative, F3_second_derivative, a3, b3);
    return 0;
}
