function [u_explicite]=euler_explicite(t,m)
 
    //Condition initial
    u_explicite(1)= 1; //solution a t =0
    dt= 1/m; //pas du temps, m=nombre des points
    
    for i = 1:m
        u_explicite(i+1) = u_explicite(i)*(1- dt*u_explicite (i)); //Euler explicite
    end
    
endfunction
funcprot(0)
