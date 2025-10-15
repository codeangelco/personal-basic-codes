#include <stdio.h>
#include <stdlib.h>
#define infinity 2147483647

typedef struct Node {
	int key;
	struct Node *next;
} Node;

void stackPush(Node **top, int element) {
    Node *newNode = malloc(sizeof(Node));
    newNode->next = *top;
    newNode->key = element;
    *top = newNode;
}

int stackPop(Node **top) {
	Node *current = *top;
	int element = infinity;

	if (*top == NULL) {
		printf("The stack is empty.\n");
	} else {
		current = *top;
		element = (*top)->key;
		(*top) = (*top)->next;
		free(current);
	}
	
	return element;
}

int stackEmpty(Node *top) {
    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void stackFree(Node **top) {
    while (!stackEmpty(*top)) {
        stackPop(top);
    }
}

int main() {
    Node *top = NULL;
    int op, value;
    while (scanf("%d",&op) != EOF) {
        switch (op) {
            case 1:
                scanf("%d",&value);
                stackPush(&top, value);
                break;
            case 2:
                if (stackEmpty(top)) {
                    printf("The stack is empty!\n");
                } else {
                    value = stackPop(&top);
                    printf("%d\n",value);
                }
                break;
            default:
                printf("Invalid case!\n");
        }
    }
    stackFree(&top);
	return 0;
}
