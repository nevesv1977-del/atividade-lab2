#include <stdio.h>
#include <string.h>

/* * ANÁLISE EXIGIDA (A Crise do Estado):
 * Argumento: Separar funções matemáticas dos dados (estado) torna-se insustentável 
 * em sistemas complexos porque o estado é "globalmente acessível" ou passado por 
 * longas cadeias de ponteiros. Isso dificulta o controle de quem alterou o quê. 
 * Se um ponteiro for mal manipulado, toda a estrutura do hospital pode ser corrompida. 
 * O Encapsulamento da Orientação a Objetos resolveria isso ao agrupar dados e 
 * comportamentos (métodos) dentro de uma classe, protegendo o estado interno.
 */

typedef struct {
    char nome[50];
    int idade;
    int id_paciente;
} Paciente;

typedef struct {
    char nome[50];
    char especialidade[30];
} Medico;

typedef struct {
    Paciente pacientes[100];
    Medico medicos[20];
    int leitos_disponiveis;
    double caixa_financeiro;
    int total_pacientes;
} SistemaHospitalar;

// Procedimento que precisa manipular a "struct gigante" via ponteiro
void realizar_internacao(SistemaHospitalar *hospital, char *nome, int idade, double custo) {
    if (hospital->leitos_disponiveis > 0) {
        // Manipulação direta e perigosa de múltiplos campos
        int index = hospital->total_pacientes;
        strcpy(hospital->pacientes[index].nome, nome);
        hospital->pacientes[index].idade = idade;
        hospital->pacientes[index].id_paciente = index + 1;
        
        hospital->leitos_disponiveis--;
        hospital->caixa_financeiro += custo;
        hospital->total_pacientes++;

        printf("[SUCESSO] Paciente %s internado. Leitos restantes: %d\n", nome, hospital->leitos_disponiveis);
    } else {
        printf("[ERRO] Sem leitos disponíveis!\n");
    }
}

int main() {
    // Inicialização manual e complexa do estado
    SistemaHospitalar meuHospital = {
        .leitos_disponiveis = 2,
        .caixa_financeiro = 50000.0,
        .total_pacientes = 0
    };

    printf("--- Estado Inicial do Hospital ---\n");
    printf("Caixa: R$ %.2f | Leitos: %d\n\n", meuHospital.caixa_financeiro, meuHospital.leitos_disponiveis);

    // Tentativas de internação
    realizar_internacao(&meuHospital, "Joao Silva", 45, 1500.0);
    realizar_internacao(&meuHospital, "Maria Souza", 30, 2000.0);
    realizar_internacao(&meuHospital, "Carlos Adnet", 60, 1800.0); // Deve falhar por falta de leitos

    printf("\n--- Estado Final do Hospital ---\n");
    printf("Caixa Atualizado: R$ %.2f | Total de Pacientes: %d\n", 
            meuHospital.caixa_financeiro, meuHospital.total_pacientes);

    return 0;
}