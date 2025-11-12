#include <stdio.h>
#include <stdlib.h>
#define infinity 2147483647

typedef struct Node {
	int key;
	int min;
	int max;
	struct Node *next;
} Node;

int stackEmpty(Node *top) {
    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void stackPush(Node **top, int element) {
    Node *newNode = malloc(sizeof(Node));
    newNode->next = *top;
    newNode->key = element;
    newNode->min = element;
    newNode->max = element;
    if (!stackEmpty(*top)) {
        if ((*top)->min < newNode->min) {
            newNode->min = (*top)->min;
        }
        if ((*top)->max > newNode->max) {
            newNode-> max = (*top)->max;
        }
    }
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

void stackFree(Node **top) {
    while (!stackEmpty(*top)) {
        stackPop(top);
    }
}

int main() {
    Node *top;
    int op, value, t, q;
    scanf("%d",&t);
    while (t--) {
        top = NULL;
        scanf("%d",&q);
        while (q--) {
            scanf("%d",&op);
            switch (op) {
                case 1:
                    scanf("%d",&value);
                    stackPush(&top, value);
                    break;
                case 2:
                    if (stackEmpty(top)) {
                        break;
                    } else {
                        stackPop(&top);
                    }
                    break;
                case 3:
                    if (!stackEmpty(top)) {
                        printf("%d\n", top->max - top->min);
                    } else {
                        puts("Empty!");
                    }
                    break;
                default:
                    puts("Invalid case!");
                }
            }
        }
	return 0;
}
