#include <stdio.h>
#include <stdlib.h>

struct Coach {
    int id;
    struct Coach *prev, *next;
};

struct Coach *start = NULL, *end = NULL, *pos = NULL;

void addCoach(int id) {
    struct Coach *newC = (struct Coach*)malloc(sizeof(struct Coach));
    newC->id = id;
    newC->prev = newC->next = NULL;

    if (start == NULL) { 
        start = end = pos = newC;
    } else {
        end->next = newC;
        newC->prev = end;
        end = newC;
    }
    printf("Coach %d added.\n", id);
}

void removeCoach(int id) {
    struct Coach *temp = start;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Coach %d not found!\n", id);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        end = temp->prev;

    if (pos == temp)
        pos = temp->next ? temp->next : temp->prev;

    free(temp);
    printf("Coach %d removed.\n", id);
}

void moveNext() {
    if (pos != NULL && pos->next != NULL) {
        pos = pos->next;
        printf("Now at coach %d.\n", pos->id);
    } else {
        printf("No coach ahead!\n");
    }
}

void movePrev() {
    if (pos != NULL && pos->prev != NULL) {
        pos = pos->prev;
        printf("Now at coach %d.\n", pos->id);
    } else {
        printf("No coach behind!\n");
    }
}

void showTrain() {
    struct Coach *temp = start;
    printf("Train: ");
    while (temp != NULL) {
        if (temp == pos)
            printf("[*%d*] ", temp->id);
        else
            printf("%d ", temp->id);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    addCoach(1);
    addCoach(2);
    addCoach(3);
    addCoach(4);

    showTrain();

    moveNext();
    moveNext();
    movePrev();

    removeCoach(2);

    showTrain();

    return 0;
}
