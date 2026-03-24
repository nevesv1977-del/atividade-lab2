#include <stdio.h>

/* * ANÁLISE EXIGIDA:
 * A ausência do Caso Base causa uma recursão infinita. Cada chamada consome um 
 * 'Stack Frame' na memória Pilha (Stack). Como a memória é finita, a pilha 
 * transborda (Stack Overflow), e o Sistema Operacional interrompe o processo 
 * com um erro de Segmentação (Segmentation Fault).
 */

void contagem_regressiva(int n) {
    printf("%d... ", n);
    // Caso Base Omitido: causará erro
    contagem_regressiva(n - 1); 
}

// PARA CONSERTAR: Descomente as linhas abaixo e comente a chamada infinita
/*
void contagem_regressiva_correta(int n) {
    if (n < 0) return; // CASO BASE
    printf("%d... ", n);
    contagem_regressiva_correta(n - 1);
}
*/

int main() {
    printf("Iniciando contagem (prepare-se para o erro)...\n");
    contagem_regressiva(10); 
    return 0;
}