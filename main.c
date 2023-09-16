#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>

// criando uma estrutura de dados hoterogenea por enquanto ou o nó da lista
struct Musica
{
    char *nome;
    struct Musica *proxima;
};

// uma lista de musicas
struct Lista
{
    struct Musica *inicio;
    struct Musica *fim;
    int tam; // tamanho da lista e da quantidade de musicas
};

// Inicializando a lista de musicas
void inicializarLista(struct Lista *lista)
{
    // define o inicio da lista como nulo
    lista->inicio = NULL;
    // define o fim da lista como nulo
    lista->fim = NULL;
    // define o tamanho da lista como 0
    lista->tam = 0;
    printf("Lista de musicas inicializada\n");
    printf("\n------------------------------\n");
}

// para inserir a musica no inicio da lista
void inserirNoInicio(struct Lista *lista, char *nome)
{
    // criando uma estrutura da musica ou do nó
    struct Musica *musica = (struct Musica *)malloc(sizeof(struct Musica));

    // se a estrutura da musica for criada
    if (musica)
    {
        // atricuir o nome inserido ao nome da estrutura
        musica->nome = strdup(nome);

        // atribui o ponteiro inicio da lista para a proxoma musica
        musica->proxima = lista->inicio;

        // atribui a estrutura musica ao inicio da lista
        lista->inicio = musica;

        // somente ira testar se é o primeiro item da lista
        if (lista->fim == NULL)
        {
            lista->fim = musica;
        }

        // o fim aponta para a nova musica ou para o inicio da lista
        lista->fim->proxima = lista->inicio;
        lista->tam++;
    }
    else
    {
        printf("Erro na alocação de memória");
    }
}

// para inserir a musica no fim da lista
void inserirNoFim(struct Lista *lista, char *nome)
{
    struct Musica *musica = (struct Musica *)malloc(sizeof(struct Musica));

    if (musica)
    {
        // atribuindo o valor
        musica->nome = strdup(nome);
        // se for nulo significa que estamo atribuindo o primeiro elemento
        if (lista->inicio == NULL)
        {
            // crianco a primeira musica
            lista->inicio = musica;
            lista->fim = musica;
            // determinando que o fim aponte para o inicio da lista;
            lista->fim->proxima = lista->inicio;
        }
        else
        {
            // definido que o antigo fim aponte para a musica inserida (novo fim)
            lista->fim->proxima = musica;
            // definindo que o fim da lista é a nova musica
            lista->fim = musica;
            // definindo que o fim da lista (ultima musica) aponta para o inicio da lista (primeira musica)
            // lista->fim->proxima = lista->inicio;
            musica->proxima = lista->inicio;
        }
        lista->tam++;
    }
    else
    {
        printf("Erra na alocação");
    }
}

// para remover a musica da lista
struct Musica *removeMusica(struct Lista *lista, char *nome)
{
    struct Musica *aux, *remover = NULL;
    if (lista->inicio)
    {
        // se o inicio da lista for igual ao fim e igual ao nome significa que é o unico elemento na lista
        if (lista->inicio == lista->fim && strcmp(lista->inicio->nome, nome) == 0)
        {
            // Então tudo nela vira nulo.
            remover = lista->inicio;
            lista->fim = NULL;
            lista->inicio = NULL;
            lista->tam--;
            // agora se o inicio da lista for igual ao nome
        }
        else if (strcmp(lista->inicio->nome, nome) == 0)
        {
            // o primeiro elemento da lista é removido
            remover = lista->inicio;
            // e o segundo elemento da lista passa a ser o primeiro
            lista->inicio = remover->proxima;
            // e o fim da lista que apontava para o item excluido aponta para o novo inicio
            lista->fim->proxima = lista->inicio;
            lista->tam--;
        }
        else
        {
            // um nó auxiliar recebe o inicio da lista
            aux = lista->inicio;
            // enquato a proxima musica for direfente do inicio da lista e for diferente do nome
            while (aux->proxima != lista->inicio && strcmp(aux->proxima->nome, nome) != 0)
            {
                // a auxiliar recebe a proxima
                aux = aux->proxima;
            }
            // agora quando a musica auxiliar for igual ao nome da musica selecionada
            if (strcmp(aux->proxima->nome, nome) == 0)
            {
                // e o fim da lista for igual a proxima
                if (lista->fim == aux->proxima)
                {
                    // remove a proxima
                    remover = aux->proxima;
                    // e a lista é atualizada pois a proxima recebe a sua sucessora
                    aux->proxima = remover->proxima;
                    // e o fim aponta para o novo inicio
                    lista->fim = aux;
                }
                else
                {
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

// para listar as musicas
void listarMusicas(struct Lista lista)
{
    struct Musica *musica = lista.inicio;
    if (musica)
    {
        printf("A lista tem %d elementos, que são: ", lista.tam);
        do
        {
            printf("%s, ", musica->nome);
            musica = musica->proxima;
        } while (musica != lista.inicio);

        printf("\n\nInicio: %s, ", lista.inicio->nome);
        printf("Fim: %s, ", lista.fim->nome);
        printf("Proxima do Fim (inicio): %s", lista.fim->proxima->nome);
    }
    else
    {
        printf("A lista está vazia...");
    }
    printf("\n");
}

// para buscar uma musica
struct Musica *buscarMusica(struct Lista *lista, char *nome)
{
    struct Musica *aux = lista->inicio;
    if (aux)
    { // se ha uma lista
        do
        {
            if (strcmp(aux->nome, nome) == 0)
            {                     // verifica se tem alguma diferença entre as strings e se nao tiver
                return aux->nome; // retorna o nome no auxiliar
                // return aux; // retorna o auxiliar
            }
            aux = aux->proxima;
        } while (aux != lista->inicio);
    }
    return NULL;
}

// para ler a entrada da musica pelo usuario
char *lendoMusica()
{
    char auxNome[3000];
    fgets(auxNome, sizeof(auxNome), stdin);

    // // removendo a quebra de linha
    char *quebraLinha = strchr(auxNome, '\n');
    if (quebraLinha)
    {
        *quebraLinha = '\0';
    }
    char *nomeMusica = (char *)malloc((strlen(auxNome) + 1) * sizeof(char));
    char *nome = strdup(auxNome);
    return nome;
}

void menu(void)
{
    printf("\n0 - Sair");
    printf("\n1 - Inserir no Inicio");
    printf("\n2 - inserir no Fim");
    printf("\n3 - Remover");
    printf("\n4 - Listar");
    printf("\n5 - Buscar\n");
    printf("\nQual é a opção: ");
}

void main(void)
{
    // para finalizar o falta é a estrutura final para imprimir na tela um menu paro o usoario
    setlocale(LC_ALL, "Portuguese");

    // inicializando a lista.
    struct Lista lista;
    inicializarLista(&lista);

    int opcao;

    /*
    char *nomeTeste = lendoMusica();
    inserirNoFim(&lista, nomeTeste);
    char *nomeTeste1 = lendoMusica();
    inserirNoFim(&lista, nomeTeste1);
    char *nomeTeste2 = lendoMusica();
    inserirNoFim(&lista, nomeTeste2);

    // free(nomeTeste);
    inserirNoFim(&lista, "caves in");
    inserirNoFim(&lista, "Moça Tiee");

    // removeMusica(&lista, "caves in");
    // printf("\n\n");
    listarMusicas(lista);
    // printf("\n\n");

    char *nome1 = buscarMusica(&lista, "caves in");
    printf("\n\n O nome é:__ %s __ ", nome1);

    printf("\n\n");

    char *nome2 = buscarMusica(&lista, "Moça Tiee");
    printf("\n\n O nome é:__ %s __ ", nome2);

    printf("\n\n");
    listarMusicas(lista);

    //criando as variaveis
    // char *nomeMusica;
    // struct Musica *Removida;

    printf("Quantas musicas você quer inserir na lista? ");
    scanf("%d",&quant);

    for(i = 0; i <= quant; i++){
    // if(quant){
    printf("\nDigite o nome da musica a ser adicionada: ");
    lendoMusica(&nomeMusica);
    // inserirNoInicio(&lista, nomeMusica);
    // }

    }

    listarMusicas(lista);

    lendoMusica(&nomeMusica);
    inserirNoInicio(&lista, nomeMusica);
    lendoMusica(&nomeMusica);
    inserirNoInicio(&lista, nomeMusica);
    inserirNoInicio(&lista, "teste1");
    inserirNoInicio(&lista, "teste2");
    printf("tamanho da lista: %d", lista.tam);

    removeMusica(&lista, "teste1");
    listarMusicas(lista);

    printf("tamanho da lista: %d", lista.tam);
    */

    // criando o switch case
    do
    {
        menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            system("clear"); // para limpar o terminal de saida na linux para window é cls
            printf("Saindo do menu...");
            break;
        case 1:
            system("clear");
            printf("Inserir nome da musica: ");
            // lendoMusica(&nomeMusica);
            // lendoMusica();
            // char nomeAux = lendoMusica();
            // inserirNoInicio(&lista, &nomeAux);
            break;

        case 2:
            system("clear");
            printf("Inserir nome da musica: ");
            // lendoMusica(&nomeMusica);
            // inserirNoFim(&lista, nomeMusica);
            break;

        case 3:
            system("clear");
            printf("\n Digite o valor a ser removido: ");
            // lendoMusica(&nomeMusica);

            // strcmp(musicaRemovida->nome,nomeMusica);

            // Removida = removeMusica(&lista, nomeMusica);
            // if (Removida)
            // {
            // printf("Musica removida: %s", Removida->nome);
            // free(Removida);
            // }
            // else
            // {
            // printf("Elemento inesistente.\n");
            // }
            break;

        case 4:
            system("clear");
            // listarMusicas(lista);
            break;
        case 5:
            system("clear");

            printf("\n Digite o valor a ser buscado: ");
            // lendoMusica(&nomeMusica);
            // Removida = buscarMusica(&lista, nomeMusica);
            // if (Removida)
            // {
            // printf("Musica encontrada: %s\n", Removida->nome);
            // }
            // else
            // {
            printf("Musica inesistente.\n");
            // }

            break;
        default:
            system("clear");
            // if (opcao != 0)
            // {
            printf("\nOpção invalida\n");
            // }
            break;
        }

        // }
    } while (opcao);
}