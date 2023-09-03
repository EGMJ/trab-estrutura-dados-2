#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>

// criando uma estrutura de dados hoterogenea por enquanto
struct Musica{
    char nome[50];
    // int duracao;
    struct Musica *proxima;
};

// uma lista de musicas desnecessario
// struct ListaMusicas {
//     struct Musica *inicio;
//     struct Musica *fim; 
//     int tam; // tamanho da lista e da quantidade de musicas
// };

void main(void){
    setlocale(LC_ALL, "Portuguese");
    // // inicializando a lista.
    struct Musica *musica;
    Inicializar(&musica);

    // // adicionando uma musica no inicio
    // strcpy(listaDeMusicas.inicio->nome,"teste");
    // printf("%s",listaDeMusicas.inicio->nome);
    
}

// Inicializando a lista de musicas
void Inicializar(struct Musica **musica){
    *musica = NULL;
    printf("Lista de musicas inicializada");
}


// func que adciona uma musica no inicio da lista
// void InserirMusicaNaLista(struct ListaMusicas *playlist, char nome){
    // inicializar a struct Musicas dinamicamente
    // struct Musica *musica = malloc(sizeof(struct Musica));



// }



void buscarMusica(){}
void contarMusicas(){}

void removeMusica(){}
void modifMusica(){}


void lendoMusica(){}

