#include "3.h"
#include <stdio.h>

double findAverageCycleLength(ListNode * arrPtr, int n) {
    unsigned int totalCycleLength = 0;
    for (int i = 0; i < n; i++) {
        // For each list, we need to find the cycle length
        // Floyd's cycle-fnding algorithm
        ListNode * singleIncrement = &arrPtr[i];
        ListNode * doubleIncrement = &arrPtr[i];
        while (1) {
            if (singleIncrement->next == NULL || doubleIncrement->next == NULL) {
                break;
            }
            if (singleIncrement == doubleIncrement->next) {
                // Cycle found
                int cycleLength = 1;
                ListNode * cycleIncrement = singleIncrement->next;
                while (cycleIncrement != singleIncrement) {
                    cycleLength++;
                    cycleIncrement = cycleIncrement->next;
                }
                totalCycleLength += cycleLength;
                break;
            }
            singleIncrement = singleIncrement->next;
            doubleIncrement = doubleIncrement->next->next;
        }
    }
    return (double) totalCycleLength / n;
}
