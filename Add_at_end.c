#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} node;

// Função para adicionar um node no final da lista
void add_node_at_end(node* head, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->link = NULL;

    node* temp = head;

    // Percorre até o último nó
    while (temp->link != NULL) {
        temp = temp->link;
    }

    // Aponta o último nó para o novo nó
    temp->link = new_node;
}

int main() {
    node* head = NULL;
    head = (node*)malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;

    node* current = NULL;
    current = (node*)malloc(sizeof(node));
    current->data = 23;
    current->link = NULL;
    head->link = current;

    current = (node*)malloc(sizeof(node));
    current->data = 10;
    current->link = NULL;
    head->link->link = current;

    // Adiciona um novo nó no final da lista
    add_node_at_end(head, 5);

    return 0;
}
