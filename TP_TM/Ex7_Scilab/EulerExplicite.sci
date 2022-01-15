function [u_explicite]=euler_explicite(t,m)
 
    u_explicite(1)= 1; //solution a t =0
    dt= 1/m; //pas du temps
    for i = 1:m
        u_explicite(i+1) = (1-dt) * u_explicite (i);
    end
    
endfunction
funcprot(0)
