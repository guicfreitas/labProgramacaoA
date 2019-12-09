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

int removeOcorrencia(Lista* l, int ocor){
	No* ant;
	No* prox;
	No* temp;
	No* atual = l->inicio;
	int cont=0;
	while(atual!=l->fim){
		if(atual->valor==ocor){
			if(atual->anterior==NULL){
				prox=atual->prox;
				temp=atual;
				l->inicio=prox;
				prox->anterior=NULL;
				//free(temp);
				
				
			}else if(atual->prox==NULL){
				ant=atual->anterior;
				temp=atual;
				l->fim=ant;
				ant->prox=NULL;
				
				//free(temp);
			}else{
				ant=atual->anterior;
				prox=atual->prox;
				temp=atual;
				ant->prox=prox;
				prox->anterior=ant;
				
				
			}
			//free(temp);
			
		}
		atual=atual->prox;
		
	}
	if(atual->valor==ocor){
		if(atual->prox==NULL){
				ant=atual->anterior;
				temp=atual;
				l->fim=ant;
				if(ant!=NULL){
					ant->prox=NULL;
				}	
		}		
		
	}
	No* p;
	 for(p=l->inicio; p!=NULL; p=p->prox){
	 	if((p!=NULL && p->prox!=NULL && p->prox->prox!=NULL) && (p->valor==p->prox->valor && p->valor==p->prox->prox->valor)){
			return 1;
		}
	 }
	
	return 0;
}

int main(){
	int valor=1,ocorr,tripla=0;
	Lista* l;
	while(valor!=-1){
		l=criarLista();
		while(valor!=0 && valor!=-1){
			
			scanf("%d",&valor);
			if(valor!=0 && valor!=-1){
				inserirFim(l,valor);
			}
			
		}
		if(valor!=-1){
			if(valor==-1){
				break;
			}
			scanf("%d",&ocorr);
			tripla=removeOcorrencia(l,ocorr);
			if(tripla==1){
				printf("tripla\n");
			}else{
				printf("nada\n");
			}
		}
		if(valor!=-1){
			valor=1;
		}
		
		destruir_lista(l);
	}
	
	return 0;
}
