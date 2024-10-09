#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
} node;

// Função para percorrer a lista e imprimir os dados
void printList(node* head) {
	node* temp = head;
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->link;
	}
	printf("NULL\n");  // Indica o fim da lista
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

	// Chamando a função para imprimir a lista
	printList(head);

	return 0;
}
