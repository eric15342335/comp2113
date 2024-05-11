#include <stdio.h>
#include <stdlib.h>
#include "3.h"

int main(int argc, char *argv[]) {
  int n = 2;
  ListNode * listArray = (ListNode *)malloc(n * sizeof(ListNode));

  ListNode * listPtr = &listArray[0];
  ListNode * newNode1 = (ListNode *)malloc(sizeof(ListNode));
  ListNode * newNode2 = (ListNode *)malloc(sizeof(ListNode));
  listPtr->data = 1;
  listPtr->next = newNode1;
  newNode1->data = 2;
  newNode1->next = newNode2;
  newNode2->data = 3;
  newNode2->next = newNode1;

  listPtr = &listArray[1];
  listPtr->data = 4;
  listPtr->next = listPtr;

  double average = findAverageCycleLength(listArray, n);

  printf("%f\n", average);

  free(newNode1);
  free(newNode2);
  free(listArray);
}
