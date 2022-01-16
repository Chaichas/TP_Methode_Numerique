#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include "matrice.c"


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
	fichier = fopen ("ftcs.dat", "w");
	
	//******Declaration des variables******
	int N = 100, M = 10000; //nombre des points selon l espace et le temps
	
	double dx = 1./(double) N; //pas dans l espace
	double Tobs = 1., dt = Tobs/(double) M; //temps et pas du temps
	double r=dt/(dx*dx);
	
	//Initialisation du vecteur u
	double u[N+1]; //initialisation tab de dim N
	
	//Initialisation de la matrice A
	double A[N+1][N+1]; //initialisation de la matrice A
		
	
	//******conditions du probleme******
	
	//Conditions aux bords
	u[0] = 0.; //condition au 1er bord
	u[N] = 0.; //condition au dernier bord
	
	A[0][0]=1; //1er element du matrice A
	A[N][N]=1; //Dernier element du matrice A
	
	//Condition initiale
	for (int i=1;  i<N; i++){
		u[i] = f_1(i*dx); //fonction f_i
	}
	
	
	for (int j = 0; j<=M; j++){
		for (int i = 0; i<=N; i++){
		
			u[i] = A[i][i] * u[i];
		}
		//if(j%(M/20)==0){
			//for (int i = 0; i<=N; i++){
				//fprintf(fichier, "%.6lf  %.6lf  %.6lf \n",j*dt, i*dx, u[i]);
			//}
		//}
	}
	
	
	//affichage
	for (int i=0; i<=N; i++){
		u[N] = 0.; //condition au dernier bord
		printf("%.6lf  %.6lf \n",i*dx, u[i]); //u en fonction de l'espace
		fprintf(fichier, "%.6lf  %.6lf \n",i*dx, u[i]); //u en fonction de l'espace dans le fichier
	}
		 
	return 0;
}
