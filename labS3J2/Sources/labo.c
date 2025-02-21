#include <assert.h>
#include <stdint.h>
#include "labo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Aide avec Johnatan sur discord pour le remove et comprendre les inserts et travail en equipe avec Olivier


/*
* Creer un noeud et l'ajouter apres le noeud currNode. Considerer la propriete next et prev.
*/
void insert(Node* currNode, void* newData) {
	Node* n = (Node*)allocate(sizeof(Node));  // Allouer de la memoire au nouveau noeud
	n->data = newData;
	n->prev = NULL;
	n->next = NULL;

	if (currNode->next != NULL) { // On veut s'assurer que ta liste ne soit pas NULL
		n->next = currNode->next;
		currNode->next->prev = n;
	}

	currNode->next = n;
	n->prev = currNode;

}

/*
* Creer un noeud et l'ajouter apres le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData) {
	if (head->data == NULL) { // On s'assurer que la liste n'est pas NULL
		head->data = newData;
		head->prev = head; // Voir avec shema note de cours, si on le met a la fin, le prev de head c'est head meme chose pour son next.
		head->next = head;
		return;
	}
	 
	insert(head->prev, newData); 

}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {
	if (head->data == NULL) {// Verifie si head n'a pas de donnee, si oui la liste est vide
		head->data = newData;// on alloue de la nouvelle memoire
		head->prev = head;
		head->next = head;
		return;
	}


	insert(head, newData);
	
}

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune reference(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode) {

	if (currNode == NULL) { // Verifie si noeud passer en parametre est NULL, si c'est le cas la fonction est NULL.
		return NULL;
	}

	currNode->prev->next = currNode->next;
	currNode->next->prev = currNode->prev; 

	currNode->next = NULL;
	currNode->prev = NULL;
	
	return currNode;
	
}
/*
* Ajouter dans le tableau le nom de chacun en ordre alphabetic. Par simplicite, considerer seulement les deux premiere lettre.
*/
void alphabetise(Node* head, char* names[]) {



	if (head == NULL) { // Si le head est NULL, on sort de l'algo, rien à trier
		return;
	}

	int count = 0;
	Node* temp = NULL;

	while (temp != head->prev) {
		if (temp == NULL) {
			temp = head;
		}
		else {
			temp = temp->next;
		}
		names[count++] = ((Person*)temp->data)->name;
	}

	// Vérifier si le tableau names est plein
	for (int i = 1; i < count; i++) {
		char* current_name = names[i]; 
		int j = i - 1;

		while (j >= 0 && (names[j][0] > current_name[0] || (names[j][0] == current_name[0] && names[j][1] > current_name[1]))) {
			names[j + 1] = names[j]; // Décaler à droite
			j--;
		}

		names[j + 1] = current_name; // Insérer à la bonne place
	}

}
