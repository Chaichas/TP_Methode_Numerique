clf();

dt=[0.01, 0.01111, 0.0125, 0.014286, 0.01667, 0.02, 0.025, 0.03333, 0.05, 0.1]; //pas du temps
dt2=[0.0001, 0.000123432, 0.00015625, 0.00020409, 0.000277889 , 0.0004 ,0.000625 , 0.001110889, 0.0025 ,0.01];

err_num = [0.0000125, 0.0000154, 0.0000195, 0.0000255, 0.0000347, 0.0000500, 0.0000781, 0.0001389, 0.0003127, 0.0012537];
err_explicite = [0.0034837, 0.0038730, 0.0043603, 0.0049878, 0.0058263, 0.0070037, 0.0087777, 0.0117551, 0.0177902, 0.0365742];
err_implicite = [0.0034480, 0.0038290, 0.0043046, 0.0049150, 0.0057273, 0.0068612, 0.0085548, 0.0113589, 0.0168979, 0.0329878];

subplot(1,2,1)
//Moindre carree pour err_explicite
[a, b] = reglin(dt, err_explicite);
plot2d(dt, err_explicite,3); 
plot2d(dt, a*dt+b);
legend(["Erreur Explicite","Moindre-Carree"],"in_upper_left")

xlabel("Pas du Temps dt")
ylabel("Erreur du schema explicite")

subplot(1,2,2)
//Moindre carree pour err_implicite
[a1, b1] = reglin(dt, err_implicite);
plot2d(dt, err_implicite,5);
plot2d(dt, a1*dt+b1);

legend(["Erreur Implicite","Moindre-Carree"],"in_upper_left")

xlabel("Pas du Temps dt")
ylabel("Erreur du schema implicite")


//Moindre carree pour err_implicite
//[a, b] = reglin(dt2, err_num);
//plot2d(dt2, err_num,5);
//plot2d(dt2, a*dt2+b);
//legend(["Erreur Numerique","Moindre-Carree"],"in_upper_left")
//xlabel("Pas du Temps dt*dt")
//ylabel("Erreur du schema numerique")
