#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *link;
} node;

void count_of_nodes(node *head) {
    int count = 0;
    if (head == NULL) {
        printf("Linked list is empty\n");
        return; // Adicionei um return aqui para evitar continuar a contagem
    }
    
    node *ptr = head; // Não precisa de inicialização a NULL aqui
    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }
    printf("Count of nodes: %d\n", count);
}

int main() {
    
    node *head = malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;
    
    node *current = malloc(sizeof(node));
    current->data = 36;
    current->link = NULL;
    head->link = current;
    
    current = malloc(sizeof(node));
    current->data = 57;
    current->link = NULL;
    head->link->link = current;
    
    current = malloc(sizeof(node));
    current->data = 54;
    current->link = NULL;
    head->link->link->link = current;

    // Chama a função para contar os nós
    count_of_nodes(head);

    // Libere a memória alocada (opcional, mas recomendado)
    // Aqui você deve liberar a memória de cada nó

    return 0;
}