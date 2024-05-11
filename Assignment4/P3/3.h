#ifndef _3_H
#define _3_H

struct listNode {
    int data;               // Data stored in the node
    struct listNode* next;  // Pointer to the next node
};
typedef struct listNode ListNode;

double findAverageCycleLength(ListNode * arrPtr, int n);

#endif