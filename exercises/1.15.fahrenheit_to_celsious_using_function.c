#include <stdio.h>

float fahrenheitToCelsius(float fahrenheit) {
	return 5.0 * (fahrenheit - 32) / 9.0;
}

int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	printf("Fahrenheit To Celsius Table\n");
	printf("---------------------------\n");

	fahr = lower;
	while (fahr <= upper) {
		celsius = fahrenheitToCelsius(fahr);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}
