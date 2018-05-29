#include <stdio.h>
#include <stdlib.h>

#include "hashTable.h"

int main()
{
    int procura_palavra = 0;
    arquivo("palavras.csv");

    //print_data("palavras.csv");

    /** testes **/
    procura_palavra = procura("usual");
    if (procura_palavra == -1)
        printf("Palavra nao encontrada\n");

    exclui_palavra("dad");

    print_data("palavras.csv");

    procura_palavra = procura("dad");
    if (procura_palavra == -1)
        printf("Palavra nao encontrada\n");

    return 0;
}
