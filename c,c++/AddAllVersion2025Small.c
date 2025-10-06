#include <stdio.h>
#include <stdlib.h>
#define ll long long

typedef struct Node {
    ll key;
    struct Node *next;
} Node;

void insertAscendantLinkedList(Node **head, size_t *size, ll value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = value;
    newNode->next = NULL;
    (*size)++;

    if (*head == NULL || (*head)->key >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *prev = *head, *curr = (*head)->next;
    while (curr != NULL && curr->key < value) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = newNode;
    newNode->next = curr;
}

ll extractMin(Node **head, size_t *size) {
    (*size)--;
    Node *temp = *head;
    *head = (*head)->next;
    ll min = temp->key;
    free(temp);
    return min;
}

ll AddAll(Node **head, size_t size) {
    ll result = 0;
    while (size > 1) {
        ll temp = extractMin(head, &size);
        temp += extractMin(head, &size);
        result += temp;
        insertAscendantLinkedList(head, &size, temp);
    }
    return result;
}

void solver() {
    Node *head = NULL;
    size_t n, size = 0;
    scanf("%zu",&n);
    for (int i = 0; i < n; i++) {
        ll temp;
        scanf("%lld",&temp);
        insertAscendantLinkedList(&head, &size, temp);
    }
    printf("%lld\n",AddAll(&head, size));
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        solver();
    }
    

    return 0;
}