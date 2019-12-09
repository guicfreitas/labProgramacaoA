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
	No* novo = malloc(sizeof(No));
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

void iniciaCartas(Lista* l,int n){
	int cont;
	for(cont=1;cont<=n;cont++){
		inserirFim(l,cont);
	}
}

int* descarte(Lista* l, int n){
	int cont=0;
	int* vetDescarte = malloc((n-1)*sizeof(int));
	No* atual= l->inicio;
	No* temp;
	
	while(l->inicio!=atual || l->fim!=atual){
		if(atual->prox!=NULL){
			vetDescarte[cont]=atual->valor;
			temp=atual;
			atual=atual->prox;
			l->inicio=atual;
			free(temp);
			inserirFim(l,atual->valor);
			temp=atual;
			atual=atual->prox;
			l->inicio=atual;
			free(temp);	
			cont++;
		}
	}
	cont=0;
	return vetDescarte;
}
void destruir_lista(Lista *lis){
	
	No* temp;
	if(lis->inicio==NULL && lis->fim==NULL){
		free(lis);
		
	}else if(lis->inicio==lis->fim){
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

int main(){
	
	int n,cont;
	Lista* l ;
	while(scanf("%d",&n)!=EOF){
		l = criarLista();
		iniciaCartas(l,n);
		int* vet = descarte(l,n);
		printf("Descartadas: ");
		if(n==1){
			
		}else if(n!=2){
			for(cont=0;cont<n-2;cont++){
				printf("%d, ",vet[cont]);
			}
			printf("%d",vet[n-2]);
		}else{
			printf("%d",vet[0]);
		}	
		printf("\n");
		printf("Restou: %d\n",l->inicio->valor);

		destruir_lista(l);
		
	}
	return 0;
}
