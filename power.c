#include <stdio.h>

int power(int base, int n) {
	int result = base;
	for(int i = 2; i <= n; i++) {
		result = result * base;
	}
	return result;
}

int main () {
	printf("%d\n", power(10, 3));
	return 0;
}
