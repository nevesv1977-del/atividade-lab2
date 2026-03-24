"""
ANÁLISE EXIGIDA:
1. Caso Base: Ocorre quando o valor da chave atual é igual ao 'alvo' buscado ou 
   quando esgotamos as chaves do dicionário atual sem encontrar subpastas.
2. Passo Recursivo: Ocorre quando encontramos um valor que é outro dicionário 
   (uma subpasta), fazendo a função chamar a si mesma para explorar esse novo nível.
"""

def buscar_arquivo(estrutura, alvo):
    for chave, valor in estrutura.items():
        # Caso Base 1: Encontrou o arquivo
        if chave == alvo:
            return f"Encontrado em: {valor}"
        
        # Passo Recursivo: Se for uma pasta (dicionário), mergulha nela
        if isinstance(valor, dict):
            resultado = buscar_arquivo(valor, alvo)
            if resultado: return resultado
            
    return None

# Estrutura de pastas aninhadas
sistema_arquivos = {
    "Documentos": {
        "Trabalho": {"relatorio.pdf": "C:/Docs/relatorio.pdf"},
        "Faculdade": {"lab_final.c": "C:/Docs/Faculdade/lab_final.c"}
    },
    "Imagens": {"foto.png": "C:/Imagens/foto.png"}
}

print("Buscando arquivo 'lab_final.c'...")
print(buscar_arquivo(sistema_arquivos, "lab_final.c"))