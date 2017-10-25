#include <stdio.h>

int grafo[10][10], caminho[10][10], peso_v[10], h;
char rotulo[10];

int calc_caminho(int s1, int s2, int tam, int x, int peso){
	int i, j;
	
	for(i=x; i<tam; i++){
		caminho[i][s1]=0;
	}
	if(x==0){
		for(j=0; j<tam; j++){
			if(grafo[s1][j]!=0){
				caminho[x][j]=peso+grafo[s1][j]+peso_v[j];
			}else{
				caminho[x][j]=20000;
			}
		}
	}else{
		for(j=0; j<tam; j++){
			if(grafo[s1][j]!=0){
				if((grafo[s1][j]+peso+peso_v[j])<caminho[x-1][j]){
					caminho[x][j]=peso+grafo[s1][j]+peso_v[j];
				}else{
					caminho[x][j]=caminho[x-1][j];
				}
			}else{
				if(caminho[x-1][j]!=0 && caminho[x][j]!=0){
					caminho[x][j]=caminho[x-1][j];
				}
			}
		}
	}
	
	peso=20000;
	
	
	for(j=0; j<tam; j++){
		if(peso==20000 && caminho[x][j]!=0){
				peso=caminho[x][j];
				s1=j;
		}
		if(caminho[x][j]!=2000 && caminho[x][j]!=0){
			if(peso>caminho[x][j]){
				peso=caminho[x][j];
				s1=j;
			}
		}
	}
	
	if(peso==20000){
		printf("\n\nImpossivel continuar, caminho inexistente.\n\n");
		return 0;
	}
	
	if(s1==s2){
		printf("%c(%d).\nCaminho minimo de %c - %c eh %d.\n\n", rotulo[s2], peso, rotulo[h], rotulo[s2], caminho[x][s2]);
		return 0;
	}else{
		if(x==0){
			printf("%c(%d) - ", rotulo[h], peso_v[h]);
		}
		printf("%c(%d) - ", rotulo[s1], peso);
		calc_caminho(s1, s2, tam, x+1, peso);
	}
}

void caminho_minimo (int tam){
	int i, j, s1=-1, s2=-1, sts;
	char inicial, final;
	
	printf("Digite o vértice inicial e o final:");
	do{
		fflush(stdin);
		scanf("%c %c", &inicial, &final);
		for(i=0; i<tam; i++){
			if(inicial==rotulo[i]){
				s1=i;
			}
			if(final==rotulo[i]){
				s2=i;
			}
		}
		if(s1==-1 || s2==-1){
			printf("\nUm ou ambos os vertices nao existem, digite novamente...\n");
		}
	}while(s1==-1 || s2==-1);
	
	if(s1==s2){
		printf("\nO caminho minimo entre %c e %c eh %d\n", inicial, final, peso_v[i]);
	}else{
		for(i=0; i<tam; i++){
			for(j=0; j<tam; j++){
				caminho[i][j]=5;
			}
		}
		h=s1;
		sts=calc_caminho(s1, s2, tam, 0, peso_v[s1]);
	}
}

int main(){
	int tam, i, j, op, op1;
	
	do{
	
		printf("Insira o tamanho do grafo:\n");
		do{
			scanf("%d", &tam);
			if(tam<=1){
				printf("Tamanho invalido, digite novamente...\n");
			}
		}while(tam<=1);
		
		printf("Digite o nome do(s) %d vertice(s):\n", tam);
		for(i=0; i<tam; i++){
			printf("%do:", i+1);
			fflush(stdin);
			scanf("%c", &rotulo[i]);
			printf("\n");
		}
		
		printf("Digite o peso do(s) %d vertice(s):\n", tam);
		for(i=0; i<tam; i++){
			printf("%c:", rotulo[i]);
			fflush(stdin);
			do{
				scanf("%d", &peso_v[i]);
				if(peso_v[i]<=0){
					printf("Valor inválido, digite novamente...\n");
				}
			}while(peso_v[i]<=0);
			printf("\n");
		}
		
		printf("Insira a matriz de custo inicial:\n");
		for(i=0; i<tam; i++){
			for(j=0; j<tam; j++){
				printf("%cx%c:", rotulo[i], rotulo[j]);
				do{
					scanf("%d", &grafo[i][j]);
					if(grafo[i][j]<0){
						printf("Valor inválido, digite novamente...\n");
					}
				}while(grafo[i][j]<0);
				printf("\n");
			}
		}
		
		/*rotulo[0]= '0'; peso_v[0]=11; grafo[0][1]=87;
		rotulo[1]= '1'; peso_v[1]=40; grafo[1][2]=68; grafo[1][3]=16;
		rotulo[2]= '2'; peso_v[2]=86; grafo[2][5]=52; 
		rotulo[3]= '3'; peso_v[3]=25; grafo[3][0]=87; grafo[3][5]= 6; grafo[3][9]=11;
		rotulo[4]= '4'; peso_v[4]=39; grafo[4][2]=49;
		rotulo[5]= '5'; peso_v[5]= 6; grafo[5][2]= 6; grafo[5][8]= 6;
		rotulo[6]= '6'; peso_v[6]=64; grafo[6][4]= 1; grafo[6][5]=93; grafo[6][7]=3;
		rotulo[7]= '7'; peso_v[7]=58; grafo[7][8]=11;
		rotulo[8]= '8'; peso_v[8]=94; grafo[8][6]=20;
		rotulo[9]= '9'; peso_v[9]=78; grafo[9][5]=68; grafo[9][8]= 4;*/
		
		do{
			caminho_minimo(tam);
			printf("\nDigite 1 para um caminho minimo com outros vertices dessa mesma matriz.\n");
			scanf("%d", &op1);
		}while(op1==1);
		
		printf("\nDigite 0 para finalizar o programa ou qualquer tecla para inserir uma nova matriz.\n");
		scanf("%d", &op);
	}while(op!=0);
	
	return 0;
}
