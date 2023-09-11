#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>

// criando uma estrutura de dados hoterogenea por enquanto ou o nó da lista
struct Musica{
    // char *nome;
    char nome[50];
    struct Musica *proxima;
};

// uma lista de musicas
struct Lista {
    struct Musica *inicio;
    struct Musica *fim; 
    int tam; // tamanho da lista e da quantidade de musicas
};

void inicializarLista(struct Lista *lista);
void inserirNoInicio(struct Lista *lista, char *nome);
void inserirNoFim(struct Lista *lista, char *nome);
struct Musica* removeMusica(struct Lista *lista, char *nome);
// struct Musica* buscarMusica(struct Lista *lista, char *nome);

void inserirMusica(struct Musica **musica, char *nome);
int contarMusicas(struct Musica **musica, int cont);
void listarMusicas(struct Lista lista);
void lendoMusica(char **nomeMusica);

void main(void){
    setlocale(LC_ALL, "Portuguese");
    // // inicializando a lista.
    struct Lista lista;
    inicializarLista(&lista);

    // inserirNoFim(&lista, "asdf3");
    // inserirNoFim(&lista, "asdf1");
    // inserirNoFim(&lista, "asdf2");
    inserirNoInicio(&lista, "teste3");
    inserirNoInicio(&lista, "teste2");
    inserirNoInicio(&lista, "teste1");


    listarMusicas(lista);

    // struct Musica *nomeAuxiliar = removeMusica(&lista, "asdf");
    //  char nomeAuxiliar = buscarMusica(&lista, "asdf");
    //  free(nomeAuxiliar->nome);

    printf("%d", lista.tam);
    // printf("%s", nomeAuxiliar);



    // // lendo e adicionando uma musica no inicio
    // lendoMusica(&nomeAuxiliar);
    // inserirMusica(&musica, nomeAuxiliar); // envio manual de musicas

    // lendoMusica(&nomeAuxiliar);
    // inserirMusica(&musica, nomeAuxiliar); // envio manual de musicas

    // lendoMusica(&nomeAuxiliar);
    // inserirMusica(&musica, nomeAuxiliar); // envio manual de musicas

    // lendoMusica(&nomeAuxiliar);
    // inserirMusica(&musica, nomeAuxiliar); // envio manual de musicas

    // printf("A quantidade de musicas na lista: %d\n",contarMusicas(&musica,0)); // conta e imprime a quantidade de musicas
 
    //listarMusicas(&musica);   
}

// Inicializando a lista de musicas
void inicializarLista(struct Lista *lista){
    // define o inicio da lista como nulo
    lista->inicio = NULL;
    // define o fim da lista como nulo
    lista->fim = NULL;
    // define o tamanho da lista como 0
    lista->tam = 0; 
    printf("Lista de musicas inicializada\n");
}
// para inserir a musica no inicio da lista
void inserirNoInicio(struct Lista *lista, char *nome){
    struct Musica *musica = (struct Musica *) malloc(sizeof(struct Musica)); // criando uma estrutura da musica ou do nó

    // se a estrutura da musica for criada
    if(musica){ 
        // musica->nome = strdup(nome);
        // atricuir o nome inserido ao nome da estrutura
        strcpy(musica->nome, nome); 
        // atribui o ponteiro inicio da lista para a proxoma musica 
        musica->proxima = lista->inicio;
        // atribui a estrutura musica ao inicio da lista
        lista->inicio = musica;
        // somente ira testar se é o primeiro item da lista
        if(lista->fim == NULL){
            lista->fim = musica;
        }
        // o fim aponta para a nova musica ou para o inicio da lista
        lista->fim->proxima = lista->inicio; 
        // aumenta o tamanho da lista que era zero
        lista->tam++;
    }else{
        printf("Erro na alocação de memória");
    }
}

void inserirNoFim(struct Lista *lista, char *nome){
    struct Musica *musica, *aux = (struct Musica *) malloc(sizeof(struct Musica));
    
    if(musica){
        // atribuindo o valor 
        strcpy(musica->nome, nome); 
        // se for nulo significa que estamo atribuindo o primeiro elemento
        if(lista->inicio == NULL){ 
            // crianco a primeira musica
            lista->inicio = musica;
            lista->fim = musica;
            // determinando que o fim aponte para o inicio da lista;
            lista->fim->proxima = lista->inicio;
        }else{
            // definido que o antigo fim aponte para a musica inserida (novo fim)
            lista->fim->proxima = musica;
            // definindo que o fim da lista é a nova musica
            lista->fim = musica;
            // definindo que o fim da lista (ultima musica) aponta para o inicio da lista (primeira musica)
            // lista->fim->proxima = lista->inicio;
            musica->proxima = lista->inicio;            
        }
        lista->tam++;
    }else{
        printf("Erra na alocação");
    }    
}

struct Musica* removeMusica(struct Lista *lista, char *nome){
    struct Musica *aux, *remover = NULL;
    if(lista->inicio){
        // se o inicio da lista for igual ao fim e igual ao nome significa que é o unico elemento na lista
        if(lista->inicio == lista->fim && lista->inicio->nome == nome){
            // Então tudo nela vira nulo.
            remover = lista->inicio;
            lista->fim = NULL;
            lista->inicio = NULL;
            lista->tam--;
        // agora se o inicio da lista for igual ao nome    
        }else if(lista->inicio->nome == nome){
            // o primeiro elemento da lista é removido
            remover = lista->inicio;
            // e o segundo elemento da lista passa a ser o primeiro
            lista->inicio = remover->proxima;
            // e o fim da lista que apontava para o item excluido aponta para o novo inicio
            lista->fim->proxima = lista->inicio;
            lista->tam--; 
        }else{
            // um nó auxiliar recebe o inicio da lista
            aux = lista->inicio;
            // enquato a proxima musica for direfente do inicio da lista e for diferente do nome
            while(aux->proxima != lista->inicio && aux->proxima->nome != nome){
                // a auxiliar recebe a proxima 
                aux = aux->proxima;
            }
            // agora quando a musica auxiliar for igual ao nome da musica selecionada
            if(aux->proxima->nome == nome){
                // e o fim da lista for igual a proxima
                if(lista->fim == aux->proxima){
                    // remove a proxima
                    remover = aux->proxima;
                    // e a lista é atualizada pois a proxima recebe a sua sucessora 
                    aux->proxima = remover->proxima;
                    // e o fim aponta para o novo inicio
                    lista->fim = aux;
                }else{
                    // se todas as condicoes estiverem erradas só remove a proxima
                    remover = aux->proxima;
                    // e atualiza a proxima musica pois o valor encontrado está no meio e não no inicio ou fim 
                    aux->proxima = remover->proxima;
                }
                lista->tam--;
            }
        }
    }
    return remover;
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

void listarMusicas(struct Lista lista){
    struct Musica *musica = lista.inicio;
    if(musica){
        do
        {
            printf("%s\n", musica->nome);
            musica = musica->proxima;
        } while (musica != lista.inicio);
        printf("\n Inicio: %s", lista.inicio);
        printf("\n Fim: %s", lista.fim);
        printf("\n Proxima do Fim (inicio): %s", lista.fim->proxima);

        printf("\n\n");

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

    
    PROBLEMA IDENTIFICADO:
        1. ao adicionar um item se só apertar enter entra como um item

*/


void lendoMusica(char **nomeMusica){
    char auxNome[200];

    /**
     * procedimento para escolher a musica um switch case com uma lista de varias musicas
     * e dependendo do valor selecionado atribui ao nome da musica
    */

    printf("Inserir nome da musica: ");
    fgets(auxNome,200,stdin);
    *nomeMusica = (char *) malloc(strlen(auxNome)*sizeof(char));
    strcpy(*nomeMusica, auxNome);
}

void modifMusica(){}

