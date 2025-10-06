#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void show(Node* head) {
    if (head == NULL) { // En caso de que la lista este vacía.
        puts("Pointer 'head' is pointing to NULL");
    }
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void freeL(Node* head) {
    Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void makeLinkedList(Node** head) {

}

int main() {
    printf("\n"); // Simplemente algo estetico
    Node* head = NULL;

    show(head); // Ejemplo para cuando la lista este vacia y se quiera imprimir

    for (int i = 1; i <= 10; i++) append(&head,i);

    // int temp;
    // for (int i = 0; i < 10; i++) {
    //     scanf("%d",&temp);
    //     append(&head,temp);
    // }
   

    show(head);
    freeL(head);

    return 0;
}