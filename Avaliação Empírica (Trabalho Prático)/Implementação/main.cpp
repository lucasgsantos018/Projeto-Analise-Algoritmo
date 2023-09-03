/*
  Vitor Hugo Leles Fonseca - 17.2.4324
  Lucas Gomes dos Santos - 20.1.4108
*/


#include <iostream>
#include <time.h>
#include <string> 
#include <cstdlib>
#include <chrono>

#include "utils.hpp"
#include "mergesort.hpp"
#include "radix.hpp"
#include "insertion.hpp"

using namespace std;

int main (int argc, char *argv[]) {
  int metodo, quantidade;
  metodo = atoi(argv[1]);
  quantidade = atoi(argv[2]);

  int *vector = new int[quantidade];

  geraAleatorio(vector, quantidade);
  auto start = std::chrono::high_resolution_clock::now();
  switch (metodo) {
    case 1: {
      cout<<"Testando o MergeSort..."<<endl;
      
      mergeSort(vector, quantidade);

    } break;

    case 2: {
      cout<<"Testando o InsertionSort..."<<endl;

      insertionsort(vector, quantidade);

    } break;

    case 3: {
      cout<<"Testando o RadixSort..."<<endl;

      radixsort(vector, quantidade);

    } break;
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "Tempo de execucao: " << duration.count() << " milissegundos" << std::endl;

  return 0;
}