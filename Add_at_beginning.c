#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} node;

// Função para adicionar um nó no início da lista
void add_at_beginning(node** head, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Falha ao alocar memória\n");
        return;
    }
    new_node->data = data;
    new_node->link = *head;
    *head = new_node;
}

int main() {
    node* head = NULL;

    // Criando o primeiro nó manualmente
    head = (node*)malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;

    // Criando o segundo nó manualmente
    node* current = NULL;
    current = (node*)malloc(sizeof(node));
    current->data = 23;
    current->link = NULL;
    head->link = current;

    // Criando o terceiro nó manualmente
    current = (node*)malloc(sizeof(node));
    current->data = 10;
    current->link = NULL;
    head->link->link = current;

    // Adicionando um novo nó no início da lista com valor 99
    add_at_beginning(&head, 99);

    // Exibindo os elementos da lista
    current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");

    return 0;
}