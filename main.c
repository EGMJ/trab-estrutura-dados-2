#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>

// criando uma estrutura de dados hoterogenea por enquanto
struct Musica
{
    char nome[50];
    // int duracao;
};


void main(void){
    setlocale(LC_ALL, "Portuguese");
    struct Musica listaDeMusicas;

    strcpy(listaDeMusicas.nome,"teste");
    printf("%s",listaDeMusicas.nome);
    
}



void buscarMusica(){}
void contarMusicas(){}

void removeMusica(){}
void modifMusica(){}

void addMusica(){}

void lendoMusica(){}

