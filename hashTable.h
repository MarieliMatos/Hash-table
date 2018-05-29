#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

typedef struct data data_t;

int procura(char* eng);
void insere_elemento(char* eng, char* pt, int tamanho);
void exclui_palavra(char* palavra);

void arquivo(char* nome_arq);
int hash_code(char* palavra, int tamanho);
void print_data (char* nome_arq);
int tamanho_arquivo(char* nome_arq);
void libera_memoria();

#endif // HASHTABLE_H_INCLUDED
