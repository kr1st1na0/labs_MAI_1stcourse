#include <stdio.h>
#include <stdlib.h>

#define DBL_LOG102 (3.010299956639811952E-1)
#define INT_WIDTH (32)
#define N ((int) (DBL_LOG102 * (INT_WIDTH - 1) + 1))

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);
	if (n > -100 && n < 100) {
		printf("This number is not correct.\n");
		exit(EXIT_FAILURE);
	}
	char mas[N + 1];
	int len = snprintf(mas, N + 1, "%d", abs(n));
	int max = -1;
	for (int i = 0; i < len - 2; ++i) {
		int sum = mas[i] - '0' + mas[i+1] - '0' + mas[i+2] - '0';
		if (sum > max)
			max = sum;
	}
	printf("Max sum: %d\n", max);
	for (int i = 0; i < len - 2; ++i) {
		int sum = mas[i] - '0' + mas[i+1] - '0' + mas[i+2] - '0';
		if (sum == max)
			printf("Numbers: %d %d %d\n", mas[i] - '0', mas[i+1] - '0', mas[i+2] - '0');
	}

	return 0;
}
