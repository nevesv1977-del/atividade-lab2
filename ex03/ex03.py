"""
ANÁLISE EXIGIDA (Refatoração):
O código original (espaguete) misturava lógica de cálculo com I/O, dificultando a manutenção.
A refatoração aplica:
1. Alta Coesão: Cada parte do código faz apenas uma coisa.
2. Função Pura (calcular_salario): Recebe dados e retorna um resultado sem efeitos colaterais.
3. Procedimento (imprimir_folha): Responsável apenas pela interface/saída de dados.
"""

# --- PARTE 1: CÓDIGO ESPAGUETE (Comentado para referência) ---
# s1 = 2000 * 1.1; print(f"Func: João - Salário: {s1}"); s2 = 3000 * 1.1; print(f"Func: Maria - Salário: {s2}") ...

# --- PARTE 2: CÓDIGO REFATORADO ---

def calcular_salario(base, bonus_percentual):
    """Função Pura: Cálculo matemático isolado."""
    return base + (base * (bonus_percentual / 100))

def imprimir_folha(nome, salario_final):
    """Procedimento: Especializado em exibição."""
    print(f"Funcionário: {nome:<10} | Salário Final: R$ {salario_final:>8.2f}")

def main():
    funcionarios = [
        {"nome": "João", "base": 2000},
        {"nome": "Maria", "base": 3500},
        {"nome": "Pedro", "base": 1800}
    ]
    
    print("=== FOLHA DE PAGAMENTO REFATORADA ===")
    for f in funcionarios:
        # Aplica a abstração procedural
        final = calcular_salario(f["base"], 10) # 10% de bónus
        imprimir_folha(f["nome"], final)

if __name__ == "__main__":
    main()