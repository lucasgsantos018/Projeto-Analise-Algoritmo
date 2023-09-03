#include "mergesort.hpp"
#include "utils.hpp"
#include <iostream>
#include <time.h>
#include <string> 
#include <cstdlib>

// Ordena o vetor v [0..n -1]
void mergeSort (int* v , int n) {
	mergeSort_ordena (v , 0, n -1) ;
}

// Ordena o vetor v[ esq .. dir ]
void mergeSort_ordena (int *v, int esq, int dir) {
	if ( esq >= dir )
	return ;

	int meio = ( esq + dir ) / 2;
	mergeSort_ordena (v,esq,meio);
	mergeSort_ordena (v,meio+1,dir);
	mergeSort_intercala (v,esq,meio,dir);
}

// Intercala os vetores v[esq .. meio ] e v[ meio +1.. dir ]
void mergeSort_intercala (int* v , int esq , int meio , int dir) {
	int i , j , k ;
	int a_tam = meio - esq +1;
	int b_tam = dir - meio ;
	int* a = new int [a_tam];
	int* b = new int [b_tam];
	for (i=0; i< a_tam ; i ++){
		a[i] = v[i+ esq];
	}
	for (i = 0; i < b_tam ; i ++){
		b[i] = v[i+meio+1];
	}
	i = 0; // Índice para o vetor 'a'
	j = 0; // Índice para o vetor 'b'
	k = esq; // Índice para o vetor 'v'

	while (i < a_tam && j < b_tam) {
		if (a[i] < b[j]) {
			v[k++] = a[i++];
		} else {
			v[k++] = b[j++];
		}
	}

	// Copia os elementos restantes do vetor 'a', se houver
	while (i < a_tam) {
		v[k++] = a[i++];
	}

	// Copia os elementos restantes do vetor 'b', se houver
	while (j < b_tam) {
		v[k++] = b[j++];
	}
}