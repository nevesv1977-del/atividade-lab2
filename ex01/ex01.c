#include <stdio.h>
#include <time.h>

/* * ANÁLISE EXIGIDA:
 * 1. Iteração (Procedural): Possui complexidade O(n). Utiliza um espaço fixo na Stack, 
 * apenas sobrescrevendo as variáveis locais a cada ciclo do loop.
 * 2. Recursão Pura: Possui complexidade exponencial O(2^n). Cada chamada gera um novo 
 * 'Stack Frame' (quadro de pilha) para armazenar o estado da função. 
 * Para o 40º termo, bilhões de chamadas são empilhadas, causando alto custo de CPU 
 * e risco de esgotamento da memória da Pilha (Stack Overflow).
 */

long long fibonacci_iterativo(int n) {
    long long a = 0, b = 1, temp;
    for (int i = 0; i < n; i++) {
        temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}

long long fibonacci_recursivo(int n) {
    if (n <= 1) return n;
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

int main() {
    int n = 40;
    clock_t start, end;
    double cpu_time_used;

    printf("Calculando o %d-esimo termo de Fibonacci...\n", n);

    // Teste Iterativo
    start = clock();
    long long res_i = fibonacci_iterativo(n);
    end = clock();
    printf("Iterativo: %lld | Tempo: %f s\n", res_i, ((double) (end - start)) / CLOCKS_PER_SEC);

    // Teste Recursivo
    printf("Calculando recursivo (aguarde)...\n");
    start = clock();
    long long res_r = fibonacci_recursivo(n);
    end = clock();
    printf("Recursivo: %lld | Tempo: %f s\n", res_r, ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}