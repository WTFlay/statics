#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define BUFFER_SIZE 4096

double compute_average(int total, int numbers[]);
static inline double pow2(double number);
double standard_deviation(int total, int numbers[], double average);
double relative_standard_deviation(double deviation, double average);

int main() {
  int i = 0, total = 0;
  int *numbers = NULL;
  char buffer[BUFFER_SIZE];
  bool total_is_read = false;
  while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
    if (!total_is_read) {
      total = atoi(buffer);
      if (total <= 0) {
        fprintf(stderr, "total numbers can't be null or negative");
        return 1;
      }
      numbers = calloc(total, sizeof(int));
      if (numbers == NULL) {
        perror("calloc");
        return 1;
      }
      total_is_read = true;
    } else {
      numbers[i++] = atoi(buffer);
    }
  }

  double average = compute_average(total, numbers);
  printf("average: %f\n", average);

  double deviation = standard_deviation(total, numbers, average);
  printf("deviation: %f\n", deviation);

  double relative_deviation = relative_standard_deviation(deviation, average);
  printf("relative deviation: %f\n", relative_deviation);

  free(numbers);
  return 0;
}

double compute_average(int total, int numbers[]) {
  double sum = 0;
  for (int i = 0; i < total; i++) {
    sum += numbers[i];
  }
  return sum / total;
}

static inline double pow2(double number) {
  return number * number;
}

double standard_deviation(int total, int numbers[], double average) {
  double sum_deviation = 0;
  for (int i = 0; i < total; i++) {
    sum_deviation += pow2(average - numbers[i]);
  }
  return sqrt(sum_deviation / total);
}

double relative_standard_deviation(double deviation, double average) {
  return deviation / average;
}
