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
void InserirMusica(struct Musica **musica, char *nome);
int contarMusicas(struct Musica **musica, int cont);
void ListarMusicas(struct Musica **musica);


void main(void){
    setlocale(LC_ALL, "Portuguese");
    // // inicializando a lista.
    struct Musica *musica;
    Inicializar(&musica);

    // adicionando uma musica no inicio
    InserirMusica(&musica, "teste\n\n"); // envio manual de musicas
    InserirMusica(&musica, "teste2\n\n"); // envio manual de musicas
    InserirMusica(&musica, "teste"); // envio manual de musicas
    printf("%d \n",contarMusicas(&musica,0)); // conta e imprime a quantidade de musicas
    // printf("%s", &musica->nome);
    ListarMusicas(&musica);
    
}

// Inicializando a lista de musicas
void Inicializar(struct Musica **musica){
    *musica = NULL;
    printf("Lista de musicas inicializada\n\n");
}

// Inserindo musicas na lista
void InserirMusica(struct Musica **musica, char *nome){
    if(*musica == NULL){// verificar se o primeiros valor esta vazio
        *musica = (struct Musica *) malloc(sizeof(struct Musica)); // alocando dinamicamente baseado no tamanha da estrutura.
        strcpy((*musica)->nome, nome); // atribuindo o valor do char para o nome da estrutura. 
        (*musica)->proxima = NULL; // definindo o proximo item da lista como nulo
    }else{ // se nao estiver nulo aplicar a recursividade para tratar o proximo como inicio
        InserirMusica(&((*musica)->proxima), nome);
    }
}

int contarMusicas(struct Musica **musica, int cont){
    if(*musica != NULL){
        contarMusicas(&(*musica)->proxima, ++cont);
    }else{
        return cont;
    }
}

void ListarMusicas(struct Musica **musica){
    if((*musica) !=NULL){
        printf("%s, ",(*musica)->nome);
        if((*musica)->proxima !=NULL){
            ListarMusicas(&((*musica)->proxima));
        }
    }else{
        printf("A lista está vazia...");
    }
}


/* TODO
    arrumar os warning de formato no char nome[50] alterar para dinamico
    funcao listar musicas
    funcao para remover musicas de duas formas, por nome e por ordem
*/


void buscarMusica(){}

void removeMusica(){}
void modifMusica(){}

void lendoMusica(){}

