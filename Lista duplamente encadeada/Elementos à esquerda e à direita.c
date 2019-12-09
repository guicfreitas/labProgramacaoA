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
	if(l->inicio!=NULL){
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

No* no_prox(Lista* l,No* atual,int pos){
	int cont=0;
	No* percorre=atual;
	
		while(pos!=cont){
			if(percorre->prox==NULL){
				return NULL;
			}else{
				percorre=percorre->prox;
			}
			cont++;
		}
	
	return percorre;
}


No* no_ant(Lista* l,No* atual,int pos){
	int cont=0;
	No* percorre=atual;
	
		while(pos!=cont){
			if(percorre->anterior==NULL){
				return NULL;
			}else{
				percorre=percorre->anterior;
			}
			cont++;
		}
	
	return percorre;
}

int main(){
	int valor=0,consulta,contE=0,contD=0;
	Lista* l = criarLista();	
	while(valor!=-1){
		scanf("%d",&valor);
		if(valor!=-1){
			inserirFim(l,valor);
		}
	}
	
	
	
	int fimE,fimD;
	
	while(scanf("%d",&consulta)!=EOF){
		No* noE=l->fim;
		No* noD=l->inicio;
		No* base;
		contD=1;
		contE=1;
		fimE=1;
		fimD=1;
		base=buscar_elem(l,consulta);
		while(fimE!=0 || fimD!=0){
			noE=no_ant(l,base,contE);
			noD=no_prox(l,base,contD);

			if(noE!=NULL){
				printf("%d ",noE->valor);
				contE++;
			}else{
				fimE=0;
			}
			
			if(noD!=NULL){
				printf("%d ",noD->valor);
				contD++;
			}else{
				fimD=0;
			}
		}
		printf("\n");
	}
	
	
	
	return 0;
}




