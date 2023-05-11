/**

    Conversao de Base:

        Bases: 
            [BIN]ario ............. Base  2
            [OCT]adecimal ......... Base  8
            [DEC]imal ............. Base 10
            [HEX]adecimal ......... Base 16

        Possibilidades de conversao:

            Para calcular o numero de permutacoes de conversoes de 2 elementos 
            escolhidos entre 4 bases numericas, podemos utilizar a formula:
        
                P(n, r) = n! / (n - r)!
        
            Onde:

                n e o numero total de elementos (4 bases numericas)
                r e o numero de elementos selecionados (grupo de 2 bases)

            Nesse caso, temos:

                n = 4 (bases numericas)
                r = 2 (grupo de 2 bases) ex.: BIN TO DEC, DEC TO HEX ...

            Aplicando na formula de permutacao, temos:

                P(4, 2) = 4! / (4 - 2)!
                = 4! / 2!
                = (4 * 3 * 2 * 1) / (2 * 1)
                = 24 / 2
                = 12

    Portanto, existem 12 permutacoes possiveis para 2 bases numericas 
    escolhidas entre 4 bases diferentes.

        01 - DEC - HEX
        02 - DEC - OCT
        03 - DEC - BIN

        04 - BIN - DEC
        05 - BIN - HEX
        06 - BIN - OCT

        07 - HEX - DEC
        08 - HEX - OCT
        09 - HEX - BIN

        10 - OCT - DEC
        11 - OCT - HEX
        12 - OCT - BIN

    Compilar: 

        gcc -o conversao conversao.c

    Mauricio Portela Pires <mauricioportelapires at gmail dot com>

**/

#include <stdio.h>
#include <math.h>
#include <string.h>

// -----------------------------------------------------------------------------
// 01 - DECimal para HEXadecimal
// -----------------------------------------------------------------------------
void decimalParaHexadecimal(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }
    int resto;
    char hexadecimal[100];
    int i = 0;
    while (decimal > 0) {
        resto = decimal % 16;
        if (resto < 10) {
            hexadecimal[i] = resto + '0';
        } else {
            hexadecimal[i] = resto - 10 + 'A';
        }
        decimal /= 16;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
}


// -----------------------------------------------------------------------------
// 02 - DECimal para OCTadecimal
// -----------------------------------------------------------------------------
void decimalParaOctal(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }
    int resto;
    int octal[100];
    int i = 0;
    while (decimal > 0) {
        resto = decimal % 8;
        octal[i] = resto;
        decimal /= 8;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
}


// -----------------------------------------------------------------------------
// 03 - DECimal para BINario
// -----------------------------------------------------------------------------
void decimalParaBinario(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    } else if (decimal == 1) {
        printf("1");
        return;
    }
    decimalParaBinario(decimal / 2);
    printf("%d", decimal % 2);
}


// -----------------------------------------------------------------------------
// 04 - BINario para DECimal
// -----------------------------------------------------------------------------
// Funcao para converter um valor binario em decimal
int binParaDecimal(char *binario) {
    int comprimento = strlen(binario);
    int decimal = 0;
    int peso = 1;
    for (int i = comprimento - 1; i >= 0; i--) {
        if (binario[i] == '1') {
            decimal += peso;
        }
        peso *= 2;
    }
    return decimal;
}


// -----------------------------------------------------------------------------
// 05 - BINario para HEXadecimal
// -----------------------------------------------------------------------------
char binToHex(char *bin) {
    int decimal = 0;
    int potencia = 0;
    // Converte o valor binario para decimal
    while (*bin != '\0') {
        decimal += (*bin - '0') * pow(2, 3 - potencia);
        bin++;
        potencia++;
        if (potencia == 4) {
            // Converte o decimal para um digito hexadecimal correspondente
            if (decimal >= 0 && decimal <= 9) {
                putchar(decimal + '0');
            } else {
                putchar(decimal - 10 + 'A');
            }
            decimal = 0;
            potencia = 0;
        }
    }
    return decimal;
}


// -----------------------------------------------------------------------------
// 06 - BINario para OCTadecimal
// -----------------------------------------------------------------------------
// Funcao auxiliar para converter um digito binario em octal
char binDigitToOctal(char *binDigit) {
    int decimal = strtol(binDigit, NULL, 2); // Converte o digito binario para decimal
    char octalDigit[2];
    sprintf(octalDigit, "%o", decimal); // Converte o decimal para octal
    return octalDigit[0]; // Retorna apenas o primeiro digito octal
}

// Funcao para converter um valor binario em octal
char* binToOctal(char *bin) {
    int len = strlen(bin);
    int octalLen = (len + 2) / 3; // Calcula o tamanho necessário para a string octal
    char *octal = (char*) malloc((octalLen + 1) * sizeof(char)); // Aloca memória para a string octal
    octal[octalLen] = '\0'; // Adiciona o caractere nulo ao final da string
    int i, j;
    for (i = len - 1, j = octalLen - 1; i >= 0; i -= 3, j--) {
        char binDigit[4];
        strncpy(binDigit, bin + i - 2, 3); // Copia 3 dígitos binários de cada vez
        octal[j] = binDigitToOctal(binDigit); // Converte os dígitos binários em um dígito octal
    }
    return octal;
}


// -----------------------------------------------------------------------------
// 07 - HEXadecimal para DECimal
// -----------------------------------------------------------------------------
int hexParaDecimal(char hex[]) {
    int decimal = 0;
    int tamanho = 0;
    // Calcula o tamanho da string hexadecimal
    while (hex[tamanho] != '\0') {
        tamanho++;
    }
    // Converte cada digito hexadecimal para decimal
    int potencia = 0;
    for (int i = tamanho - 1; i >= 0; i--) {
        int digito;
        // Converte caracteres '0'-'9' para seus valores decimais correspondentes
        if (hex[i] >= '0' && hex[i] <= '9') {
            digito = hex[i] - '0';
        }
        // Converte caracteres 'A'-'F' para seus valores decimais correspondentes
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digito = hex[i] - 'A' + 10;
        }
        // Converte caracteres 'a'-'f' para seus valores decimais correspondentes
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digito = hex[i] - 'a' + 10;
        }
        // Ignora outros caracteres invalidos
        else {
            continue;
        }
        decimal += digito * pow(16, potencia);
        potencia++;
    }
    return decimal;
}


// -----------------------------------------------------------------------------
// 08 - HEXadecimal para OCTadecimal
// -----------------------------------------------------------------------------
int hexToOctal(char hex[]) {
    int decimal = 0, octal = 0, potencia = 0;
    // Convertendo o valor hexadecimal para decimal
    for (int i = 0; hex[i] != '\0'; i++) {
        // Convertendo caracteres '0'-'9' para seus valores decimais correspondentes
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal = decimal * 16 + (hex[i] - '0');
        }
        // Convertendo caracteres 'A'-'F' para seus valores decimais correspondentes
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal = decimal * 16 + (hex[i] - 'A' + 10);
        }
        // Convertendo caracteres 'a'-'f' para seus valores decimais correspondentes
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal = decimal * 16 + (hex[i] - 'a' + 10);
        }
    }
    // Convertendo o valor decimal para octal
    while (decimal != 0) {
        octal += (decimal % 8) * pow(10, potencia);
        decimal /= 8;
        potencia++;
    }
    return octal;
}

// -----------------------------------------------------------------------------
// 09 - HEXadecimal para BINario
// -----------------------------------------------------------------------------
// Funcao para converter um caractere hexadecimal em um valor decimal correspondente
int hexToDec(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else {
        return -1;
    }
}

// Funcao para converter um valor hexadecimal em um valor binario correspondente
void hexToBinary(char hex[], char binary[]) {
    int decimal = 0, index = 0;
    // Convertendo o valor hexadecimal para decimal
    for (int i = strlen(hex) - 1; i >= 0; i--) {
        int dec = hexToDec(hex[i]);
        if (dec == -1) {
            printf("Valor hexadecimal invalido: %c\n", hex[i]);
            return;
        }
        decimal += dec * (1 << (4 * index));
        index++;
    }
    // Convertendo o valor decimal para binario
    int binaryIndex = 0;
    while (decimal > 0) {
        binary[binaryIndex++] = decimal % 2 + '0';
        decimal /= 2;
    }
    binary[binaryIndex] = '\0';
    // Invertendo a string de binario resultante
    int len = strlen(binary);
    for (int i = 0; i < len / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }
}

// -----------------------------------------------------------------------------
// 10 - OCTadecimal para DECimal
// -----------------------------------------------------------------------------
int octalParaDecimal(int octal) {
    int decimal = 0;
    int potencia = 0;
    while (octal != 0) {
        int digito = octal % 10;
        decimal += digito * (1 << (3 * potencia));
        octal /= 10;
        potencia++;
    }
    return decimal;
}


// -----------------------------------------------------------------------------
// 11 - OCTadecimal para HEXadecimal
// -----------------------------------------------------------------------------
// Funcao para converter um valor octal em um valor hexadecimal correspondente
void octToHex(char octal[], char hexadecimal[]) {
    int decimal = 0, index = 0;
    // Convertendo o valor octal para decimal
    for (int i = strlen(octal) - 1; i >= 0; i--) {
        int oct = octal[i] - '0';
        decimal += oct * pow(8, index);
        index++;
    }
    // Convertendo o valor decimal para hexadecimal
    int hexIndex = 0;
    while (decimal > 0) {
        int rem = decimal % 16;
        if (rem < 10) {
            hexadecimal[hexIndex++] = rem + '0';
        } else {
            hexadecimal[hexIndex++] = rem - 10 + 'A';
        }
        decimal /= 16;
    }
    hexadecimal[hexIndex] = '\0';
    // Invertendo a string hexadecimal resultante
    int len = strlen(hexadecimal);
    for (int i = 0; i < len / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[len - i - 1];
        hexadecimal[len - i - 1] = temp;
    }
}


// -----------------------------------------------------------------------------
// 12 - OCTadecimal para BINario
// -----------------------------------------------------------------------------
// Funcao para converter um caractere octal em um valor decimal correspondente
int octToDec(char oct) {
    return oct - '0';
}

// Funcao para converter um valor octal em um valor binario correspondente
void octToBinary(char octal[], char binary[]) {
    int decimal = 0, index = 0;
    // Convertendo o valor octal para decimal
    for (int i = strlen(octal) - 1; i >= 0; i--) {
        int oct = octToDec(octal[i]);
        decimal += oct * pow(8, index);
        index++;
    }
    // Convertendo o valor decimal para binario
    int binaryIndex = 0;
    while (decimal > 0) {
        binary[binaryIndex++] = decimal % 2 + '0';
        decimal /= 2;
    }
    binary[binaryIndex] = '\0';
    // Invertendo a string binaria resultante
    int len = strlen(binary);
    for (int i = 0; i < len / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }
}


// -----------------------------------------------------------------------------
// Menu Principal
// -----------------------------------------------------------------------------
int main() {
    int primeiraBase, segundaBase;
    int decimal, octal;
    char binario[100];
    char hexadecimal[100];
    char octal_str[100];
    printf("*** Conversor de Base ***\n");
    printf("por Mauricio Portela Pires\n\n");
    printf("Escolha a primeira base:\n");

    printf("1. DECimal\n");
    printf("2. BINario\n");
    printf("3. OCTadecimal\n");
    printf("4. HEXadecimal\n");
    scanf("%d", &primeiraBase);

    printf("\nEscolha a segunda base:\n");
    if (primeiraBase == 1) {
        printf("DEC para :\n");
        printf("2. BIN\n");
        printf("3. OCT\n");
        printf("4. HEX\n");
        scanf("%d", &segundaBase);
    } else if (primeiraBase == 2) {
        printf("BIN para :\n");
        printf("1. DEC\n");
        printf("3. OCT\n");
        printf("4. HEX\n");
        scanf("%d", &segundaBase);
    } else if (primeiraBase == 3) {
        printf("OCT para :\n");
        printf("1. DEC\n");
        printf("2. BIN\n");
        printf("4. HEX\n");
        scanf("%d", &segundaBase);
    } else if (primeiraBase == 4) {
        printf("HEX para :\n");
        printf("1. DEC\n");
        printf("2. BIN\n");
        printf("3. OCT\n");
        scanf("%d", &segundaBase);
    } else {
        printf("Combinacao invalida!\n");
    }

    if (primeiraBase == 1) {
        if (segundaBase == 2) {
            printf("DEC: ");
            scanf("%d", &decimal);
            printf("BIN: ");
            decimalParaBinario(decimal);
            printf("\n");
        } else if (segundaBase == 3) {
            printf("DEC: ");
            scanf("%d", &decimal);
            printf("OCT: ");
            decimalParaOctal(decimal);
            printf("\n");
        } else if (segundaBase == 4) {
            printf("DEC: ");
            scanf("%d", &decimal);
            printf("HEX: ");
            decimalParaHexadecimal(decimal);
            printf("\n");
        } else {
            printf("Combinacao invalida!\n");
        }
    } else if (primeiraBase == 2) {
        if (segundaBase == 1) {
            printf("BIN: ");
            scanf("%s", binario);
            int decimal = binParaDecimal(binario);
            printf("DEC: %d\n", decimal);
        } else if (segundaBase == 2) {
            printf("BIN: ");
            scanf("%s", binario);
            printf("HEX: ");
            binToHex(binario);
            printf("\n");
        } else if (segundaBase == 3) {
            printf("BIN: ");
            scanf("%s", binario);
            char *octal = binToOctal(binario);
            printf("OCT: %s\n", octal);
            free(octal); // Libera a memoria alocada para a string octal
        } else {
            printf("Combinacao invalida!\n");
        }
    } else if (primeiraBase == 3) {
        if (segundaBase == 1) {
            printf("OCT: ");
            scanf("%d", &octal);
            int decimal = octalParaDecimal(octal);
            printf("DEC: %d\n", decimal);
        } else if (segundaBase == 3) {
            printf("OCT: ");
            scanf("%s", octal_str);
            octToBinary(octal_str, binario);
            printf("BIN: %s\n", binario);
        } else if (segundaBase == 4) {
            printf("OCT: ");
            scanf("%s", octal_str);
            octToHex(octal_str, hexadecimal);
            printf("HEX: %s\n", hexadecimal);
        } else {
            printf("Combinacao invalida!\n");
        }
    } else if (primeiraBase == 4) {
        if (segundaBase == 1) {
            printf("HEX: ");
            scanf("%s", hexadecimal);
            int decimal = hexParaDecimal(hexadecimal);
            printf("DEC: %d\n", decimal);
        } else if (segundaBase == 2) {
            printf("HEX: ");
            scanf("%s", hexadecimal);
            hexToBinary(hexadecimal, binario);
            printf("BIN: %s\n", binario);
            printf("\n");
        } else if (segundaBase == 3) {
            printf("HEX: ");
            scanf("%s", hexadecimal);
            int octal = hexToOctal(hexadecimal);
            printf("OCT: %d\n", octal);
        } else {
            printf("Combinacao invalida!\n");
        }
    } else {
        printf("Combinacao invalida!\n");
    }
    return 0;
}
