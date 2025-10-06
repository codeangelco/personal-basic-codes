#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

void deleteCircularLinkedList(Node **tail) {
    if (*tail == NULL) return;

    Node  *curr = (*tail)->next, *next;
    while (curr != *tail) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(curr);
    *tail = NULL;
}

void printCircularLinkedList(Node *tail) {
    if (tail == NULL) {
        puts("La lista esta vacia.\n");
        return;
    }

    Node *temp = tail->next;
    while (temp != tail) {
        printf("%d ~ ",temp->key);
        temp = temp->next;
    }
    printf("%d ~ (se repite)\n", temp->key);
}

void insertCircularLinkedList(Node **tail, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->key = value;

    if ((*tail) == NULL) {
        newNode->next = newNode;
        *tail = newNode;
        return;
    }

    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
    *tail = newNode;
}

int main() {
    Node *tail = NULL;

    printCircularLinkedList(tail);

    int t = 5;
    while (t--) {
        int temp;
        scanf("%d",&temp);
        insertCircularLinkedList(&tail, temp);
    }

    printCircularLinkedList(tail);
    
    deleteCircularLinkedList(&tail);
    printCircularLinkedList(tail);
    
    return 0;
}