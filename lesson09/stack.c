#include <stdlib.h>
#include <stdio.h>

struct Element {
    int             value;
    struct Element *next;
    struct Element *previous;
};

typedef struct Element Element;
/* 
  I need to do this because C does't support something like
  deftype struct Element {
    int   value;
    Element *next;
    Element *previous;
  };
*/

typedef struct {
    struct Element *currentElement;
    struct Element *firstElement;
} Stack;

Element *createElement(int n) {
    Element *Element = malloc(sizeof(Element));
    if (Element == NULL) {
        printf("Something wrong while creating a new Element\n");
        exit(EXIT_FAILURE);
    }
    Element->value = n; // same as (*nsode).value = n;
    return Element;
}

Stack *createStack(int n) {
    Element *Element = createElement(n);
    Stack *  stack   = malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Something wrong while creating a new stack\n");
        exit(EXIT_FAILURE);
    }
    stack->currentElement = Element;
    stack->firstElement   = Element;
    return stack;
}

Element *push(Stack *stack, int n) {
    Element *newElement         = createElement(n);
    stack->currentElement->next = newElement;
    newElement->previous        = stack->currentElement;
    stack->currentElement       = newElement;
    return newElement;
}

Element *pop(Stack *stack) {
    if (stack->currentElement == NULL) {
        return NULL;
    }
    Element *poppedValue        = stack->currentElement;
    stack->currentElement       = poppedValue->previous;
    stack->currentElement->next = NULL;
    poppedValue->previous       = NULL;
    return poppedValue;
}

void printElement(Element *element) {
    if (element == NULL) {
        printf("Element is NULL");
    } else {
        printf("Element value is %d\n", element->value);
    }
}

void printStack(Stack *stack) {
    Element *whatever = stack->firstElement;
    while (whatever != NULL) {
        if (whatever == stack->currentElement) {
            printf("(%d) <-- stack pointer\n", whatever->value);
        } else {
            printf("(%d)\n", whatever->value);
        }
        printf("| |\n");
        if (whatever->next == NULL) {
            printf("NULL\n");
        }
        whatever = whatever->next;
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
    Element *element = pop(stack);
    printElement(element);
    free(element);
    printStack(stack);
}