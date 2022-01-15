//Diffusion thermique dans une plaque
function [u]=implicite(N,M)
    //Donnees de x
    Dx= 1/N; //pas en x
    
    //Donnees de t
    Tobs = 1; //temps d' observation
    Dt = 1/M; //pas en t
    
    r=Dt/(Dx)^2;
    
    
    //Conditions aux bord
    u(1) = 0; //temperature fixe pour x = 0
    u(N+1) = 0; //temperature fixe pour x = N
    
    
    //Condition initiale: Temperature de toute la barre a t = 0
        for i = 2:(N)
            [f]= func(i*Dt); //fonction definit dans un autre script
            u(i) = f;
         end

    //Matrice A
    A = diag((1+2*r)*ones(1,N)) + diag(-r * ones (1,N-1),1) + +diag(-r * ones(1,N-1),-1);
    
    //Expression de u en temps et en espace
    for j = 1:M //En temps
        for i=2: (N-1) //en espace
            
         end
    end
endfunction
funcprot(0)
