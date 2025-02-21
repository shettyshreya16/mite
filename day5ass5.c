#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char urls[MAX][100];
    int top;
} Stack;

void push(Stack *stack, char *url) {
    if (stack->top < MAX - 1) {
        strcpy(stack->urls[++(stack->top)], url);
    }
}

char *pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->urls[(stack->top)--];
    }
    return NULL;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

int main() {
    Stack back = {.top = -1}, forward = {.top = -1};
    char current[100] = "home";

    printf("Visited: %s\n", current);
    push(&back, current);

    strcpy(current, "google.com");
    printf("Visited: %s\n", current);
    push(&back, current);

    strcpy(current, "github.com");
    printf("Visited: %s\n", current);
    push(&back, current);

    strcpy(current, "stackoverflow.com");
    printf("Visited: %s\n", current);
    push(&back, current);

    if (!is_empty(&back)) {
        push(&forward, pop(&back));
        strcpy(current, back.urls[back.top]);
        printf("Action: Go Back\nCurrent Page: %s\n", current);
    }

    if (!is_empty(&forward)) {
        strcpy(current, forward.urls[forward.top]);
        printf("Action: Go Forward\nCurrent Page: %s\n", current);
    }

    return 0;
}






#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char items[MAX][50];
    int top;
} Stack;

void push(Stack *stack, char *item) {
    if (stack->top < MAX - 1) {
        strcpy(stack->items[++(stack->top)], item);
    }
}

char *pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->items[(stack->top)--];
    }
    return NULL;
}

void display(Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%s", stack->items[i]);
        if (i < stack->top) printf(", ");
    }
    printf("\n");
}

int main() {
    Stack warehouse = {.top = -1};
    char *dispatchedItem;

    push(&warehouse, "Item A");
    printf("Stock Added: Item A\n");
    push(&warehouse, "Item B");
    printf("Stock Added: Item B\n");
    push(&warehouse, "Item C");
    printf("Stock Added: Item C\n");

    dispatchedItem = pop(&warehouse);
    if (dispatchedItem) {
        printf("Dispatching Item: %s\n", dispatchedItem);
    }

    printf("Remaining Stock: ");
    display(&warehouse);

    return 0;
}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char song[50];
    struct Node *next;
} Node;

Node* createNode(char *song) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->song, song);
    newNode->next = newNode;
    return newNode;
}

void addSong(Node **tail, char *song) {
    Node *newNode = createNode(song);
    if (*tail == NULL) {
        *tail = newNode;
        (*tail)->next = *tail;
    } else {
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void nextSong(Node **current) {
    if (*current != NULL) {
        *current = (*current)->next;
    }
}

int main() {
    Node *tail = NULL, *current = NULL;

    addSong(&tail, "Song A");
    addSong(&tail, "Song B");
    addSong(&tail, "Song C");

    current = tail->next;

    printf("Current Song: %s\n", current->song);
    nextSong(&current);
    printf("Next Song: %s\n", current->song);
    nextSong(&current);
    printf("Next Song: %s\n", current->song);
    nextSong(&current);
    printf("Next Song: %s\n", current->song);

    return 0;
}
