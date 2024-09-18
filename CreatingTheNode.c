#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *link;
} node;

int main () {
    struct node *head = (struct node *)malloc(sizeof(struct node));

    printf("\n\nAdress of head = %p\n", &head);
    printf("Content of Head = %p\n\n", (void*)head);
    return 0;
}