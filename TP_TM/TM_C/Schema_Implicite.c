#include <stdlib.h>
#include <stdio.h>
#include <math.h> 


//fonction 1
double f_1(double x){
	return sin(2*M_PI*x);
}

//fonction 2
double f_2(double x){

double exper;

    if ((x > 0) && (x <= 0.5)){
        exper = 2*x; //Expression de la fonction pour x in ]0,1/2]
    }
    else if ((x > 0.5) && (x < 1)){
        exper = 2*(1-x); //Expression de la fonction pour x in ]1/2,1[
    }

	return exper;
}

//Programme principal
int main(){

	FILE *fichier;
	fichier = fopen ("implicite.dat", "w");
	
	FILE *fichier2;
	fichier2 = fopen ("implicite_3D.dat", "w");
	
	//******Declaration des variables******
	int N = 100, M = 10000; //nombre des points selon l espace et le temps
	
	double dx = 1./(double) N; //pas dans l espace
	double Tobs = 1., dt = Tobs/(double) M; //temps et pas du temps
	double r=dt/(dx*dx);
	
	//Initialisation du vecteur u
	double u[N+1][M+1]; //initialisation tab de dim N+1 * N+1
	double v[N+1][M+1];
	
		
	//******conditions du probleme******
	
	//Conditions aux bords
	for (int j=0; j<=M;j++){
		u[0][j]=0.; //1er bord
		u[N][j]=0.; //2eme bord
	}
	
	//Condition initiale
	for (int i=1;  i<N; i++){
		u[i][0] = f_2(i*dx); //fonction f_i
	}	
	
	//initialisation des u[i][j] a l'interieur, except conditions aux bords
	for (int i=1;  i<N; i++){
		for (int j=1;  j<M; j++){
			u[i][j] = 0.;
		}
	}
	
	
	//Schema implicite
	for (int j = 1; j<M; j++){
		for (int i = 1; i<N; i++){
		
			u[i][j] = (-1.*r)*u[i+1][j+1] + (1+2.*r)*u[i][j+1] + (-1.*r)*u[i-1][j+1];
		}		
	}	
	
	//affichage 2D
	for (int i=0; i<=N; i++){
		printf("%.6lf  %.6lf \n",i*dx, u[i][0]); //u en fonction de l'espace
		fprintf(fichier, "%.6lf  %.6lf \n",i*dx, u[i][0]); //u en fonction de l'espace dans le fichier
	}
	
	//affichage 3D  
	for (int i=0; i<=N; i++){
			for (int j=0; j<=M; j+=100){
				printf("%.6lf  %.6lf %.6lf \n",i*dx, j*dt, u[i][j]); //u en fonction de l'espace
				fprintf(fichier2, " %.6lf  %.6lf %.6lf \n",i*dx, j*dt, u[i][j]); //u en fonction de l'espace dans le fichier2
		}	
	}
		 
	return 0;
}
