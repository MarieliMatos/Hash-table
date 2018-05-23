#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

typedef struct data data_t;

data_t* arquivo(char* nome_arq);
void init_dados(data_t* dados);

int indice_elemento(data_t* dados, char* eng, char* pt, int tamanho);
int indice_quadratic_probing(int num, int i, int tamanho);
int conv_string(char* palavra);
#endif // HASHTABLE_H_INCLUDED
