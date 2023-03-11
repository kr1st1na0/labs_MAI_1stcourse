#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, len;
	scanf("%d", &n);
	if (n > -100 && n < 100) {
		printf("This number is not correct.\n");
	}
	else {
		if (n < 0) {
			n = abs(n);
		}
		int n1 = n;
		while (n1 > 0) {
			len++;
			n1 /= 10;
		}
		int mas[len];
		int k = 0;
		while (n > 0) {
			mas[k] = n%10;
			n /= 10;
			k += 1;
		}
		for (int i = 0; i < len/2; i++) {
			int temp = mas[i];
			mas[i] = mas[len-i-1];
			mas[len-i-1] = temp;
		}
		int max = -1;
		for (int i = 0; i <= len - 3; i++) {
			int sum = mas[i] + mas[i+1] + mas[i+2];
			if (sum > max) {
				max = sum;
			}
		}
		printf("Max sum: %d\n", max);
		for (int i = 0; i <= len - 3; i++) {
			int sum = mas[i] + mas[i+1] + mas[i+2];
			if (sum == max) {
				printf("Numbers: %d %d %d\n", mas[i], mas[i+1], mas[i+2]);
			}
		}
	}
}
