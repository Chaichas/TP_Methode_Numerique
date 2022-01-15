clf();

dt=[0.01, 0.01111, 0.0125, 0.014286, 0.01667, 0.02, 0.025, 0.03333, 0.05, 0.1]; //pas du temps

err_num = [0.0000083, 0.0000103, 0.0000130, 0.0000170, 0.0000231, 0.0000333,  0.0000521, 0.0000926, 0.0002084, 0.0008342];
err_explicite = [0.0050209, 0.0055814, 0.0062828, 0.0071857, 0.0083917, 0.0100842, 0.0126319, 0.0169021, 0.0255342, 0.0521937];
err_implicite = [0.0049793, 0.0055814, 0.0062176, 0.0071006, 0.0082759, 0.0099175, 0.0123714, 0.0164390, 0.0244918, 0.0480153];
[a, b] = reglin(dt, err_explicite);
//plot2d(dt, err_num,12,logflag='nl'); 
//plot("nlnl",n,err_explicite,n,err_implicite);
plot2d(dt, err_explicite,3); 
plot2d(dt, err_implicite,5); 

//plot2d(dt, err_explicite, "green",logflag='nl');
plot2d(dt, a*dt+b);

legend(["Erreur Explicite", "Erreur Implicite","Moindre-Carree"],"in_upper_left")

xlabel("Pas du Temps dt")
ylabel("Erreurs")
