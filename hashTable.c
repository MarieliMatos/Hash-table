#include <stdio.h>
#include <stdlib.h>#include <string.h>

#include "hashTable.h"

#define BUFFER_SIZE 96

struct data{
    char *eng;
    char *ptbr;
};

data_t* arquivo(char* nome_arq)
{
    data_t* dados;
    FILE* fp;
    char buffer[BUFFER_SIZE], buffer_eng[BUFFER_SIZE], buffer_pt[BUFFER_SIZE];
    int linha = 0, index = 0;

    // Abre o arquivo
    fp = fopen(nome_arq, "r");
    if (fp == NULL){
        perror("Erro em arquivo: fopen: ");
        exit(EXIT_FAILURE);
    }

    // Conta as linhas do arquivo
    while(fgets(buffer, 294, fp) != NULL)
        linha++;
     rewind(fp);

    // Aloca a memória para a struct data
    dados = (data_t*)malloc(sizeof(data_t)*linha);
    if (dados == NULL){
        perror("Erro em 'arquivo': ");
        exit(1);
    }
    init_dados(dados);      // Inicializa a struct

    // Lê os dados do arquivo
     while(fgets(buffer, 294, fp) != NULL){
        sscanf(buffer,"%50[^,],%50[^,]", buffer_eng, buffer_pt);
        index = indice_elemento(dados, buffer_eng, buffer_pt, linha);

        printf("%d      ", index);
        printf("%s\n", buffer_eng);
    }


    fclose(fp);
    return dados;
}

/**
    Função que insere elementos do arquivo

    Sistema de colisão: Quadratic Probing
**/
int indice_elemento(data_t* dados, char* eng, char* pt, int tamanho)
{
    int num = 0, i, index = 0;
    num = conv_string(eng);
    for(i=0; i<tamanho; i++){
        index = indice_quadratic_probing(num, i, tamanho);
        if (dados[index].eng == NULL){
            //dados[index].eng = eng;
            //printf("%s  \n",dados[index].eng);
            return index;
        }
    }
    return -1;
}

/** Função que retorna um indice **/
int indice_quadratic_probing(int num, int i, int tamanho)
{
    int index = 0;

    index = (num +(i*i))%tamanho;

    return index;
}

/** Converte a string em um valor inteiro **/
int conv_string(char* palavra)
{
    int tamanho = 0, i, num=0;
    char carac;
    tamanho = strlen(palavra);

    // Converte os valores dos caracteres em inteiros
    for(i=0; i<tamanho;i++){
        carac = palavra[i];
        num += carac;
    }
    return num;
}

/** Função que inicializa os dados da struct **/
void init_dados(data_t* dados){
    dados->eng = NULL;
    dados->ptbr = NULL;
}

