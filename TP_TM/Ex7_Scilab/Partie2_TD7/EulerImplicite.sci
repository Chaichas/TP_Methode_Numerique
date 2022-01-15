function [u_implicite]=euler_implicite(t,m)
 
    u_implicite(1)= 1; //solution a t =0
    dt= 1/m; //pas du temps
    for i = 1:m
           //u_implicite(i+1)= (-1/(2*dt)) + sqrt(abs(u_implicite(i)));
          //u_implicite(i+1)= (-1/(2*dt)) - sqrt(u_implicite(i));
          u_implicite(i+1)=(2*dt*sqrt(abs (u_implicite(i)))-1)/(2*dt);
    end;
    
endfunction
funcprot(0)
