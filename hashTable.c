#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashTable.h"

#define BUFFER_SIZE 96
#define DEBUG
#define NOME_ARQ "palavras.csv"

struct data
{
    char *eng;
    char *ptbr;
};

data_t* array_dados[294];               // Vetor estatico

void arquivo(char* nome_arq)
{
    FILE* fp;
    char buffer[BUFFER_SIZE], buffer_eng[BUFFER_SIZE], buffer_pt[BUFFER_SIZE];
    int tamanho_arq = 0;

    // Abre o arquivo
    fp = fopen(NOME_ARQ, "r");
    if (fp == NULL)
    {
        perror("Erro em arquivo: fopen: ");
        exit(EXIT_FAILURE);
    }

    // Tamanho do arquivo
    tamanho_arq = tamanho_arquivo(NOME_ARQ);

    rewind(fp);


    // Lê os dados do arquivo
    while(fgets(buffer, BUFFER_SIZE, fp) != NULL)
    {
        sscanf(buffer,"%50[^,],%50[^,]", buffer_eng, buffer_pt);
        //printf("%s, %s \n", buffer_eng, buffer_pt);
        insere_elemento(buffer_eng, buffer_pt, tamanho_arq);
    }
    fclose(fp);
}

/**
    Função que insere elementos do arquivo

    Sistema de colisão: Linear Probing
**/
void insere_elemento(char* eng, char* pt, int tamanho)
{
    data_t* dados = (data_t*)malloc(sizeof(data_t));

    int index = 0, tam=0, tam2=0;

    tam = strlen(eng);
    dados->eng = malloc(tam+1);
    strcpy(dados->eng, eng);

    tam2 = strlen(pt);
    dados->ptbr = malloc(tam2+1);
    strcpy(dados->ptbr, pt);

    index = hash_code(eng, tamanho);

    while (array_dados[index] != NULL)
        index++;

    array_dados[index] = dados;

#ifndef DEBUG
    printf("%d  %s   %s\n", index, dados->eng, dados->ptbr);
#endif // DEBUG
}

/** Função que cria uma hash **/
int hash_code(char* palavra, int tamanho)
{
    int tam = 0, i, num=0, index=0;
    char carac;
    tam = strlen(palavra);

    // Converte os valores dos caracteres em inteiros
    for(i=0; i<tam; i++)
    {
        carac = palavra[i];
        num += carac;
    }
    index = num%tamanho;
#ifndef DEBUG
    printf("%d\n", index);
#endif // DEBUG
    return index;
}

/**   Função de procura  **/
int procura(char* eng)
{
    int index = 0;

    // Pega o valor do hash da palavra
    index = hash_code(eng, tamanho_arquivo(NOME_ARQ));

    while(array_dados[index] != NULL)
    {
        if(strcmp(array_dados[index]->eng, eng) == 0)
        {
            printf("Palavra:  %s\n", array_dados[index]->eng);
            printf("Traducao: %s\n", array_dados[index]->ptbr);
            return 0;
        }
        index++;
    }
    return -1;
}

/** Funcao que deleta palavra **/
void exclui_palavra(char* palavra)
{
    int index = 0, conf = 0;

    // struct para substituir dado excluido
    data_t* del_data = (data_t*)malloc(sizeof(data_t));
    del_data->eng = " ";
    del_data->ptbr = " ";

    index = hash_code(palavra, tamanho_arquivo(NOME_ARQ));

    while(array_dados[index] != NULL)
    {
        if(strcmp(array_dados[index]->eng, palavra) == 0)
            array_dados[index] = del_data;
        index++;
    }
    // Confere se a palavra foi excluida
    conf = procura(palavra);
    if(conf == -1)
        printf("Palavra excluida com sucesso!\n");
}

/**  Função que retorna o tamanho do arquivo  **/
int tamanho_arquivo(char* nome_arq)
{
    FILE* fp;
    int tamanho_arq = 0;
    char buffer[BUFFER_SIZE];
    // Abre o arquivo
    fp = fopen(nome_arq, "r");
    if (fp == NULL)
    {
        perror("Erro em arquivo: fopen: ");
        exit(EXIT_FAILURE);
    }

    // Tamanho do arquivo
    while(fgets(buffer, 294, fp) != NULL)
        tamanho_arq++;

    return tamanho_arq;
}

/**  Função que imprime os dados da struct **/
void print_data (char* nome_arq)
{
    int i, tamanho = 0;

    tamanho = tamanho_arquivo(nome_arq);

    for(i = 0; i<tamanho; i++)
    {
        if(array_dados[i] != NULL)
            printf("%d  %s     %s\n", i, array_dados[i]->eng, array_dados[i]->ptbr);
        else
            printf("(vazio)\n");
    }
}

void libera_memoria()
{
    int tamanho = 0,i;

    tamanho = tamanho_arquivo(NOME_ARQ);

    for (i=0; i<tamanho;  i++){
        free(array_dados[i]->eng);
        free(array_dados[i]->ptbr);
    }
}
