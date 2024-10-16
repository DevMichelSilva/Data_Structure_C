#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um nó para uma lista vazia
struct Node* createEmptyList(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Lista circular aponta para si mesma
    return newNode;
}

// Função para adicionar um nó no início da lista
struct Node* addAtBeginning(struct Node* tail, int data) {
    if (tail == NULL) {
        return createEmptyList(data);
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = tail->next; // Aponta para o antigo head
    tail->next = newNode; // Tail agora aponta para o novo node (novo head)
    return tail;
}

// Função para adicionar um nó no final da lista
struct Node* addAtEnd(struct Node* tail, int data) {
    if (tail == NULL) {
        return createEmptyList(data);
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = tail->next; // Aponta para o antigo head
    tail->next = newNode; // O último nó aponta para o novo nó
    return newNode; // O novo nó agora é o último (tail)
}

// Função para adicionar um nó em uma posição específica
struct Node* addAtPosition(struct Node* tail, int data, int pos) {
    if (tail == NULL) {
        return createEmptyList(data);
    }

    struct Node* current = tail->next; // Começa do head
    int count = 1;

    while (count < pos - 1 && current != tail) {
        current = current->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Posição inválida\n");
        return tail;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;

    if (current == tail) {
        tail = newNode; // Se o nó for inserido no final, atualiza o tail
    }

    return tail;
}

// Função para deletar o primeiro nó (head)
struct Node* deleteFirst(struct Node* tail) {
    if (tail == NULL) {
        printf("A lista está vazia.\n");
        return NULL;
    }

    struct Node* head = tail->next;
    if (head == tail) { // Apenas um nó
        free(head);
        return NULL;
    }

    tail->next = head->next; // Tail aponta para o novo head
    free(head);
    return tail;
}

// Função para deletar o último nó (tail)
struct Node* deleteLast(struct Node* tail) {
    if (tail == NULL) {
        printf("A lista está vazia.\n");
        return NULL;
    }

    struct Node* head = tail->next;
    if (head == tail) { // Apenas um nó
        free(tail);
        return NULL;
    }

    struct Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    current->next = tail->next; // O penúltimo nó aponta para o head
    free(tail);
    return current; // O penúltimo nó agora é o tail
}

// Função para deletar um nó em uma posição específica
struct Node* deleteAtPosition(struct Node* tail, int pos) {
    if (tail == NULL) {
        printf("A lista está vazia.\n");
        return NULL;
    }

    struct Node* head = tail->next;
    if (pos == 1) {
        return deleteFirst(tail);
    }

    struct Node* current = head;
    int count = 1;

    while (count < pos - 1 && current->next != tail->next) {
        current = current->next;
        count++;
    }

    if (count != pos - 1 || current->next == tail->next) {
        printf("Posição inválida\n");
        return tail;
    }

    struct Node* temp = current->next;
    current->next = temp->next;
    if (temp == tail) {
        tail = current; // Se for o último nó, atualiza o tail
    }

    free(temp);
    return tail;
}

// Função para imprimir a lista circular
void printList(struct Node* tail) {
    if (tail == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    struct Node* current = tail->next;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != tail->next);

    printf("(circular)\n");
}

int main() {
    struct Node* tail = NULL;

    tail = addAtEnd(tail, 10); // Adiciona o primeiro nó
    tail = addAtEnd(tail, 20);
    tail = addAtEnd(tail, 30);
    printList(tail);

    tail = addAtBeginning(tail, 5);
    printList(tail);

    tail = addAtPosition(tail, 25, 3);
    printList(tail);

    tail = deleteFirst(tail);
    printList(tail);

    tail = deleteLast(tail);
    printList(tail);

    tail = deleteAtPosition(tail, 2);
    printList(tail);

    return 0;
}
