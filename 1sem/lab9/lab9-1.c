#include <stdio.h>

#define N (4)

char alphabet[N] = { '0', '1', '2', '3' };

int permutation(int n, char result[N]);

int main(void) {
	char result[N];
	int f;
	scanf("%d", &f);
	permutation(f, result);
	printf("\n");
	for (int i = 0; i < N; ++i)
	    printf("%c ", result[i]);
	return 0;
}


int permutation(int n, char result[N]) {
	int representation[4] = { 0 };
	for (int i = 1; i < N + 1; ++i) {
		representation[i - 1] = n % i;
		n /= i;
	}
	for (int i = 0; i < N; ++i)
		result[i] = alphabet[i];
	
	for (int i = N - 1; i > 0; --i) {
		int j = representation[i];
		char temp = result[j];
		for (; j < i; ++j)
		    result[j] = result[j + 1];
		result[i] = temp;
	}
	for (int i = 0; i < N / 2; ++i) {
		char h = result[i];
		result[i] = result[N - i - 1];
		result[N - i - 1] = h;
	}
}
