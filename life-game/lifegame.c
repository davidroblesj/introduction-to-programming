#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

static const int xsize=140,ysize=140;

int vecinos(int mat1[xsize][ysize],int i,int j){

int sumavn;

    sumavn=
    mat1[((i-1)+xsize)%xsize][j]+
    mat1[((i-1)+xsize)%xsize][((j-1)+ysize)%ysize]+
    mat1[i][((j-1)+ysize)%ysize]+
    mat1[((i+1)+xsize)%xsize][((j-1)+ysize)%ysize]+
    mat1[((i+1)+xsize)%xsize][j]+
    mat1[((i+1)+xsize)%xsize][((j+1)+ysize)%ysize]+
    mat1[i][((j+1)+ysize)%ysize]+
    mat1[((i-1)+xsize)%xsize][((j+1)+ysize)%ysize];

return sumavn;
}

int reglas(int (*mat1)[ysize],int (*mat2)[ysize],int vec,int i,int j){

if ((mat1[i][j]==0 && vec==3)||(mat1[i][j]==1 && (vec==2 || vec==3)))

	mat2[i][j]=1;
else
	mat2[i][j]=0;

//return (mat2[i][j]);

}

int imprimir(int mat[xsize][ysize]){
int i,j;
for(j=0; j<ysize; j++){
	for(i=0; i<xsize; i++){
		if(mat[i][j]==0)
				printf(".");
			else
				printf("O");
    	}
	printf("\n");
}
}


int main (){
struct tms t;
int upper=2, lower=0,rndm,i,j;
int mat1[xsize][ysize],mat2[xsize][ysize];

srand(times(&t));  
upper -=lower;

for (j=0;j<ysize;j++){
	for(i=0;i<xsize;i++){
		rndm = (int)(rand()%upper) + lower;
		mat1[i][j]=rndm;
	}
}

imprimir(mat1);
		
for(;;){ 

	for (j=0;j<ysize;j++){
		for(i=0;i<xsize;i++){
			int vec=vecinos(mat1,i,j);
			reglas(mat1,mat2,vec,i,j);
			}
	}

	imprimir(mat2);

	for (j=0;j<ysize;j++){
		for(i=0;i<xsize;i++){
			mat1[i][j]=mat2[i][j];
			}
	
	}
	
		usleep(80000);
		system("clear");
/*int x;
	printf("introduce un numero: ");
	
	scanf("%d" , &x);
if(x==1)
continue;*/	
}
return 1;
}


