#include <stdio.h>

/*
  print Celsius - Fahrenheit Table
  for celsius = 0, 20, ..., 3000
*/
main() 
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  printf("Celcius to Fahrenheit Table\n");
  printf("---------------------------\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = celsius/(5.0 / 9.0) + 32;

    printf("%3.0f\t%6.1f\n", celsius, fahr);

    celsius = celsius + step;
  }
}

