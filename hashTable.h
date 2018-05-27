#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

typedef struct data data_t;

void procura(char* eng);
void insere_elemento(char* eng, char* pt, int tamanho);

void arquivo(char* nome_arq);
int hash_code(char* palavra, int tamanho);
void print_data (int tamanho);
int tamanho_arquivo(char* nome_arq);
void libera_memoria();

#endif // HASHTABLE_H_INCLUDED
