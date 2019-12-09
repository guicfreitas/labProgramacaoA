#include <stdio.h>
#include <stdlib.h>

/* Estrutura de dados para os nos da lista. Nao altere.
 */
typedef struct no No;
struct no {
	int dado;
	No *prox;
};


/* Estrutura de dados para uma lista encaeada. Nao altere.
 */
typedef struct lista Lista;
struct lista {
	No *inicio;
	No *fim;
};


/* Prototipos das funcoes que voce deve implementar. Voce pode
 * modificar os NOMES dos parametros. Nao altere os TIPOS
 * dos parametros, nem dos retornos das funcoes!
 */


/* Cria uma lista circular encadeada vazia. Tanto "inicio" quanto
 * "fim" apontam para NULL.
 */
Lista *criar_lista(void);

/* Libera memoria de uma lista. Deve remover todos os nos e
 * tambem a memoria para a estrutura da lista.
 */
void destruir_lista(Lista *lis);

/* Procura por um elemento na lista. Se o elemento for
 * encontrado, retorna um ponteiro parao no' que o contem. Caso
 * contrario, retorna NULL.
 */
No *buscar_elem(Lista *lis, int elem);

/* Procura por um no' em uma certa posicao da lista. Assuma que o
 * primeiro no' esta' na posicao zero e que cada no' tem uma unica
 * posicao. Se a posicao passada para a funcao for invalida, retorne
 * NULL. Caso contrario, retorne um ponteiro para o no'
 */
 No *buscar_pos(Lista *lis, int pos);

/* Insere um elemento no fim da lista. Lembre-se de atualizar os
 * ponteiros da lisa para que ela continue sendo circular. Use os
 * ponteiro "fim", contido na estrutura da lista, para nao precisar
 * percorrer toda a lista em busca do fim.
 */
void inserir_fim(Lista *lis, int elem);

/* Cria um novo no' e o insere apos um no de referencia. Esse
 * no de referencia deve ser obtido com ajuda da funcao
 * buscar_elem().
 *
 * Se o no de referencia for o ultimo da lista, o novo no' devera
 * ser inserido no fim e o ponteiro "fim" devera' ser atualizado
 */
void inserir_apos(Lista *lis, No *ref, int elem);

int main(){
	int inserir=0,a,b,q;
	Lista* l = criar_lista();
	No* ref;
	No* pos;
	scanf("%d",&inserir);
	while(inserir!=-1){
		inserir_fim(l,inserir);
		scanf("%d",&inserir);
	}
	
	while(a!=-1 && b!=-1){
		scanf("%d%d",&a,&b);
		if(a!=-1 && b!=-1){
			ref=buscar_elem(l,a);
			inserir_apos(l,ref,b);
		}
	}
	
	while(scanf("%d",&q)!=EOF){
		pos=buscar_pos(l,q);
		if(pos==NULL){
			printf("invalido\n");
		}else{
			printf("%d\n",pos->dado);
		}
	}
	
	
	return 0;
}





Lista *criar_lista(void){
	Lista* l = malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim= NULL;
	return l;
}

void destruir_lista(Lista *lis){
	
	No* temp;
	if(lis->inicio==NULL && lis->fim==NULL){
		free(lis);
		
	}else if(lis->inicio==lis->fim){
		No* atual=lis->inicio;
		free(atual);
		free(lis);
	}else{
		No* atual=lis->inicio;
		while(atual->prox!=lis->inicio){
			temp=atual;
			atual=temp->prox;
			free(temp);

		}
	}	
	free(lis);
}


No *buscar_elem(Lista *lis, int elem){
	No* atual=lis->inicio;
	
	
	while(atual!=lis->fim){
		if(atual->dado==elem){
			return atual;
		}
		
		atual=atual->prox;
		
	}
	return NULL;
}

No *buscar_pos(Lista *lis, int pos){
	No* atual=lis->inicio;
	
	int cont=0,fim=1;
	if(pos<0){
		return NULL;
	}
	while(pos!=cont && fim==1){
		if(atual!=lis->fim){
			atual=atual->prox;
		}else{
			atual=atual->prox;
			fim=0;
			if(pos!=cont){
				return NULL;
			}
		}	
		cont++;
	}
	return atual;
}

void inserir_fim(Lista *lis, int elem){
	if(lis->fim!=NULL){
		No* fim=lis->fim;
		No* novo = malloc(sizeof(No));
		novo->dado=elem;
		novo->prox=lis->inicio;
	
		fim->prox=novo;
		lis->fim=novo;
	}else{
		No* novo = malloc(sizeof(No));
		novo->dado=elem;
		lis->inicio=novo;
		lis->fim=novo;
		novo->prox=lis->inicio;

	}
}

void inserir_apos(Lista *lis, No *ref, int elem){
	No* busca = ref;
	No* novo=malloc(sizeof(No));
	if(busca!=NULL){
		if(busca==lis->fim){
			novo->prox=lis->inicio;
			novo->dado=elem;
			lis->fim=novo;
		}else{
			 novo->prox=busca->prox;
			 novo->dado=elem;
			busca->prox=novo;
		}
	}else{
		inserir_fim(lis,elem);
	}
}


