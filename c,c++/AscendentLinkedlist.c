#include <stdio.h>
#include <stdlib.h>

/* Estructura base para cada nodo de una lista enlazada. */
typedef struct Node {
    int key;
    Node *next;
} Node;

/* Inserta un elemento en la lista, dejandola ordenada ascendetemente. */
void InsertElementIntoAscendentLinkedlist(Node **head, int element) {
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->key = element;
    newNode->next = NULL;

    if (*head == NULL || (*head)->key >= element) { // Condicion mejorada
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *prev = *head, *curr = (*head)->next;
    while (curr != NULL && curr->key < element) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = newNode;
    newNode->next = curr;   
}

/* Imprime la lista. */
void showLinkedList(Node *head) {
    while (head != NULL) {
        printf("%d ~ ",head->key);
        head = head->next;
    }
    puts("NULL");
}

/* Recibe la direccion de memoria del head. Elimina los elementos de la memoria y la cabeza apuntara a NULL. */
void deleteLinkedList(Node **head) {
    Node *temp;
    while (*head != NULL) { // Mejorado
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}

/* Elimina la primera recurrencia de un elemento de la lista. */
void deleteElementFirstOccurrenceAscendentLinkedList(Node **head, int element) {
    if (*head == NULL) {
        puts("ERROR: The linked list is empty.");
        return;
    }

    if ((*head)->key == element) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *prev = *head, *curr = (*head)->next;
    while (curr != NULL && curr->key < element) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr != NULL && curr->key == element) {
        prev->next = curr->next;
        free(curr);
        return;
    }

    printf("The element %d isn't in the linked list\n", element);
}


int main() {
    Node *head = NULL;
    int n;
    scanf("%d",&n);
    while (n != -1) {
        InsertElementIntoAscendentLinkedlist(&head, n);
        scanf("%d",&n);
    }
    scanf("%d",&n);
    while (n != -1) {
        deleteElementFirstOccurrenceAscendentLinkedList(&head, n);
        scanf("%d",&n);
    }
    showLinkedList(head);
    deleteLinkedList(&head);
    return 0;
}