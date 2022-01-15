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

    if ((x > 0) & (x <= 1/2)){
        exper = 2*x; //Expression de la fonction pour x in ]0,1/2]
    }
    else if ((x > 1/2) & (x < 1)){
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
	double u[N]; //initialisation tab de dim N
	
	//******conditions du probleme******
	
	//Conditions aux bords
	u[0] = 0.; //condition au 1er bord
	u[N-1] = 0.; //condition au dernier bord
	
	//Condition initiale
	for (int i=1;  i<N-1; i++){
		u[i] = f_2(i*dx); //fonction f_i
	}
	
	//int k=0;
	//for (int i = 0; i<=N; i++){
		//fprintf(fichier, "%.6lf  %.6lf  %.6lf \n",k*dt, i*dx, u[i]);
	//}
	
	for (int j = 1; j<M; j++){
		for (int i = 1; i<N-1; i++){
			u[i] = (1.-2.*r)*u[i] + r*(u[i+1]+u[i-1]); //schema explicite
		}
		//if(j%(M/20)==0){
			//for (int i = 0; i<=N; i++){
				//fprintf(fichier, "%.6lf  %.6lf  %.6lf \n",j*dt, i*dx, u[i]);
			//}
		//}
	}
	
	//affichage
	for (int i=0; i<N; i++){
		printf("%.6lf  %.6lf \n",i*dx, u[i]); //u en fonction de l'espace
		fprintf(fichier, "%.6lf  %.6lf \n",i*dx, u[i]); //u en fonction de l'espace dans le fichier
	}
	
	return 0;
}
	
