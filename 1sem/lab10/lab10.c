#include <stdio.h>

int main () {
	int n, a, summ = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		summ += a;
	}
	printf("%d\n", summ);
	return 0;
}
