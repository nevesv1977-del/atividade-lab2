"""
ANÁLISE EXIGIDA:
Em Python, a passagem de argumentos segue o modelo 'Call-by-sharing'. 
1. Ao passar uma lista para uma função, não estamos passando uma cópia da lista, 
   mas sim uma referência ao mesmo objeto na memória (Heap).
2. Como listas são objetos MUTÁVEIS, qualquer alteração feita dentro da função 
   reflete instantaneamente no objeto original.
3. Isso explica por que o estoque original foi alterado irreversivelmente: a função 
   modificou o conteúdo do endereço de memória compartilhado.
"""

def aplicar_desconto(lista_produtos, porcentagem):
    """Aplica desconto alterando o objeto original (efeito colateral)."""
    for i in range(len(lista_produtos)):
        lista_produtos[i] = lista_produtos[i] - (lista_produtos[i] * (porcentagem / 100))
    print(f"Lista dentro da função após desconto: {lista_produtos}")

def main():
    # O estoque original
    estoque = [100.0, 250.0, 50.0, 1000.0]
    
    print(f"Estoque inicial no main: {estoque}")
    
    # Chamando a função
    aplicar_desconto(estoque, 10)
    
    print("\n--- Verificação de Mutabilidade ---")
    print(f"Estoque final no main:    {estoque}")
    print("AVISO: O estoque original foi modificado sem um comando de atribuição explícita!")

if __name__ == "__main__":
    main()