/* 
Lucas Gomes dos Santos - 20.1.4108

b) A função potencia possui recursão e a função de multiplicar matriz, que representa 8 instruções
T(n) = T(n/2) + 19

T(n) = (T(n/4) + 19) + 19 = T(n/2^2) + 2 * 19

Ou seja, usando a relação de recorrência -> T(n) = T(n/(2^k) + 19 * k) 

Caso base -> n / (2^k) = 1
ln(n) = k * ln(2) -> k = ln(n)
Logo, T(n) = T(1) + 19 * ln(n)  ->   T(n) = O(1) + O(ln(n)) , podemos concluir então, que T(n) = O(ln(n))


*/


#include <stdio.h>

// Função para multiplicar matrizes 2x2  
// Linha 15 a 18 - 4 instruções
// Linha 22 a 25 - 4 instruções, total multMatriz - 8 instruções

void multMatriz(int matriz1[2][2], int matriz2[2][2]){

    int x = matriz1[0][0] * matriz2[0][0] + matriz1[0][1] * matriz2[1][0];
    int y = matriz1[0][0] * matriz2[0][1] + matriz1[0][1] * matriz2[1][1];
    int z = matriz1[1][0] * matriz2[0][0] + matriz1[1][1] * matriz2[1][0];
    int w = matriz1[1][0] * matriz2[0][1] + matriz1[1][1] * matriz2[1][1];

    matriz1[0][0] = x;
    matriz1[0][1] = y;
    matriz1[1][0] = z;
    matriz1[1][1] = w;
}

// Função para elevar matriz 2x2 à n
// linha 33 a 36 - 2 instruções
// função potencia recursiva -> T(n/2)
// multMatriz -> 8 instruções
// linha 44 e 45 -> 9 instruções     Total -> T(n/2) + 19

void potencia(int matriz1[2][2], int n){

    if(n == 0 || n == 1)
        return;
    
    int dataMatriz[2][2] = {{1,1}, {1,0}};

    potencia(matriz1, n / 2);
    multMatriz(matriz1, matriz1);

    if (n % 2 != 0)
        multMatriz(matriz1, dataMatriz);
    
}

int fib(int n){
    if(n == 0)
        return 0;
    int matriz1[2][2] = {{1,1}, {1,0}};

    potencia(matriz1, n - 1);

    return matriz1[0][0];
}

int main(){
    int n, resultFib;

    printf("Digite a posição n para saber seu valor na sequência de fibonacci: ");
    scanf("%d", &n);
    resultFib = fib(n);
    printf("Valor: %d\n", resultFib);

    return 0;
}