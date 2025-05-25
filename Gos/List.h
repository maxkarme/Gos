#pragma once
#include <stdio.h>

#include "Subdivision.h";

typedef struct Node {
	Subdivision value;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct {
	Node* root;
} List;

void add(List* list, Subdivision value) {
	if (list->root == 0) {
		Node node = { value, 0, 0 };
		list->root = &node;
		return;
	}

	if (list->root->value.number > value.number) {
		Node node = { value, 0, list->root };
		list->root = &node;
		return;
	}

	Node* curr = list->root;

	while (curr->next != 0 && curr->next->value.number < value.number) {
		curr = curr->next;
	}

	Node node;
	node.value = value;
	node.next = curr->next;
	node.prev = curr;

	curr->next->prev = &node;
	curr->next = &node;
}

void printList(List* list) {
	if (list->root == 0) {
		printf("Список пуст\n");
		return;
	}

	Node* curr = list->root;

	while (curr != 0) {
		printf("{Номер подразделения: %d, Название: %s, ", curr->value.number, curr->value.name);
		printf("Специализация: %s, Количество сотрудников: %d, ", curr->value.specialization, curr->value.countEmployes);
		printf("ФИО руководителя: %s}\n", curr->value.bossName);

		curr = curr->next;
	}
}