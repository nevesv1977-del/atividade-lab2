"""
ANÁLISE EXIGIDA:
Diferença de Execução:
- Sub-rotina Tradicional (Run-to-completion): Executa todo o código até o fim ou return.
- Corrotina (Yield): Suspende a execução, preserva o estado das variáveis locais 
  e devolve o controle ao chamador. Na próxima chamada, ela retoma exatamente de onde parou.
"""

def linha_montagem():
    print("[LOG] Iniciando Processamento...")
    
    yield "Peça 1: Soldagem concluída"
    # A função pausa aqui e mantém o estado
    
    yield "Peça 2: Pintura concluída"
    # A função pausa aqui e mantém o estado
    
    yield "Peça 3: Inspeção de Qualidade concluída"

# Programa Principal
gerador = linha_montagem()

print(next(gerador)) # Chama a corrotina
print("... Pausa no main para logística ...")
print(next(gerador)) # Retoma a corrotina
print(next(gerador))