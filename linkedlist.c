#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
	int data;
	struct linkedlist *next;
} linkedlist;

void push_to_list(linkedlist **head, int data) {
	linkedlist *current = *head;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = (linkedlist*)malloc(sizeof(linkedlist));
	current->next->data = data;
	current->next->next = NULL;
}

// print linked list
void print_list(linkedlist *head) {
	linkedlist *current = head;
	while(current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int main(){
	linkedlist* ll = malloc(sizeof(linkedlist));
	push_to_list(&ll, 1);
	push_to_list(&ll, 2);
	print_list(ll);

	return 0;
}