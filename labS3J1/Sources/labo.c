#include <assert.h>
#include <stdint.h>
#include "labo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//https://www.programiz.com/dsa/linked-list-operations 
// Le code a ete fait en equipe mais de chacun de notre cote, il se peut qu'il y ait des ressemblances mais rien n'a ete copier.
// Fait avec Olivier Clermont, on l'a fait de cette maniere car on aime s'aider a comprendre. 



void insert(Node* currNode, void* newData) {
	Node* n = (Node*)allocate(sizeof(Node));  // Allouer de la memoire au nouveau noeud
	
	n->data = newData; 
	n->next = NULL;

	if (currNode->next != NULL) { // on pointe vers le next pour dire que currNode va etre le prochain noeud  a ajouter
		n->next = currNode-> next;
	}

	currNode->next = n;
}

void insertHead(Node* head, void* newData) {
	if (head->data == NULL) {
		head->data = newData;
	}
	else {
	Node* n = (Node*)allocate(sizeof(Node));
	n->data = newData; 
	n->next = head->next; 
	head->next = n;  
	}

}

Node* removeByData(Node* head, void* rmData) {
	
	
	Node* temp = head;
	Node* last = NULL;

	while(temp != NULL && temp->data != rmData) { // Recherche du noeud a supprimer
		last = temp;
		temp = temp->next;
	}
	if (temp == NULL) { // Si rien est trouver
		return;
	}
	if (last != NULL) {
		last->next = temp->next;
	}
	else {
		head = temp->next;
	}

	memset(temp, 0, sizeof(Node));  
	return last; 

}


Node* removeByName(Node* head, char* name) {
	Node* temp = head;
	Node* last = NULL;

	while (temp != NULL && temp->data != name) { // Recherche du noeud a supprimer
		last = temp;
		temp = temp->next;
	}
	if (temp == NULL) { // Si rien est trouver
		return;
	}
	if (last != NULL) {
		last->next = temp->next;
	}
	else {
		head = temp->next;
	}

	memset(temp, 0, sizeof(Node));
	return last;
	

}


void sort(Node* head) { // lien pour ce code 
	Node* a = head;
	Node* b = a->next;

	for (a = head; a->next != NULL; a = a->next) {
		for (b = a->next; b != NULL; b = b->next) {
			Person* verif_1 = (Person*)a->data;
			Person* verif_2 = (Person*)b->data;
			Person tempo;

			if (verif_1->age > verif_2->age) {
				tempo = *verif_1;
				*verif_1 = *verif_2;
				*verif_2 = tempo; 
			}
		}
	}
}







