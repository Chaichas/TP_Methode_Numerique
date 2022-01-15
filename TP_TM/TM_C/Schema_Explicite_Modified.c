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
	fichier = fopen ("ftcs.dat", "w");
	
	//******Declaration des variables******
	int N = 100, M = 10000; //nombre des points selon l espace et le temps
	
	double dx = 1./(double) N; //pas dans l espace
	double Tobs = 1., dt = Tobs/(double) M; //temps et pas du temps
	double r=dt/(dx*dx);
	double u[N][M]; //initialisation de la matrice u(x,t)
	
	//******conditions du probleme******
	
	//Conditions aux bords
	u[0][M] = 0.; //condition au 1er bord
	u[N][M] = 0.; //condition au dernier bord
	
	//Condition initiale
	for (int j=1;  j<N; j++){ //x in ]0,1[
		u[N][j] = f_2(j*dx); //fonction f_i
	}
	
	//int k=0;
	//for (int i = 0; i<=N; i++){
		//fprintf(fichier, "%.6lf  %.6lf  %.6lf \n",k*dt, i*dx, u[i]);
	//}
	
	for (int j = 1; j<=M; j++){ //boucle sur le temps
		for (int i = 1; i<N; i++){
			u[i][j+1] = (1.-2.*r)*u[i][j] + r*(u[i+1][j]+u[i-1][j]); //schema explicite
		}
		//if(j%(M/20)==0){
			//for (int i = 0; i<=N; i++){
				//fprintf(fichier, "%.6lf  %.6lf  %.6lf \n",j*dt, i*dx, u[i][j]);
			//}
		//}
	}
	
	//affichage
	for (int i=0; i<=N; i++){
		printf("%.6lf  %.6lf \n",i*dx, u[i][1]); //u en fonction de l'espace
		fprintf(fichier, "%.6lf  %.6lf \n",i*dx, u[i][1]); //u en fonction de l'espace dans le fichier
	}
	
	return 0;
}
	
