#include <stdio.h>

int main(){
	int cont,numPerfeito,soma=0;
	scanf("%d",&numPerfeito);
	for(cont=1;cont<numPerfeito;cont++){
		if(numPerfeito%cont==0){
			printf("%d\n",cont);
			soma=soma+cont;
		}
	}
	
	if(soma==numPerfeito){
		printf("PERFEITO");
	}else{
		printf("NAO PERFEITO");
	}
	return 0;
}
