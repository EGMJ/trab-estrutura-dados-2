#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>

// criando uma estrutura de dados hoterogenea por enquanto
struct Musica{
    // char *nome;
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
void inserirMusica(struct Musica **musica, char *nome);
int contarMusicas(struct Musica **musica, int cont);
void listarMusicas(struct Musica **musica);
void lendoMusica(char **nomeMusica);

void main(void){
    setlocale(LC_ALL, "Portuguese");
    // // inicializando a lista.
    struct Musica *musica;
    Inicializar(&musica);

    char *nomeAuxiliar;

    lendoMusica(&nomeAuxiliar);

    // strcpy((musica)->nome, nomeAuxiliar); // atribuindo o valor do char para o nome da estrutura. 
    inserirMusica(&musica, nomeAuxiliar); // envio manual de musicas

    // adicionando uma musica no inicio
    // inserirMusica(&musica, "teste1\n"); // envio manual de musicas
    // inserirMusica(&musica, "teste2\n"); // envio manual de musicas
    // inserirMusica(&musica, "teste3"); // envio manual de musicas
    
    // inserirMusica(&musica, musica->nome); // envio manual de musicas

    // printf("teste de imprecao %s", nomeTeste);

    // inserirMusica(&musica, nome   Teste); // envio manual de musicas
    printf("A quantidade de musicas na lista: %d\n",contarMusicas(&musica,0)); // conta e imprime a quantidade de musicas
 
    listarMusicas(&musica);   
}

// Inicializando a lista de musicas
void Inicializar(struct Musica **musica){
    *musica = NULL;
    printf("Lista de musicas inicializada\n\n");
}

// Inserindo musicas na lista
void inserirMusica(struct Musica **musica, char *nome){
    if(*musica == NULL){// verificar se o primeiros valor esta vazio
        *musica = (struct Musica *) malloc(sizeof(struct Musica)); // alocando dinamicamente baseado no tamanha da estrutura.
        strcpy((*musica)->nome, nome); // atribuindo o valor do char para o nome da estrutura. 
        (*musica)->proxima = NULL; // definindo o proximo item da lista como nulo
    }else{ // se nao estiver nulo aplicar a recursividade para tratar o proximo como inicio
        inserirMusica(&((*musica)->proxima), nome);
    }
}

int contarMusicas(struct Musica **musica, int cont){
    if(*musica != NULL){
        contarMusicas(&(*musica)->proxima, ++cont);
    }else{
        return cont;
    }
}

void listarMusicas(struct Musica **musica){
    if((*musica) !=NULL){
        printf("%s, ",(*musica)->nome);
        if((*musica)->proxima !=NULL){
            listarMusicas(&((*musica)->proxima));
        }
    }else{
        printf("A lista está vazia...");
    }
}


/* TODO
    arrumar os warning de formato no char nome[50] alterar para dinamico

        1. Alocação de memória dinâmica para as músicas inseridas
        
        2. Uma função de busca de músicas por nomes
        
        4. Remoção de músicas por nome ou por ordem        

        5. Adição de músicas sem ser manualmente
      
        6. A última música aponta para a primeira música da lista.
*/


void lendoMusica(char **nomeMusica){
    char auxNome[200];

    /**
     * procedimento para escolher a musica um switch case com uma lista de varias musicas
     * e dependendo do valor selecionado atribui ao nome da musica
    */

    printf("Inserir nome da musica: \n");
    fgets(auxNome,200,stdin);
    *nomeMusica = (char *) malloc(strlen(auxNome)*sizeof(char));
    strcpy(*nomeMusica, auxNome);
}

void buscarMusica(){}
void removeMusica(){}
void modifMusica(){}

