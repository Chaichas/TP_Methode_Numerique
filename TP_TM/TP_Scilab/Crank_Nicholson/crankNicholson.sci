//Diffusion thermique dans une plaque
function [u]=Crank_Nicholson(N,M)

    A1=zeros(N,N); //initialisation du matrice A1
    A2=zeros(N,N); //initialisation du matrice A2
    u=zeros(N,1); //initialisation du vecteur u
    
    //Donnees de x
    Dx= 1/N; //pas en x
    
    //Donnees de t
    Tobs = 1; //temps d' observation
    Dt = 1/M; //pas en t
    
    r=Dt/(Dx)^2;
    
    
    //Conditions aux bord
    u(1) = 0; //temperature fixe pour x = 0
    u(N) = 0; //temperature fixe pour x = N
    
    
    //Condition initiale: Temperature de toute la barre a t = 0
        for i = 2:(N-1)
            [f]= func(i*Dt); //fonction definit dans un autre script
            u(i) = f;
         end

    //Matrice A
    A1 = diag((1+2*r)*ones(1,N)) + diag(-r * ones (1,N-1),1) + +diag(-r * ones(1,N-1),-1);
    A2 = diag((-1-2*r)*ones(1,N)) + diag(r * ones (1,N-1),1) + +diag(r * ones(1,N-1),-1);
    
    //Expression de u en temps et en espace
    for j = 1:M //En temps
        u=A1\(A2*u); //resolution  du systeme (2.84)
    end
endfunction
funcprot(0)
