#include "insertion.hpp"
#include "utils.hpp"

void insertionsort ( int* vector, int n) {
  int i,j;                            // O(1)

  for (i = n -2; i >= 0; i --) {      // O(n) -> n - 1 iterações
    vector[n] = vector[i];            // O(1)  
    j = i + 1;                        // O(1)
    while (vector[n] > vector[j] ) {  // O(n) -> No pior caso n - 1 iterações 
      vector[j - 1] = vector[j];      // O(1)
      j ++;                           // O(1)
    }
    
  vector[j - 1] = vector[n];           // O(1)
 }
}                                      // = O(n^2)