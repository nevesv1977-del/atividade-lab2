#include <stdio.h>

/* * ANÁLISE EXIGIDA:
 * 1. Passagem por Valor: A função recebe uma CÓPIA do dado. Um novo endereço de memória 
 * é alocado no escopo da função. Alterar essa cópia não afeta a variável original no main.
 * 2. Passagem por Referência (Ponteiros): A função recebe o ENDEREÇO de memória da variável original. 
 * Ao usar o operador de desreferência (*), acessamos diretamente o espaço de memória do main, 
 * permitindo a mutação do estado original.
 */

void alterar_por_valor(int saldo) {
    saldo = 5000;
    printf("Dentro da funcao (valor): %d\n", saldo);
}

void alterar_por_referencia(int *saldo) {
    *saldo = 5000;
    printf("Dentro da funcao (referencia): %d\n", *saldo);
}

int main() {
    int saldo_bancario = 1000;

    printf("Saldo inicial: %d\n", saldo_bancario);

    printf("\nTentando alterar via Passagem por Valor...\n");
    alterar_por_valor(saldo_bancario);
    printf("Saldo apos funcao: %d (Falhou)\n", saldo_bancario);

    printf("\nTentando alterar via Passagem por Referencia (Ponteiro)...\n");
    alterar_por_referencia(&saldo_bancario);
    printf("Saldo apos funcao: %d (Sucesso)\n", saldo_bancario);

    return 0;
}