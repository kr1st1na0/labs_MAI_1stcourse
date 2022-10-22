#include <stdio.h>
#include <math.h>

int sign(int q) {
	if (q > 0) {
		return 1;
	}
	if (q == 0) {
		return 0;
	}
	if (q < 0) {
		return -1;
	}
}

int max(int a, int b) {
	return a > b ?  a : b;
}

int main() {
	int i = 0, j = -3, l = -7, k = 0, i1, j1;
	while (k <= 51) {
		if (k == 51) {
			printf("The point was not in the specified area. The final coordinates of the point: (%d, %d),  the value of the dynamic motion parameter: %d, the step: 50.\n", i, j, l);
            break;
		}
		if ((((i - 10) * (i - 10) + (j - 10) * (j - 10)) <= 100) && (((i - 10) * (i - 10) + (j - 10) * (j - 10)) >= 25)) {
			printf("At the step number %d the point was in the specified area.\n", k);
			break;
		}
		i1 = i;
		j1 = j;
		i = abs((i1 - j1 + l) / (3 - sign(i1 - j1 + k))) + 10;
		j = abs((i1 + j1 - l) / (3 - sign(j1 - i1 + k))) + 10;
		l = ((max(i1 * j1, j1 * l) * (k + 1)) % 40 + 40) % 40;
		k += 1;
	}
	return 0;
}
