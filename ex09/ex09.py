"""
ANÁLISE EXIGIDA:
A 'Lazy Evaluation' (Avaliação Preguiçosa) gera o dado apenas no momento em que 
ele é solicitado. Se carregássemos um log 'infinito' em uma lista, a memória RAM 
seria esgotada instantaneamente. Com o gerador, o custo de memória é constante (O(1)), 
independente do tamanho total dos dados.
"""

import time

def gerador_log_infinito():
    registro_id = 1
    while True:
        timestamp = time.strftime("%H:%M:%S")
        yield f"ID: {registro_id} | STATUS: OK | HORA: {timestamp}"
        registro_id += 1

def main():
    log = gerador_log_infinito()
    
    print("Lendo os primeiros 5 registros do log 'infinito':")
    for _ in range(5):
        print(next(log))
        time.sleep(0.5) # Simula tempo de leitura

if __name__ == "__main__":
    main()