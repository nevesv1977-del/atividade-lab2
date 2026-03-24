#include <stdio.h>

/* * ANÁLISE EXIGIDA:
 * 1. Função Segura (return): A nova altitude é calculada e retornada como um novo valor. 
 * O estado original da variável no 'main' permanece intacto até que o programador 
 * decida atribuir o retorno explicitamente.
 * 2. Efeito Colateral (void com ponteiro): Ao passar o endereço da variável local, 
 * o procedimento altera o valor diretamente na memória. Isso caracteriza um 
 * "efeito colateral", pois a mudança ocorre fora do escopo da função, 
 * podendo gerar acoplamento forte e dificuldades em rastrear mudanças de estado.
 */

// Função que calcula sem alterar o original (Imutabilidade simulada)
int calcular_nova_altitude(int altitude_atual, int subida) {
    return altitude_atual + subida;
}

// Procedimento que força a mutação (Efeito Colateral)
void forcar_mudanca_altitude(int *altitude_local, int nova_altitude) {
    *altitude_local = nova_altitude; 
    printf("[SISTEMA] Altitude alterada via referencia para: %d m\n", *altitude_local);
}

int main() {
    int altitude = 1000; // Variável local ao main

    printf("Altitude Inicial: %d m\n", altitude);

    // 1. Uso seguro
    int calculo = calcular_nova_altitude(altitude, 500);
    printf("Calculo realizado (Funcao): %d m | Altitude Real: %d m (Sem alteracao)\n", calculo, altitude);

    // 2. Uso com efeito colateral
    printf("\nIniciando mutacao forcada...\n");
    forcar_mudanca_altitude(&altitude, 2500);
    printf("Altitude Real apos Procedimento: %d m (Alterada diretamente)\n", altitude);

    return 0;
}