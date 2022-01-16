function [u_numerique]=solution_numerique(t,m)

    u_numerique(1)=1;
    dt= 1/m; //pas du temps
    
    for i = 1:m
        u_numerique(i+1) = (-1 + sqrt(1-dt*dt*u_numerique(i)*u_numerique(i)+2*dt*u_numerique(i)))/dt; //schema numerique
    end
    
endfunction
funcprot(0)
