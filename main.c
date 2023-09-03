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

void Inicializar(struct Musica **musica);
void InserirMusica(struct Musica **musica, char nome);


void main(void){
    setlocale(LC_ALL, "Portuguese");
    // // inicializando a lista.
    struct Musica *musica;
    Inicializar(&musica);
    InserirMusica(&musica, 'a'); // NAO consigo enviar um texto
    // // adicionando uma musica no inicio
    // strcpy(listaDeMusicas.inicio->nome,"teste");
    // printf("%s",listaDeMusicas.inicio->nome);
    
}

// Inicializando a lista de musicas
void Inicializar(struct Musica **musica){
    *musica = NULL;
    printf("Lista de musicas inicializada");
}

// Inserindo musicas na lista
void InserirMusica(struct Musica **musica, char nome){
    // verificar se o primeiros valor esta vazio
    if(*musica == NULL){
        // alocando dinamicamente baseado no tamanha da estrutura.
        *musica = (struct Musica *) malloc(sizeof(struct Musica));
        // atribuindo o valor
        (*musica)->nome = nome;
        // definindo o proximo item da lista como nulo 
        (*musica)->proxima = NULL;
    }
    else{ // se nao estiver nulo aplicar a recursividade para tratar o proximo como inicio
        InserirMusica(&((*musica)->proxima), nome);
    }
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

