#include <stdio.h>
#include <stdlib.h>
#include "3.h"

int main(int argc, char *argv[]) {
  int n = 1;
  ListNode * listArray = (ListNode *)malloc(n * sizeof(ListNode));

  ListNode * listPtr = &listArray[0];
  listPtr->data = 1;
  listPtr->next = NULL;

  double average = findAverageCycleLength(listArray, n);

  printf("%f\n", average);

  free(listArray);
}
