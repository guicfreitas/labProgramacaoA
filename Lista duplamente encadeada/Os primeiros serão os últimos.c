#include <stdio.h>
#include <stdlib.h>


typedef struct no No;
struct no{
	int valor;
	No* anterior;
	No* prox;
};

typedef struct lista Lista;
struct lista{
	No* inicio;
	No* fim;
};



Lista* criarLista(){
	Lista* l = malloc(sizeof(Lista));
	l->inicio=NULL;
	l->fim=NULL;
}

void inserirFim(Lista* l,int valor){
	No* novo =(No*) malloc(sizeof(No));
	novo->valor=valor;
	No* notemp=l->fim;
	if(l->fim!=NULL){
		notemp->prox=novo;
		novo->anterior=notemp;
		novo->prox=NULL;
		l->fim=novo;
	}else{
		l->inicio=novo;
		l->fim=novo;
		novo->prox=NULL;
		novo->anterior=NULL;
	}
}

No *buscar_elem(Lista *l, int elem){
	No* atual=l->inicio;
	if(l->inicio->valor==elem){
		return l->inicio;
	}
	if(l->fim->valor==elem){
		return l->fim;
	}

	while(atual!=l->fim){
		if(atual->valor==elem){
			return atual;
		}

		atual=atual->prox;

	}
	return NULL;
}

void destruir_lista(Lista *lis){

	No* temp;
	if(lis->inicio==NULL && lis->fim==NULL){

		free(lis);
	}else{

		if(lis->inicio==lis->fim){
		No* atual=lis->inicio;
		free(atual);

		}else{
			No* atual=lis->inicio;
			while(atual!=lis->fim){
				temp=atual;
				atual=temp->prox;
				free(temp);

			}
		}
		free(lis);
	}

}

void inverteSubLista(Lista* l ,int elem){
	int valor;
	No* result = buscar_elem(l,elem);
	No* prox;
	if(result->prox==NULL){
		 prox =result;
	}else{
		prox = result->prox;
	}
	
	
	No* fim = l->fim;
	No* temp;
	No* ant;
	No* atual;

	while(prox->anterior!=NULL){
		atual=prox->anterior;
		temp=atual; 
		valor = atual->valor;
		inserirFim(l,valor);
		if(atual->anterior!=NULL){
			prox->anterior=atual->anterior;
		}else{
			prox->anterior=NULL;
		}

		free(temp);
	}

	l->inicio = prox;

}

void imprimirLista(Lista* l){
	No* p;
	 for (p=l->inicio; p!=NULL; p=p->prox){
	 	printf("%d ",p->valor);
	 }
}
void inicia(Lista* l,int n){
	int cont;
	for(cont=1;cont<=n;cont++){
		inserirFim(l,cont);
	}
}

int main(){
	int valor,altera;
	Lista* l = criarLista();
	scanf("%d",&valor);
	inicia(l,valor);
	//imprimirLista(l);
	while(scanf("%d",&altera)!=EOF){
		inverteSubLista(l ,altera);
		//imprimirLista(l);
	}
	imprimirLista(l);
	return 0;
}

