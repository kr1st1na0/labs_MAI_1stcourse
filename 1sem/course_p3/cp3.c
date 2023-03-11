#include <stdio.h>
#include <math.h>

#define MAX_ITER 100

typedef double dbl;
typedef long double ldbl;

const ldbl k = 10e2;

dbl epsilon() {
    ldbl eps = 1.0;
    while (1 + eps / 2.0 != 1)
        eps /= 2.0;
    return eps;
}

ldbl function(ldbl x) {
    return (logl((1 + x) / ( 1 - x)));
}

ldbl Taylor(dbl x, int n) {
    ldbl sum = 0;
    for (ldbl i = 0.0; i <= n; i++) {
      ldbl p = 2 * i + 1;
      sum = sum + pow(x,p) * (2 / p);
    }
    return sum;
}

int main() {
    dbl abs_eps = epsilon();
    dbl relative_eps = sqrt(abs_eps);
    ldbl a = 0.0, b = 0.5, x = 0.0, result;
    int n, t;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    printf("Machine epsilon for long double = %.16e\n", abs_eps);
    ldbl step = (b - a) / n;
    printf("Taylor series value table for function f(x) = ln((1+x)/(1-x))\n");
    printf(" ________________________________________________________________________ \n");
    printf("|    x    |       sum of row       |         function       |   iter    |\n");
    printf("|_________|________________________|________________________|___________|\n");
    for (ldbl x = a; x <= b; x += step) {
      for (n = 0; n < MAX_ITER; n++) {
        result = Taylor(x, n);
        if (fabs(result) <= fmax(relative_eps * fabs(result), abs_eps)) {
          break;
        }
      }
      printf("| %.5Lf | %.20Lf | %.20Lf |   %d\t|\n", x, result, function(x), n);
      result = 0.0;
    }
    printf("|_________|________________________|________________________|___________|\n");
    return 0;
}
