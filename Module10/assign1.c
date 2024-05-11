#include <stdio.h>

int main(void) {
    int numSeats;
    printf("Total number of seats: ");
    scanf("%d", &numSeats);

    int numVotes;
    printf("Total number of votes: ");
    scanf("%d", &numVotes);

    int numLists;
    printf("Total number of lists: ");
    scanf("%d", &numLists);

    int quota = numVotes / numSeats;
    int seats[numLists];
    for (int i = 0; i < numLists; i++) {
        printf("Votes for list %d: ", i + 1);
        scanf("%d", &seats[i]);
        int autoSeats = seats[i] / quota;
        printf("Automatic seat for list %d: %d\n", i + 1, autoSeats);
        printf("Remainder for list %d: %d\n", i + 1, seats[i] - autoSeats * quota);
    }

    return 0;
}
