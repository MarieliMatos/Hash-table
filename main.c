#include <stdio.h>
#include <stdlib.h>

#include "hashTable.h"

int main()
{
   int procura_palavra = 0, menu;
    char palavra[60], excluir[60], op;
    arquivo("palavras.csv");

    setlocale(LC_ALL, "Portuguese");

    system("cls");
    printf("\tDicionário Inglês/Português\n");
    printf("1 - Tradução\n");
    printf("2 - Mostrar todas as traduções\n");
    printf("3 - Excluir palavra\n");
    printf("4 - Sair\n");
    scanf("%d", &menu);

    switch(menu)
    {
    case 1:
        system("cls");
        printf("Inserir palavra: ");
        fflush(stdin);
        gets(palavra);

        procura_palavra = procura(palavra);

        if (procura_palavra == -1)
            printf("Palavra nao encontrada\n");
        printf("\nRetornar ao menu? <s>  <n>\n");
        fflush(stdin);
        scanf("%c", &op);
        if (op == 's' || 'S')
            return main();
        else
            break;

    case 2:
        system("cls");
        print_data("palavras.csv");

        printf("\nRetornar ao menu? <s>  <n>\n");
        fflush(stdin);
        scanf("%c", &op);
        if (op == 's' || 'S')
            return main();
        else
            break;

    case 3:
        system("cls");
        printf("Inserir palavra: ");
        fflush(stdin);
        gets(excluir);

        exclui_palavra(excluir);

        printf("\nRetornar ao menu? <s>  <n>\n");
        fflush(stdin);
        scanf("%c", &op);
        if (op == 's')
            return main();
        else
            system("cls");
            break;
    case 4:
        break;
    }


    return 0;
}
