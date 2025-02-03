#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // Header
#include <time.h>
#include <stdlib.h>
#include "labo.h"




char* sousTexte(char* texte, int from, int to)
{
	static char sousTab[64] = { 0 };
	
	for (int i = from; i < to; i++) {
		sousTab[i-from] = texte[i];
	}
	return sousTab;
}

void set_String(char* text, String* s)
{  
	int length = 0;
	int longueur_tab = s->length;
	for (int i = 0; text[i] != 0; i++) {
		s->characters[i] = text[i];
		length ++;
	}
	s->length = length; 
	
	
}

int String_is_palindrome(String* s)
{
	int left = 0;
	int right = strlen(s) - 1;
	while (left < right) {
		if (s->characters[left] != s->characters[right]) {
			return 0;
		}
		left++;
		right--;
		
	}
	return 1;
}

void bubbleSort(int elements[], int n)
{

	
	for (int i = 0; i < n - 1; i++) { // Nombre echange
		for (int j = 0; j < n - 1 - i;j++) { //Compare les elements
			if (elements[j] > elements[j + 1]) {// Si element plus grand que le suivant on swap
		
				int temp = 0;
				temp = elements[j];
				elements[j] = elements[j + 1];
				elements[j + 1] = temp;
			}
		}
	}
	return elements;
}

		