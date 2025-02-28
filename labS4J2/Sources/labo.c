#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"
#include <stdint.h>
#include <assert.h>
#include <limits.h> // Pour notre INT_MAX au code du SortQueue


// Aide avec note de cours fournis, aide avec Oli
//https://www.geeksforgeeks.org/queue-in-c/
//https://www.tutorialspoint.com/c_standard_library/limits_h.htm (oui j'aurais pu donner une valeur moi-meme a int maximale mais je trouvais ca cool de mettre ca)
//https://www.maxicours.com/se/cours/trier-par-selection/#:~:text=Le%20tri%20par%20s%C3%A9lection%20d,par%20s%C3%A9lection%20est%20toujours%20quadratique. (Pour le dernier num)


/*
* Ajouter l'element sur la queue/file.
*/
void push(Queue* q, Node* n) {
	if (q->next == NULL) { //Si la file est vide
		q->next = q->prev = n; 
	}
	else {
		Node*last = q->next; // Recupere le dernier element existant de la Queue
		n->next= last; // Le nouveau noeudpointe maintenant vers l'ancien element 
		last->prev= n; // l'ancien dernier element pointe vers le nouveau noeud
		q->next = n; // Mettre a jour la tete de la file
	}
}

/*
* Enlever l'element de la queue/file et retourner le noeud. Si jamais il n'y a pas de noeud, retourner NULL.
*/
Node* pop(Queue* q) {
	Node* n = q->prev; // On recupere le dernier element 

	if (q->prev != NULL) { 
		if (q->prev == q->next) { // Si il y a un seul element dans la liste
			q->next = q->prev = NULL; 
		}
		else {
			q->prev = q->prev->prev; // Sinon on supprime le dernier element
		}
	}
	return n;
}



/*
* Retourner l'element de la fin de la queue/file sans l'enlever de la queue. Si jamais il n'y a pas d'element, retourner NULL.
*/
Node* peek(Queue* q) {
	return q->prev;  // On pointe le dernier element de la file et on le retourne pour nous l'afficher
}



/*
* Ajouter l'element sur la queue/file comme si elle serait une priority queue. Utiliser l'age afin de "trie" a chaque push.La personne au premier pop() est la plus jeune.
*/
void pushAsPriorityQueue(Queue* q, Node* n) {
	if (q->next == NULL) { // Si ya rien dans file
		q->next = q->prev = n;
		return;
	}
	Queue tempQueue = { NULL, NULL }; // File temporaire
	int inserted = 0; // Pour savoir si n a été inséré, comme ungenre de counter 

	// Déplacer les éléments jusqu'à trouver où insérer n
	while (q->next != NULL) {
		Node* current = pop(q); 
		Person* person_current = (Person*)current->data; // On pointe vers l'age de la Queue
		Person* person_n = (Person*)n->data; // On pointe vers l'age de n, qui va etre comparer avec celui de la Queue

		if (!inserted && person_current->age > person_n->age) { // Si n est plus jeune
			push(&tempQueue, n); // Insérer n avant l'élément plus vieux
			inserted = 1; // le counter fait +1 dont la condition sort  
		}

		push(&tempQueue, current); 
	}

	// Si n n'a pas été inséré, c'est le plus vieux, on l'ajoute à la fin
	if (!inserted) { 
		push(&tempQueue, n); 
	}

	// Remettre les éléments dans q 
	while (tempQueue.next != NULL) { 
		push(q, pop(&tempQueue)); 
	}
	// On insere n dans la file en respectant un ordre croissant d'age, on utilise une file temporaire pour reorganiser les elements
	// Des qu'on trouve une personne plus vieille que n on insere n avant
}




/*
* Trier la queue. La personne au premier pop() est la plus jeune.Vous devez utiliser push,pop et/ou peek.
* Vous ne pouvez pas utiliser le meme algorithme de tri que celui utiliser lors du labo sur la stack
*/
void sortQueue(Queue* q) {
	if (q->next == NULL) { // Si la file est vide
		return; 
	}

	Queue sortedQueue = { NULL, NULL }; // on se cree une queue temporaire ou l'on va stocker nos valeurs de notre queue dedans 

	while (q->next != NULL) { // Tant qu'on a pas fait le tour de la liste
		Node* minNode = NULL; // Contient l'age le plus petit
		int minAge = INT_MAX;// Initialise a INT MAX (valeur maximal pour un int) permettant de trouver l'age minimal

		// 1. Trouver l'âge minimum dans la file
		int initialSize = 0; // Compteur qui nous permet de garder une trace du nombre d'element dans q
		Queue tempQueue = { NULL, NULL }; // File temporaire pour stocker les éléments de q temporairement pendant qu'on cherche le plus jeune
		while (q->next != NULL) { // Parcours la file
			Node* current = pop(q); // retire un element
			push(&tempQueue, current); // le stocke dans la tempQueue
			Person* person = (Person*)current->data; // accede a l'age

			if (person->age < minAge) { // si on trouve le plus jeune
				minAge = person->age;
				minNode = current;
			}
			initialSize++; // compte le nombre d'elements
		}// Dans le fond on depile avec pop(q) tous les elements un par un et on les met temporairement dans un tempQueue
		//A chaque element on recupere son age avec person->age
		// Si on trouve un age inferieur que minage on met a jour minage et minNode et on compte le nombre d'elements
	
		// 2. Réinsérer les éléments dans q sauf minNode
		for (int i = 0; i < initialSize; i++) { // On depile tempQueue un par un, on les remet dans q, sauf minNode qui est l'age min
			Node* current = pop(&tempQueue);
			if (current != minNode) {
				push(q, current);
			}
		} // minNode n'st pas reinsere dans q mais conserer pour etre ajouter dans la file trie

		// 3. Ajouter le plus jeune à la file triée
		push(&sortedQueue, minNode); // la on ajoute minNode dans sortedQueue
	}

	// 4. Réinsérer les éléments triés dans q
	while (sortedQueue.next != NULL) {
		push(q, pop(&sortedQueue));
	}
}





	