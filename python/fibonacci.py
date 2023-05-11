#
# Mauricio P Pires
# Python 3.10.9
#

import portela

#
# Sequencia Fibinacci
# Função para retorna o valor de um determinado termo
# Criterios:
#
# Entrada: Valores aceitos:
#    1) numeros inteiros positivos
# Saida:
#    1) se entrada de (n) > 1, valor de saida é a soma de (n -1) + (n -2);
#    2) senao, valor de saida será (n)
#    3) se valor de (n) for negativo, o valor de saída será None
#

def cabecalho():
    print("Mauricio P Pires")
    print(sys.version)
    print("-"*80)
    print("")

def fib(n):
    return None if n < 0 else fib(n -1) + fib(n -2) if n > 1 else n

if __name__ == "__main__":
    portela.cabecalho()
    # Testando com uma sequencia que
    # comeca em -15, passando por 0 (zero)
    # e chegando a 15.
    for x in range(-15,15):
        # Se os valores de 'x' forem < 0, nao mostrar na tela.
        print("Termo: {} \tValor: {}".format(x if x > -1 else None,fib(x))) if x > -1 else None
