#include <stdio.h>
#include <math.h>

typedef double dbl;

dbl epsilon() {
    dbl eps = 1.0;
    while (1 + eps / 2.0 != 1)
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

dbl dichotomy(dbl (*F)(dbl), dbl a, dbl b, dbl relative_eps, dbl abs_eps) {
    dbl x = (a + b) / 2;
    if (F(a) * F(b) < 0){
        while (fabs(a - b) > fmax(relative_eps * fabs(x), abs_eps)) {
            x = (a + b) / 2;
            if (F(x) * F(a) < 0) {
                b = x;
            }
            else {
                a = x;
            }
        }
        return x;
    }
    else {
        return NAN;
    }
}

dbl iterations(dbl (*F_x)(dbl), dbl (*F_x_first_derivative)(dbl), dbl a, dbl b, dbl relative_eps, dbl abs_eps) {
    dbl x = (a + b) / 2;
    if (fabs(F_x_first_derivative(x)) < 1) {
        while (fabs(F_x(x) - x) >= fmax(relative_eps * fabs(x), abs_eps)) {
            x = F_x(x);
        }
        return x;
    }
    else {
        return NAN;
    }
}

dbl newton(dbl (*F)(dbl), dbl (*F_first_derivative)(dbl), dbl (*F_second_derivative)(dbl), dbl a, dbl b, dbl relative_eps, dbl abs_eps) {
    dbl x = (a + b / 2);
    if (fabs(F(x) * F_second_derivative(x)) < (F_first_derivative(x) * F_first_derivative(x))) {
        while (fabs(F(x) / F_first_derivative(x)) > fmax(relative_eps * fabs(x), abs_eps)) {
            x -= F(x) / F_first_derivative(x);
        }
        return x;
    }
    else {
        return NAN;
    }
}

void result(dbl d, dbl i, dbl n) {
   if (d != NAN) printf("The root obtained by the dichotomy method: %.10f\n", d);
   else printf("The dechotomy method isn't suitable\n");
   if (i != NAN) printf("The root obtained by the iterations method: %.10f\n", i);
   else printf("The iterations method isn't suitable\n");
   if (n != NAN) printf("The root obtained by the Newton's method: %.10f\n", n);
   else printf("The Newton's method isn't suitable\n");
}


int main() {
    dbl abs_eps = epsilon();
    dbl relative_eps = sqrt(abs_eps);
    dbl a2 = 1, b2 = 2;
    dbl a3 = 1, b3 = 1.5;
    dbl d1 = dichotomy(F2, a2, b2, relative_eps, abs_eps);
    dbl i1 = iterations(F2_x, F2_x_first_derivative, a2, b2, relative_eps, abs_eps);
    dbl n1 = newton(F2, F2_first_derivative, F2_second_derivative, a2, b2, relative_eps, abs_eps);
    printf("Machine epsilon for long double = %.16e\n", abs_eps);
    printf("Function cos(x) - exp(-0.5*x^2) + x - 1\n");
    result(d1, i1, n1);
    printf("\n");
    dbl d2 = dichotomy(F3, a3, b3, relative_eps, abs_eps);
    dbl i2 = iterations(F3_x, F3_x_first_derivative, a3, b3, relative_eps, abs_eps);
    dbl n2 =newton(F3, F3_first_derivative, F3_second_derivative, a3, b3, relative_eps, abs_eps);
    printf("Function 1 - x + sin(x) - ln(1 + x)\n");
    result(d2, i2, n2);
    return 0;
}
