#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>

int colores(int s3,int s2,int s1,int (*mats3),int (*mats2),int (*mats1)){
int upper=5, lower=2,i=0,j=0,a1,rndm,a2=0,a3=0,b1=0,b2=0,c1=0,suma,mat[6]; //2=rojo 3=verde 4=azul

upper -=lower;

if(s3==0)
	a1=0;
else{
	for (i=0; i<s3; i++){

		rndm = (int)(rand()%upper) + lower;

		if(i==0)
			a1=rndm;
		else if(i==1)
			a2=rndm;
		else if(i==2)
			a3=rndm;
		if((a1==a2) || (a1==a3) || ((a2==a3) && (a2!=0 && a3!=0))){
			i=-1;
			continue;
		}
					
	}
}

if(s2==0)
	b1=0;
else{
	for (j=0; j<s2; j++){

		rndm = (int)(rand()%upper) + lower;
		if(rndm==a1 || rndm==a2 || rndm==a3){
			j=-1;
			continue;
		}
		else{
			if(j==0)
				b1=rndm;
			else if(j==1)
				b2=rndm;
			if(b1==b2){
				j=-1;
				continue;
			}
					
		}
	}
}

if(s1==0)
	c1=0;
else{
	for (j=0; j<s1; j++){

		rndm = (int)(rand()%upper) + lower;
		if(rndm==b1 || rndm==b2 || rndm==a1){
			j=-1;
			continue;
		}
		else
		c1=rndm;
		
				
	}
}
mats3[0]=a1;
mats3[1]=a2;
mats3[2]=a3;
mats2[0]=b1;
mats2[1]=b2;
mats1[0]=c1;
}				
			
int imprimir(int (*mat), int n){
int i;
printf("Torre %d: ",n);
for(i=0; i<n; i++){
	
	printf("%d ",mat[i]);
	}
printf("\n");
}

int ale(int n,int *s){
int i,l1,l2,l3,rndm,upper=2,lower=0;
upper-=lower;
for (i=0; i<n; i++){
	rndm = (int)(rand()%upper) + lower;
	if(i==0){
		l1=rndm;
		*s=rndm;
	}
	else if(i==1){
		l2=l1+rndm;
		*s=l2;
	}
	else if(i==2){
		l3=l2+rndm;
		*s=l3;
	}						
}
}

int mover(int select,int move,int (*mata),int (*matb),int *sa,int *sb,int na,int nb){
int i,j,x;
for(i=(select-1);(i>0 ||i==0);i--){
	if(mata[i]!=0){
		x=mata[i];
		for(j=0;j<move;j++){
			if(matb[j]==0){
				matb[j]=x;
				break;
			}
			else
				continue;
		}
	mata[i]=0;
	break;
	}
	else 
		continue;
}
*sa=0;
*sb=0;
for(i=0;i<na;i++){
	if(mata[i]!=0)
		*sa=*sa+1;
		else
		break;	
}

for(i=0;i<nb;i++){
	if(matb[i]!=0)
		*sb=*sb+1;
		else
			break;	
}
}

int comparar(int (*mats3),int (*mats2),int (*mats1),int (*matf3),int (*matf2),int (*matf1)){
int i,check3=0,check2=0,check1=0,suma;

for(i=0;i<3;i++){
	if(mats3[i]==matf3[i])
		check3=check3+1;
		else{
			check3=0;
			break;
		}	
}
for(i=0;i<2;i++){
	if(mats2[i]==matf2[i])
		check2=check2+1;
		else{
			check3=0;
			break;
		}	
}
for(i=0;i<1;i++){
	if(mats3[i]==matf3[i])
		check1=check1+1;
		else{
			check3=0;
			break;
		}	
}
suma=check3+check2+check1;

if(suma==6)
	return 1;
else
	return 0;

}

void main (){
struct tms t;
int i,s1,s2,s3,f1,f2,f3,suma,suma2;
int mats3[3],mats2[2],mats1[1],matf3[3],matf2[2],matf1[1];
int move,select,pasos=0;

srand(times(&t));

while(suma!=3){
	ale(3,&s3);
	ale(2,&s2);
	ale(1,&s1);
	suma=s1+s2+s3;
}
while(suma2!=3){
	ale(3,&f3);
	ale(2,&f2);
	ale(1,&f1);
	suma2=f1+f2+f3;
}

colores(s3,s2,s1,mats3,mats2,mats1);
colores(f3,f2,f1,matf3,matf2,matf1);

printf("Torres de inicio \n");
imprimir(mats3, 3);
imprimir(mats2, 2);
imprimir(mats1, 1);

printf("Torre objetivo \n");
imprimir(matf3, 3);
imprimir(matf2, 2);
imprimir(matf1, 1);

while(comparar(mats3,mats2,mats1,matf3,matf2,matf1)==0){

	printf("selecciona la torre a mover ");
	scanf("%d", &select);	
	while((select==3 && s3==0) || (select==2 && s2==0) || (select==1 && s1==0)){
		printf("sin elementos \n");
		printf("selecciona la torre a mover ");
		scanf("%d", &select);
	}
	printf("mover elemento a ");
	scanf("%d", &move);
	while((move==3 && s3==3) || (move==2 && s2==2) || (move==1 && s1==1)){
		printf("torre llena \n");
		printf("mover elemento a ");
		scanf("%d", &move);		
	}
		if(select==1 && move==2)
		mover(select,move,mats1,mats2,&s1,&s2,1,2);
		else if(select==2 && move==1)
		mover(select,move,mats2,mats1,&s2,&s1,2,1);
		else if(select==3 && move==1)
		mover(select,move,mats3,mats1,&s3,&s1,3,1);
		else if(select==1 && move==3)
		mover(select,move,mats1,mats3,&s1,&s3,1,3);
		else if(select==2 && move==3)
		mover(select,move,mats2,mats3,&s2,&s3,2,3);
		else if(select==3 && move==2)
		mover(select,move,mats3,mats2,&s3,&s2,3,2);
		else
		printf("movimiento invalido \n");

	system("clear");

printf("Torres a mover\n");
imprimir(mats3, 3);
imprimir(mats2, 2);
imprimir(mats1, 1);
printf("Torres objetivo \n");
imprimir(matf3, 3);
imprimir(matf2, 2);
imprimir(matf1, 1);
	
pasos=pasos+1;
}
printf("has ganado en %d pasos\n",pasos);
}
