#include "labo.h"
#include <stdio.h>

void insertionSort(int elements[], int n)
{
	for (int i = 1; i < n; i++) {

			int temp = elements[i];
			int b = i - 1;

		while (b >= 0 && elements[b] > temp) {
			elements[b + 1] = elements[b];
			b = b - 1;
		}

		elements[b + 1] = temp;
	}
}



void quickSort(int* elements, int left, int right)
{
	if (left >= right) {
		return;
	}
	int pivot = elements[left]; //Mettre le pivot au premier element du tableau
	int i = left + 1;
	int c = right;
	int temp;

	while (i <= c) {
		while (i <= right && elements[i] <= pivot) {
			i++;
		}
		while (elements[c] > pivot) {
			c--;
		}
		if (i < c) { //Condition qui fait swap notre valeur plus grande vers la droite 
			temp = elements[i];
			elements[i] = elements[c];
			elements[c] = temp;
		}
	}
	// Echange de ton pivot avec ton c qui est ta plus grande valeur
	temp = elements[left];
	elements[left] = elements[c];
	elements[c] = temp;

	//Recursive calls(rappel la meme fonction)
	quickSort(elements, left, c - 1);
	quickSort(elements, c + 1, right);
}
