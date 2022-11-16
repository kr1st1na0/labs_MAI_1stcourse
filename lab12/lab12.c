#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THREE (3)

typedef struct {
	int array[THREE];
	int idx;
} CyclicArray;

int sum(int array[THREE]) {
	int s = 0;
	for (int i = 0; i < THREE; i++) {
		s += array[i];
	}
	return s;
}

void func(int maxArray[THREE]);

int main() {
	int maxArray[THREE] = { 0, 0, 0 };
	func(maxArray);
	printf("MaxSum = %d\n", sum(maxArray));
	printf("Numbers: ");
	for (int i = 0; i < THREE; i++) {
		printf("%d ", maxArray[i]);
	}
	printf("\n");
	return 0;
}

int update(CyclicArray *cyclic, int digit) {
	int result = cyclic->array[cyclic->idx];
	cyclic->array[cyclic->idx++] = digit;
	cyclic->idx %= THREE;
	return result;
}

void func(int maxArray[THREE]) {
	int iter = 0;
	memset(maxArray, 0, THREE * sizeof maxArray[0]);
	int currentSum = 0, maxSum = 0;
	CyclicArray  cyclic = { { 0, 0, 0}, 0 };
	for (int ch = getchar(); ch != EOF; ch = getchar(), ++iter) {
		int digit = ch - '0';
		currentSum -= update(&cyclic, digit);
		currentSum += digit;
		if (currentSum > maxSum) {
			memcpy(maxArray, cyclic.array, sizeof cyclic.array);
			maxSum = currentSum;
		}
	}
}
