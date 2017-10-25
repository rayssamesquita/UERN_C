#include <stdio.h>

int grau[10], grafo[10][10], cont_cor[10], cores[10], coloracao[10][10];
char rotulo[10];


int classificacao(int tam){
	int g, i, j, sts=0;
	
	g=grafo[0][1];
	
	for(i=0; i<tam; i++){
		for(j=0; j<tam; j++){
			if(i!=j){
				if(grafo[i][j]!=g){
					sts=1;
				}
			}
		}
	}
	
	if(sts==0){
		if(g==0){
			return 0;
		}else{
			return 1;
		}
	}else{
		return 2;
	}
}

void cont_grau(tam){
	int i, j;
	
	for(i=0; i<tam; i++){
		grau[i]=0;
		for(j=0; j<tam; j++){
			if(grafo[i][j]==1){
				grau[i]++;
			}
		}
	}
}

void color(int tam, int cor){
	int i, j, k, l, sts=0, sts1=0, sts2=0, aux, x=0, pos;

	cores[cor]=cor;
	cont_cor[cor]=0;
	do{
		aux=-1;
		if(cor==0 && x==0){	
			for(i=0; i<tam; i++){
				if(aux<grau[i]){
					aux=grau[i];
					pos=i;
				}
			}
		
			coloracao[cor][x]=pos;
			cont_cor[cor]++;
			sts2=1;
			x++;
		}else{
			sts2=0;
			for(i=0; i<tam; i++){
				sts1=0;
				if(aux<grau[i]){
					for(k=0; k<=cor; k++){
						for(l=0; l<cont_cor[k]; l++){
							if(cont_cor[cor]!=0){
								if(i==coloracao[k][l]){
									sts1=1;
								}
							}else{
								if(i==coloracao[k][l]){
									sts1=1;
								}
							}
						}
					}
					
					for(k=0; k<cont_cor[cor]; k++){
						if(grafo[i][coloracao[cor][k]] == 1){
							sts1=1;
						}
					}
					
					if(sts1==0){
						aux=grau[i];
						pos=i;
						sts2=1;
					}
				}
			}
			if(sts2==1){
				cont_cor[cor]++;
				coloracao[cor][x]=pos;
				x++;
			}
		}
	}while(sts2==1);
	
	for(k=0; k<=cor; k++){
		sts+=cont_cor[k];
	}
	
	
	if(sts<tam){
		color(tam, cor+1);
	}else{
		printf("\n\nResultado:\n");
		for(k=0; k<=cor; k++){
			printf("Cor %d:", cores[k]);
			for(l=0; l<cont_cor[k]; l++){
				printf("%c ", rotulo[coloracao[k][l]]);
			}
			printf("\n");
		}
	
		printf("\n\nA quantidade de cores necessaria eh %d.\n", cor+1);
	}
	
	
}

int main(){
	int i, j, op, tam, classif;
	
	do{
		
		for(i=0; i<10; i++){
			for(j=0; j<10; j++){
				coloracao[i][j]=-1;
			}
		}
	
		printf("Insira a quantidade de vertices:\n");
		do{
			scanf("%d", &tam);
			if(tam<=0){
				printf("Quantidade invalida, digite novamente...\n");
			}
		}while(tam<=0);
		
		printf("Digite o nome do(s) %d vertice(s):\n", tam);
		for(i=0; i<tam; i++){
			printf("%do:", i+1);
			fflush(stdin);
			scanf("%c", &rotulo[i]);
			printf("\n");
		}
		
		
		printf("Insira a matriz de custo inicial:\n");
		for(i=0; i<tam; i++){
			for(j=i; j<tam; j++){
				printf("%cx%c:", rotulo[i], rotulo[j]);
				do{
					scanf("%d", &grafo[i][j]);
					grafo[j][i]=grafo[i][j];
					if(grafo[i][j]!=0 && grafo[i][j]!=1){
						printf("Valor inválido, digite novamente...\n");
					}
				}while(grafo[i][j]!=0 && grafo[i][j]!=1);
				printf("\n");
			}
		}
		
		/*grafo[0][0]=0;	grafo[0][1]=1;	grafo[0][2]=1;	grafo[0][3]=0;
		grafo[1][0]=1;	grafo[1][1]=0;	grafo[1][2]=0;	grafo[1][3]=1;
		grafo[2][0]=1;	grafo[2][1]=0;	grafo[2][2]=0;	grafo[2][3]=1;
		grafo[3][0]=0;	grafo[3][1]=1;	grafo[3][2]=1;	grafo[3][3]=0;*/
		
			classif=classificacao(tam);
	
	switch (classif){
		case 0:
			printf("\nGrafo vazio, logo apenas uma cor eh necessaria.\n");
			break;
		case 1:
			printf("\nGrafo completo, logo %d cores sao necessarias.\n", tam);
			break;
		case 2:
			cont_grau(tam);
			color(tam, 0);
	}
		
		printf("\nDigite 0 para finalizar o programa ou qualquer tecla para inserir uma nova matriz.\n");
		scanf("%d", &op);
	}while(op!=0);
	
	return 0;
}
