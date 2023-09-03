#include <cstdlib>
#include <iostream>
#include <ctime>

#include "utils.hpp"
using namespace std;

void geraAleatorio (int* vector, int n) {
  // preenche o vetor com numeros aleatorios
  std::time_t currentTime = std::time(nullptr);
  std::srand(static_cast<unsigned int>(currentTime));

  for (int i=0; i<n; i++)
    vector[i] = std::rand()%n;
  return;
}

// A utility function to print an array
void printaVetor(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout<<endl;
}