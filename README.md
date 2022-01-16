# TP_Methode_Numerique
Ce depot contient:
1/ Le mini-projet du TD1 (Exercice 7),
2/ TP de Technique de Modelisation.

Schema explicite ==> U(n+1)=(Id + r * A) *U(n)
Schema implicite ==> U=inv(Id - r * A) *U(n)
schema crank-Nicholson ==> (Id + r * A) *U(n+1) = (Id - r * A) *U(n) --> U(n+1) = inv(Id + r * A) * (Id - r * A) *U(n)

