#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096

double compute_average(int total, int *numbers);

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

  free(numbers);
  return 0;
}

double compute_average(int total, int *numbers) {
  double sum = 0;
  for (int i = 0; i < total; i++) {
    sum += numbers[i];
  }
  return sum / total;
}
