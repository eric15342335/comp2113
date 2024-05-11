#include <stdio.h>
#include <stdlib.h>
#include "3.h"

int main(int argc, char *argv[]) {
  int n = 1;
  ListNode * listArray = (ListNode *)malloc(n * sizeof(ListNode));

  ListNode * listPtr = &listArray[0];
  ListNode * newNode1 = (ListNode *)malloc(sizeof(ListNode));
  ListNode * newNode2 = (ListNode *)malloc(sizeof(ListNode));
  ListNode * newNode3 = (ListNode *)malloc(sizeof(ListNode));
  ListNode * newNode4 = (ListNode *)malloc(sizeof(ListNode));
  listPtr->data = 1;
  listPtr->next = newNode1;
  newNode1->data = 2;
  newNode1->next = newNode2;
  newNode2->data = 1;
  newNode2->next = newNode3;
  newNode3->data = 2;
  newNode3->next = newNode4;
  newNode4->data = 1;
  newNode4->next = newNode2;

  double average = findAverageCycleLength(listArray, n);

  printf("%f\n", average);

  free(newNode1);
  free(newNode2);
  free(newNode3);
  free(newNode4);
  free(listArray);
}
