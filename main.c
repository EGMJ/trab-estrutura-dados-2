#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>

// criando uma estrutura de dados hoterogenea por enquanto ou o nó da lista
struct Musica{
    char *nome;
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
struct Musica* buscarMusica(struct Lista *lista, char *nome);
void listarMusicas(struct Lista lista);
void lendoMusica(char **nomeMusica);

void main(void){
    setlocale(LC_ALL, "Portuguese");

    // inicializando a lista.
    struct Lista lista;
    inicializarLista(&lista);

    // criando as variaveis
    int opcao;
    char *nomeMusica;
    struct Musica *musicaRemovida;

    // criando o switch case
    // do{
    //     printf("\n0 - Sair\n1 - Inserir no Inicio\n2 - inserir no Fim\n3 - Remover\n4 - Listar\n5 - Buscar\n");
    //     scanf("%d", &opcao);

        
    // } while (opcao != 0);

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
        // atricuir o nome inserido ao nome da estrutura
        musica->nome = strdup(nome);

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
        lista->tam++;
    }else{
        printf("Erro na alocação de memória");
    }
}

void inserirNoFim(struct Lista *lista, char *nome){
    struct Musica *musica = (struct Musica *) malloc(sizeof(struct Musica));
    
    if(musica){
        // atribuindo o valor 
        strncpy(musica->nome, nome,sizeof(musica->nome)); 
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
        if(lista->inicio == lista->fim && strcmp(lista->inicio->nome, nome) == 0){
            // Então tudo nela vira nulo.
            remover = lista->inicio;
            lista->fim = NULL;
            lista->inicio = NULL;
            lista->tam--;
        // agora se o inicio da lista for igual ao nome    
        }else if(strcmp(lista->inicio->nome, nome) == 0){
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
            while(aux->proxima != lista->inicio && strcmp(aux->proxima->nome, nome) != 0){
                // a auxiliar recebe a proxima 
                aux = aux->proxima;
            }
            // agora quando a musica auxiliar for igual ao nome da musica selecionada
            if(strcmp(aux->proxima->nome, nome) == 0){
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

void listarMusicas(struct Lista lista){
    struct Musica *musica = lista.inicio;
    if(musica){
        do
        {
            printf("%s, ", musica->nome);
            musica = musica->proxima;
        } while (musica != lista.inicio);
        printf("\n\nInicio: %s", lista.inicio->nome);
        printf("\nFim: %s", lista.fim->nome);
        printf("\nProxima do Fim (inicio): %s", lista.fim->proxima->nome);

        printf("\n\n");

    }else{
        printf("A lista está vazia...");
    }
}

struct Musica *buscarMusica(struct Lista *lista, char *nome){
    struct Musica *aux = lista->inicio;
    if(aux){ // se ha uma lista 
        do{
            if(strcmp(aux->nome, nome) == 0){ // verifica se tem alguma diferença entre as strings e se nao tiver
                return aux; // retorna o auxiliar
            }
            aux = aux->proxima;
        } while (aux != lista->inicio);
    }
    return NULL;
}

/* TODO     
    2. Adição de músicas sem ser manualmente atraves de um switch case
    3. Ajustar a funcao inserir no final
    4. Ajustar a funcao Lendo musica

    PROBLEMA IDENTIFICADO:
    1. ao adicionar um item se só apertar enter entra como um item
*/

void lendoMusica(char **nomeMusica){
    char auxNome[3000];
    printf("Inserir nome da musica: ");
    fgets(auxNome, sizeof(auxNome),stdin);
    *nomeMusica = (char *)malloc((strlen(auxNome) + 1) * sizeof(char));
    strcpy(*nomeMusica, auxNome);
}
