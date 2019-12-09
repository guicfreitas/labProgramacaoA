#include <stdio.h>
#include <stdlib.h>

/* Sugestao de estrutura de dados para guardar a lista de programa
 * e os programas. Voce pode alterar essa estrutura como quiser,
 * mas deve implementar uma lista circular encadeada.
 */
typedef struct programa Programa;
struct programa {
    char nome[81];
    int tempo_restante;
    Programa *prox;
};

typedef struct lista Lista;
struct lista {
    Programa *inicio;
    Programa *fim;
};


/* Sugestao de funcao para criar uma lista. Voce pode
 * alterar, usar ou remover esta funcao.
 */
Lista *criar_lista(void)
{
	Lista *nova = malloc(sizeof *nova);
	nova->inicio = nova->fim = NULL;
	return nova;
}


/* Sugestao de funcao para ler a descricao de um programa e
 * retornar um novo no' para ele. Voce pode usar, modificar
 * ou remover esta funcao.
 */
Programa *ler_programa(void)
{
	Programa *novo = malloc(sizeof *novo);
	
	// Leitura do nome do programa
	scanf("%80s", novo->nome);
	
	// Leitura do tempo total de execucao do programa
	scanf("%d", &novo->tempo_restante);
	
	// Atribui um valor inicial para o ponteiro prox
	novo->prox = NULL;
	
	return novo;
}

void inserir_fim(Lista *lis, Programa* novo){
	if(lis->fim!=NULL){
		Programa* fim=lis->fim;
		novo->prox=lis->inicio;
		fim->prox=novo;
		lis->fim=novo;
	}else{
		lis->inicio=novo;
		lis->fim=novo;
		novo->prox=lis->inicio;

	}
}

void percorreLista(Lista* lis,int cota){
	int tempTotal=0,fim=1,cont=0;
	
	Programa* atual=lis->inicio;
	while(fim==1){
		tempTotal=tempTotal+atual->tempo_restante;
		
		if(atual==lis->fim){
			fim=0;
		}
		atual=atual->prox;
	}
	
	atual=lis->inicio;
	
	while(cont!=tempTotal){
		if(atual->tempo_restante>0){
			if(atual->tempo_restante>cota){
				atual->tempo_restante=atual->tempo_restante-cota;
				cont=cont+cota;
			}else{
				cont=cont+atual->tempo_restante;
				atual->tempo_restante=0;
				
				printf("%d us: %s finalizou\n",cont,atual->nome);
			}
			
		}
		atual=atual->prox;
		
	}
	printf("%d us: shutdown\n",tempTotal);
	
}

int main(){
	int cont, cota, numProg;
	Lista* l = criar_lista();
	Programa* temp;
	scanf("%d%d",&cota,&numProg);
	for(cont=0;cont<numProg;cont++){
		temp = ler_programa();
		inserir_fim(l,temp);
	}
	
	percorreLista(l,cota);
	
	
	return 0;
}
