#include <stdio.h>
#include <malloc.h>
#include <locale.h>

typedef struct {
    int valor;
    struct Lista *proximo;
} Lista;

// Chamando as funcoes
void inicializar(Lista **lista); 
void inserirNaListaValor(Lista **lista, int x);
int qtdElementosNaLista(Lista **lista, int cont);
void exibirLista(Lista **lista);
void apagarLista(Lista **lista);
void removerValorLista (Lista **lista,int x);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    Lista *lista;
    inicializar(&lista);
    inserirNaListaValor(&lista, 5);
    // inserirNaListaValor(&lista, 10);
    // inserirNaListaValor(&lista, 12);
	// //apagarLista(&lista);
    exibirLista(&lista);
    // removerValorLista(&lista, 7
	
	// ,);
    // printf("\nA quantidade de elementos na lista é: %d\n", qtdElementosNaLista(&lista, 0));
    
    // return 0;
}

void inicializar(Lista **lista) {
    *lista = NULL;
    printf("\nLista Inicializada\n");
}

void inserirNaListaValor(Lista **lista, int x) { // Insere os valores da lista
    if (*lista == NULL) { // verifica se o primeiro valor é nulo
        *lista = (Lista *) malloc(sizeof(Lista)); // criando a memoria dinamica bazeada no tamanho
        (*lista)->valor = x; // criando a variavel
        (*lista)->proximo = NULL; // criando o ponteiro NULL
    } else { // se nao recursividade no codigo para cair no if
        inserirNaListaValor(&((*lista)->proximo), x);
    }
}

void exibirLista(Lista **lista){
	if(*lista != NULL){ // verifica se a lista nao é nula
		printf("%d, ", (*lista)->valor); // imprime o valor se nao for nula
		
		if((*lista)->proximo != NULL){ // verifica se o proximo vetor nao é vazio
			exibirLista(&((*lista)->proximo)); // se nao for ele faz a recursividade
		}else printf("\n"); //  se for vazia imprime nada
	}else{
		printf("\nLista vazia"); // se estiver vazia imprime vazia
	}
}

int qtdElementosNaLista(Lista **lista, int cont) { // Faz a contagem de elementos
    if (*lista != NULL) { // verifica se a lista nao é nula
        return qtdElementosNaLista(&((*lista)->proximo), ++cont); // retorna a logica, ++cont pois tem que contar antes pois tem que rodar primeiro para nao dar zero infinito
    } else {
        return cont; // retorna a contagem total
    }
}

void apagarLista(Lista **lista){
	if((*lista) != NULL){ // verifica se a lista nao é nula
		apagarLista(&((*lista)->proximo)); // percorre a lista
		free(*lista); // apaga o ultimo elemento
		(*lista) = NULL; // transforma o elemento em nulo
	} 
	// Cuidado, ao apagar o primeiro elemento voce perde a lista na memoria, pois voce mata a referencia dos outros elementos.
} 

void removerValorLista (Lista **lista,int x){
	Lista *aux;
	if ((*lista)!= NULL){
		if ((*lista)->valor ==x){
			if (((*lista)->proximo == NULL)){
				free (*lista);
				(*lista)=NULL;
			}else {
			aux = *lista;
			(*lista) = (*lista)-> proximo;
			free (aux);
			}
		}else{
			removerValorLista(&((*lista)->proximo), x);
		}
	}else{
		removerValorLista(&((*lista)->proximo),x);
	}
}

