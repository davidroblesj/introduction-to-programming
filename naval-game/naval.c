#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>
#include <math.h>

static const int xsize=30,ysize=30;


typedef struct{

int x;
int y;

}board;

typedef struct{

int x;
int y;

}barco;

int llenar(int (*mat1)[ysize]){

	int i,j;
	for (j=0;j<ysize;j++){
		for(i=0;i<xsize;i++){
			mat1[i][j]=0;
		}
	}

}


int imprimir(int mat[xsize][ysize]){
	int i,j;
	for(j=0; j<ysize; j++){
		for(i=0; i<xsize; i++){
			if(mat[i][j]==0)
					printf(". ");
				else if(mat[i][j]==1)
					printf("O ");
				else if(mat[i][j]==2)
					printf("X ");
				else if(mat[i][j]==3)
					printf("@ ");		
	    	}
		printf("\n");
	}
}


int randomizar(int upper,int lower){

	int rndm;
		
	rndm = (int)(rand()%upper) + lower;

	return rndm;

}

int bote(int (*mat1)[ysize],int l,int *x,int *y){
	int lx,ly,dir,i;

	*x=randomizar(xsize,0);
	*y=randomizar(xsize,0);

	mat1[*x][*y]=1;
	
	
	dir=randomizar(2,0);
	
	if (dir==0){
		ly=*y+l;
		for(i=*y;i<ly;i++){
			mat1[*x][i]=1;
		}
	}
	
	else if (dir==1){
		lx=*x+l;
		for(i=*x;i<lx;i++){
			mat1[i][*y]=1;
		}
	}


}

int distancia(int bx, int by,int x,int y){
	int dis;
	dis=sqrt((bx-x)*(bx-x)+(by-y)*(by-y));
	
	return dis;
}


int main (){
	struct tms t;
	int rndm,i,j,mat1[xsize][ysize],hit=0,b=4,distant[b],l;
	float dis=0,dis1,dis2,dis3,dis4;
	board c1;
	barco b1,b2,b3,b4;

	srand(times(&t));  
	
	llenar(mat1);

	bote(mat1,2,&b1.x,&b1.y);
	bote(mat1,3,&b2.x,&b2.y);
	bote(mat1,4,&b3.x,&b3.y);
	bote(mat1,5,&b4.x,&b4.y);
	
	

	for(;;){
		imprimir(mat1);
		
		
		printf("Coordenada x: ");
		
		scanf("%d" , &c1.x);	

		printf("Coordenada y: ");
		
		scanf("%d" , &c1.y);

		if(mat1[c1.x][c1.y]==1){
			mat1[c1.x][c1.y]=2;
			hit++;
		}
		
		else{
			mat1[c1.x][c1.y]=3;
			for(j=0; j<ysize; j++){
				for(i=0; i<xsize; i++){
					if(mat1[i][j]==1){
						for(l=0; l<b; l++)
						distant[l]=distancia(i,j,c1.x,c1.y);
						printf("dis %d \n",distant[l]);
					}	
				}
			}	
			/*dis1=distancia(c1.x,c1.y,b1.x,b1.y);
			dis2=distancia(c1.x,c1.y,b2.x,b2.y);
			dis3=distancia(c1.x,c1.y,b3.x,b3.y);
			dis4=distancia(c1.x,c1.y,b4.x,b4.y);
	
			distant[0]=dis1;
			distant[1]=dis2;
			distant[2]=dis3;
			distant[3]=dis4;*/
			
			for(i=0; i<b; i++){
			if(distant[i]>dis)
				dis=distant[i];			
			}
			int dismenor = dis;
			for(i=0; i<b; i++){
			if(dismenor>distant[i])
				dismenor=distant[i];
							
			}
			
		printf("Tu tiro esta a %d del barco mas cercano	\n",dismenor);		
		
		}	
		if(hit==14){
		printf("Ganaste\n");
		break;	
		}	
	}	

	return 1;
	
	
}
