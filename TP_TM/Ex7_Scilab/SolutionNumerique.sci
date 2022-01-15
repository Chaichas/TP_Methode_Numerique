function [u_numerique]=solution_numerique(t,m)

    u_numerique(1)=1;
    dt= 1/m; //pas du temps
    for i = 1:m
        u_numerique(i+1) = ((2-dt)/(2+dt)) * u_numerique(i); //u(m+1)
    end
    
endfunction
funcprot(0)
