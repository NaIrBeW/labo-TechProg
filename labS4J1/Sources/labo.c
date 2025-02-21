#include <stdint.h>
#include <assert.h>
#include "labo.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// https://www.geeksforgeeks.org/c-program-to-reverse-a-stack-using-recursion/ 
//https://www.geeksforgeeks.org/sort-a-stack-using-recursion/
//https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/

// Les sources citées m'ont aidé dans mon code ainsi que les notes de cours, rien a été copier :)


/*
* Creer la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size) {

Stack* s = (Stack*)allocate(sizeof(Stack));

	if (!s) return NULL;  // Vérifier que l'allocation a réussi

	s->max_size = max_size;
	s->top = -1;  // La pile est vide au début
	s->data = (void**)allocate(max_size * sizeof(void*));
	if (!s->data) {
		// Si l'allocation échoue, libérer la structure de la pile
		free(s);
		return NULL;
	}

return s;
}


/*
* Ajouter l'element sur la stack. Prevener "l'overflow" de la stack.
*/
void push(Stack* s, void* newData) {

	if (s->top + 1 < s->max_size) {
		s->top += 1;
		s->data[s->top] = newData;
	}
	else if (s-> top >= s -> max_size - 1) {
		return; 
	}

}

/*
* Enlever l'element de la stack et retourner l'information. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* pop(Stack* s) {
	void* out = NULL;

	if (s->top >= 0) {
		out = s->data[s->top];
		s->top -= 1;
	}
	
	return out; 
	
}

/*
* Retourner l'element du top sans l'enlever de la stack. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* peek(Stack* s) {

	if (s->top >= 0) {
		return s->data[s->top];  // Retourner l'élément du haut sans le retirer
	}
	return NULL;

}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilise la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s) {

	if (s->top < 0) {
		return;
	}

	// Retire tous les éléments de la pile et les stocker dans un tableau temporaire
	void** temptab = (void**)allocate((s->top + 1) * sizeof(void*));
	if (!temptab) return; // Si l'allocation échoue, on arrête l'opération

	int i = 0;
	while (s->top >= 0) {
		temptab[i++] = pop(s); // On recupere chaque element du Stack s pour le mettre dans notre tableau tempo

	}

	// Reinserer les elements a l'envers 
	for (int j = 0; j < i; j++) {
		push(s, temptab[j]);
	}

}

/*
* Triee la stack.La personne sur le haut/top est la plus jeune. Vous ne pouvez pas modifier la propriete data directement. Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s) {

	if (s->top == -1) {
		return; // La pile est vide
	}

	// Utiliser une pile temporaire pour trier les éléments
	Stack* tempStack = new_stack(s->max_size);
	if (!tempStack) return; // Si l'allocation échoue, on arrête l'opération

	while (s->top != -1) {
		// Extrait l'élément supérieur de la pile originale
		void* temp = pop(s);

		// Transférer les éléments de tempStack à s s'ils sont plus grands que temp
		while (tempStack->top != -1 && *(int*)peek(tempStack) > *(int*)temp) { // On compare temp donc les elements extraits avec l'element du sommet de tempstack
			push(s, pop(tempStack)); // Si l'element de tempstack est plus grand que temp on le deplace dans s pour faire de la place

		// Placer temp dans la pile temporaire
		push(tempStack, temp);
		}// Une fois les elements plus grands deplacer on place temp dans tempstack 
	}

	// Remettre les éléments triés dans la pile originale
	while (tempStack->top != -1) { // A la fin tempstack contient les elements tries et on les remet dans s
		push(s, pop(tempStack));
	}
}