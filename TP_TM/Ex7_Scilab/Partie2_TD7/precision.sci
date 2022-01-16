t =1; //temps
m=100; //nombre de points
dt= 1/m; //pas du temps

[u_exacte]= solution_exacte(t); //solution exacte, systeme (E2)
[u_numerique]=solution_numerique(t,m); //solution numerique, systeme (E2)
[u_explicite]=euler_explicite(t,m); //Euler explicite, systeme (E2)
[u_implicite]=euler_implicite(t,m); //Euler implicite, systeme (E2)

//Erreurs relatives

erreur_num= norm(u_exacte - u_numerique(m+1))/norm(u_exacte); //precision schema nimerique
disp(erreur_num);

erreur_explicite= norm(u_exacte - u_explicite(m+1))/norm(u_exacte); //precision Euler explicite
disp(erreur_explicite);

erreur_implicite= norm(u_exacte - u_implicite(m+1))/norm(u_exacte); //precision Euler implicite
disp(erreur_implicite);

//Calcul et comparison de k
k_num = sqrt(erreur_num/dt^2);
disp(k_num);

k_explicite = erreur_explicite/dt;
disp(k_explicite);

k_implicite = erreur_implicite/dt;
disp(k_implicite);

funcprot(0)
