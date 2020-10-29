#include <stdlib.h>
#include <stdio.h>

struct Node {
    int          value;
    struct Node *next;
    struct Node *previous;
};

typedef struct Node Node;
/* 
  I need to do this because C does't support something like
  deftype struct Node {
    int   value;
    Node *next;
    Node *previous;
  };
*/

typedef struct {
    struct Node *currentNode;
    struct Node *firstNode;
} Stack;

Node *createNode(int n) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("Something wrong while creating a new node\n");
        exit(EXIT_FAILURE);
    }
    node->value = n; // same as (*nsode).value = n;
    return node;
}

Stack *createStack(int n) {
    Node * node  = createNode(n);
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Something wrong while creating a new stack\n");
        exit(EXIT_FAILURE);
    }
    stack->currentNode = node;
    stack->firstNode   = node;
    return stack;
}

Node *push(Stack *stack, int n) {
    Node *newNode            = createNode(n);
    stack->currentNode->next = newNode;
    newNode->previous        = stack->currentNode;
    stack->currentNode       = newNode;
    return newNode;
}

Node *pop(Stack *stack) {
    Node *poppedValue        = stack->currentNode;
    stack->currentNode       = poppedValue->previous;
    stack->currentNode->next = NULL;
    return poppedValue;
}
void printNode(Node* node){
  printf("Node value is %d\n", node->value);
}

void printStack(Stack *stack) {
    Node *currentNode = stack->firstNode;
    while (currentNode != NULL) {
        if (stack->currentNode == currentNode) {
            printf("(%d) <-- stack pointer\n", currentNode->value);
        } else {
            printf("(%d)\n", currentNode->value);
        }
        printf("| |\n");
        if (currentNode->next == NULL) {
            printf("NULL\n");
        }
        currentNode = currentNode->next;
    }
}

int main(void) {
    printf("createStack\n");
    Stack *stack = createStack(2);
    printStack(stack);
    printf("\npush(stack, 4)\n");
    push(stack, 4);
    printStack(stack);
    printf("\npush(stack, 5)\n");
    push(stack, 5);
    printStack(stack);
    printf("\npop(stack)\n");
    Node* node = pop(stack);
    printNode(node);
    free(node);
    printStack(stack);
}