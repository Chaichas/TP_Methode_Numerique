function [f]= func1(x)
    if ((x > 0) && (x <= 1/2)) then
        f = 2*x; //Expression de la fonction pour x in ]0,1/2]
    end
    if ((x > 1/2) && (x < 1)) then
        f = 2*(1-x); //Expression de la fonction pour x in ]1/2,1[
    end

endfunction
funcprot(0)
