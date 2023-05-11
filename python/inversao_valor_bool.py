import portela

if __name__ == "__main__":
    portela.cabecalho()
    print("Inversao de Valor Booleano\n")
    
    print("*** Variavel do tipo booleano ***")

    # Variavel eh inicializada como Verdadeiro
    b = True
    print("Valor de 'b' = {}".format(b))

    for y in range(5):
        # A cada passada o valor será alternado:
        # Famoso "Liga-Desliga"
        b = not b
        print("... Valor de 'b' = {}".format(b))

    print("")

    print("*** Lista com elementos booleanos ***")
    lista_bool = [True, True, False, True, False]
    print("Lista ORIGINAL : {}".format(lista_bool))
    print("Lista INVERTIDA: {}".format([not elemento for elemento in lista_bool]))

    #
    # Alternativa encontrada antes:
    # usa o modulo 'numpy'
    #
    # import numpy as np
    # lista_bool = np.array([True, True, False, True, False])
    # lista_bool = np.logical_not(lista_bool)
    # print(lista_bool)
    #
