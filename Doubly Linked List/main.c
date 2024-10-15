#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} Node;

// Função que conta os Nodes da lista
void countNodes (Node *head) {
    
    Node *ptr_aux = head;
    
    int count = 0;
    
    while (ptr_aux != NULL) {
        count++;
        ptr_aux = ptr_aux->next;
    } printf ("Numeros de Nodes na Lista = %d\n\n", count);
    
}

// Função para imprimir a list
void printList(Node *head) {
    Node *ptr_aux = head;
    
    while (ptr_aux != NULL) {
        printf("%d", ptr_aux->data);
        ptr_aux = ptr_aux->next;
        if(ptr_aux != NULL) {
            printf("->");
        }
    }
    printf("->NULL\n");
}

// Função para adicionar um nó à lista vazia
Node *addAtEmptyList (Node *head, int data) {
    
    // retorna o endereço base da memória alocada ->
    // e atribui este endereço à variável temp.
    Node *temp = (Node *)malloc(sizeof(Node));
    
    // Verifica se há falha na alocação de memória;
    if(temp == NULL) {
        printf("Erro de alocação de memória\n");
        return NULL;
    }
    
    // Inicializa o novo N definindo os Ponteiros como NULL
    // e atribuindo o valor de "data";
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    
    head = temp; // O ponteiro head agora aponta para o novo nó criado;
    
    return head; // Retorna o novo ponteiro head, que aponta para o primeiro nó da lista;
}

// Função para adicionar um nó no inicio da lista
Node *addAtBeginning (Node *head, int data) {
    
    // retorna o endereço base da memória alocada ->
    // e atribui este endereço à variável temp.
    Node *temp = (Node *)malloc(sizeof(Node));
    
    // Verifica se há falha na alocação de memória;
    if(temp == NULL) {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    
    // Inicializa o novo N definindo os Ponteiros como NULL
    // e atribuindo o valor de "data";
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    
    // temp->next aponta para onde head esta apontando;
    temp->next = head;
    
    // Verificação para evitar segfault;
    if (head != NULL) { 
        head->prev = temp;
    }
    
    head = temp; // O ponteiro head agora aponta para o novo nó criado;
    
    return head; // Retorna o novo ponteiro head, que aponta para o primeiro nó da lista;
}

// Função para adicionar um nó no final da lista
Node *addAtEnd (Node *head, int data) {
    
    Node *temp = (Node *)malloc(sizeof(Node));
    
    if (temp == NULL) {
        printf("Erro ao alocar memória");
        return NULL;
    }
    
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    
    // Se a lista estiver vazia, retorna o novo nó como head
    if (head == NULL) {
        return temp;  // Aqui o novo nó se torna o head
    }
    
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = temp;
    temp->prev = current;
    
    return head;
}

// Função para adicionar um nó em uma posição específica
Node *addAtPosition(Node *head, int data, int position) {
    // Verifica se a posição é válida (deve ser maior ou igual a 1)
    if (position < 1) {
        printf("Posição inválida. Deve ser maior ou igual a 1.\n");
        return head;
    }

    // Se a posição for a primeira, usa a função de adicionar no início
    if (position == 1) {
        return addAtBeginning(head, data);
    }

    // Cria o novo nó
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Erro ao alocar memória.\n");
        return head;
    }

    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    // Percorre a lista até a posição desejada ou o final
    Node *current = head;
    int currentPosition = 1;
    
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    // Se o current for NULL, a posição é maior que o número de nós da lista
    if (current == NULL) {
        printf("A posição é maior que o tamanho da lista.\n");
        free(temp);
        return head;
    }

    // Insere o nó na posição especificada
    temp->next = current->next;
    if (current->next != NULL) {
        current->next->prev = temp;
    }
    current->next = temp;
    temp->prev = current;

    return head;
}

// Função para remover o primeiro nó da lista
Node *removeFirstNode(Node *head) {
    
    // Verifica se a lista está vazia
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return NULL;
    }

    // Guarda o próximo nó
    Node *temp = head;
    head = head->next; // Atualiza o head para o próximo nó

    // Verifica se o próximo nó não é NULL e ajusta o ponteiro prev
    if (head != NULL) {
        head->prev = NULL;
    }

    // Libera o nó removido
    free(temp);
    
    return head; // Retorna o novo head
}

// Função para remover o último nó da lista
Node *removeLastNode(Node *head) {
    // Verifica se a lista está vazia
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return NULL;
    }

    // Se a lista tem apenas um nó
    if (head->next == NULL) {
        free(head);
        return NULL; // A lista agora está vazia
    }

    // Percorre a lista até o último nó
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Ajusta o ponteiro do penúltimo nó
    current->prev->next = NULL;
    free(current); // Libera o último nó

    return head; // Retorna o ponteiro head
}

// Função para remover um nó de uma posição específica
Node *removeAtPosition(Node *head, int position) {
    // Verifica se a lista está vazia ou se a posição é inválida
    if (head == NULL || position < 1) {
        printf("A lista está vazia ou a posição é inválida.\n");
        return head;
    }

    // Se a posição for a primeira, usa a função de remover o primeiro nó
    if (position == 1) {
        return removeFirstNode(head);
    }

    // Percorre a lista até a posição desejada
    Node *current = head;
    int currentPosition = 1;
    
    while (current != NULL && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    // Se o current for NULL, a posição é maior que o número de nós da lista
    if (current == NULL) {
        printf("A posição é maior que o tamanho da lista.\n");
        return head;
    }

    // Ajusta os ponteiros do nó anterior e do próximo
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    // Libera o nó a ser removido
    free(current);

    return head;
}

// Função para liberar a memória da lista
void freeList(Node **head) {
    
    Node *current = *head;
    Node *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *head = NULL; // Define o ponteiro head como NULL após a liberação
}

int main () {
    
    // Define o ponteiro head como NULL;
    Node *head = NULL;
    
    // Adiciona um Node no final da lista;

    head = addAtEmptyList(head, 45);
    head = addAtBeginning(head, 78);
    head = addAtEnd(head, 63);
    
    printList(head);
    countNodes(head);
    
    head = removeFirstNode(head);
    head = removeLastNode(head);
    
    printList(head);
    countNodes(head);
    
    head = addAtPosition(head, 99, 2);
    head = removeAtPosition(head, 2);
    
    printList(head);
    countNodes(head);
    
    
    
    return 0;
}