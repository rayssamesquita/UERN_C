#include <stdio.h>

#define LTAM 24
#define CTAM 12

	int matriz[LTAM][CTAM], caminho[LTAM][CTAM];

int algoritmoDos8_busca(int i, int j){
	int x1, x2, k1, k2, m, n, min_l, min_c, sts=0;
	if(i==0){
		if(j==0){
			x1=i;
			x2=i+1;
			k1=j;
			k2=j+1;
		}else if(j<CTAM-1){
			x1=i;
			x2=i+1;
			k1=j-1;
			k2=j+1;
		}else if(j==CTAM-1){
			x1=i;
			x2=i+1;
			k1=j-1;
			k2=j;
		}
	}else if(i<LTAM-1){
		if(j==0){
			x1=i-1;
			x2=i+1;
			k1=j;
			k2=j+1;
		}else if(j==CTAM-1){
			x1=i-1;
			x2=i+1;
			k1=j-1;
			k2=j;
		}else{
			x1=i-1;
			x2=i+1;
			k1=j-1;
			k2=j+2;
		}
	}else if (i==LTAM-1){
		if(j==0){
			x1=i-1;
			x2=i;
			k1=j;
			k2=j+1;
		}else if(j==CTAM-1){
			x1=i-1;
			x2=i;
			k1=j-1;
			k2=4;
		}else{
			x1=i-1;
			x2=i;
			k1=j-1;
			k2=j+1;
		}
	}
	
	min_l=x1;
	min_c=k1;
	for(m=x1; m<=x2; m++){
		for(n=k1; n<=k2; n++){
			if(sts==0 && caminho[m][n]!=0){
				min_l=m;
				min_c=n;
				sts=1;
			}else{
				if(caminho[m][n]<caminho[min_l][min_c] && caminho[m][n]!=0){
					min_l=m;
					min_c=n;
				}
			}
		}
	}
	
	if(matriz[min_l][min_c]!=1){
		matriz[min_l][min_c]=1;
		algoritmoDos8_busca(min_l, min_c);
	}
	

}


void menor_caminho(){
	int i, j, pos_x, pos_y;
	
	for(i=0; i<LTAM; i++){
		for(j=0; j<CTAM; j++){
			if(matriz[i][j]==2){
				pos_x=i;
				pos_y=j;
			}
		}
	}
		algoritmoDos8_busca(pos_x, pos_y);
	
}

void algoritmoDos8_set(int i, int j){
	int x1, x2, k1, k2, m, n;
	if(i==0){
		if(j==0){
			x1=i;
			x2=i+1;
			k1=j;
			k2=j+1;
		}else if(j<CTAM-1){
			x1=i;
			x2=i+1;
			k1=j-1;
			k2=j+1;
		}else if(j==CTAM-1){
			x1=i;
			x2=i+1;
			k1=j-1;
			k2=j;
		}
	}else if(i<LTAM-1){
		if(j==0){
			x1=i-1;
			x2=i+1;
			k1=j;
			k2=j+1;
		}else if(j==CTAM-1){
			x1=i-1;
			x2=i+1;
			k1=j-1;
			k2=j;
		}else{
			x1=i-1;
			x2=i+1;
			k1=j-1;
			k2=j+2;
		}
	}else if (i==LTAM-1){
		if(j==0){
			x1=i-1;
			x2=i;
			k1=j;
			k2=j+1;
		}else{
			x1=i-1;
			x2=i;
			k1=j-1;
			k2=j+1;
		}
	}
	
	for(m=x1; m<=x2; m++){
		for(n=k1; n<=k2; n++){
			if(matriz[m][n]==0){
				if(m==i || n==j){
					if(caminho[m][n]==0){
						caminho[m][n]=caminho[i][j]+1;
					}
				}
			}
		}
	}
	
}

int main(){
	int i, j;
	
	for(i=0; i<LTAM; i++){
		for(j=0; j<CTAM; j++){
			matriz[i][j]=0;
			caminho[i][j]=0;
		}
	}
	
	//Ponto Inicial
	matriz[0][0]=1;
	
	//Primeiro Obstáculo
	matriz[1][3]=5;
	matriz[1][4]=5;
	matriz[2][3]=5;
	matriz[2][4]=5;
	
	//Segundo Obstáculo
	matriz[3][0]=5;
	matriz[3][1]=5;
	matriz[4][0]=5;
	matriz[4][1]=5;
	
	//Terceiro Obstáculo
	matriz[10][2]=5;
	matriz[10][3]=5;
	matriz[11][2]=5;
	matriz[11][3]=5;
	
	//Quarto Obstáculo
	matriz[14][6]=5;
	matriz[14][7]=5;
	matriz[15][6]=5;
	matriz[15][7]=5;
	
	//Quinto Obstáculo
	matriz[21][10]=5;
	matriz[21][11]=5;
	matriz[22][10]=5;
	matriz[22][11]=5;
	
	//Sexto Obstáculo
	matriz[22][7]=5;
	matriz[22][8]=5;
	matriz[23][7]=5;
	matriz[23][8]=5;
	
	//Ponto Final
	matriz[23][11]=2;

	
	for(i=0; i<LTAM; i++){
		for(j=0; j<CTAM; j++){
			if(matriz[i][j]==0 || matriz[i][j]==1){
				algoritmoDos8_set(i, j);	
			}
		}
	}
	
	menor_caminho();
	
	for(i=0; i<LTAM; i++){
		for(j=0; j<CTAM; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n\n");
	}
	
	printf("\n\n\n\n");
	
	for(i=0; i<LTAM; i++){
		for(j=0; j<CTAM; j++){
			printf("%d ", caminho[i][j]);
		}
		printf("\n\n");
	}
	
	getch();
	return 0;
}
