set dgrid 
set pm3d
set xlabel "Expace x"
set ylabel "Temps t"
set zlabel "u(x,t)"
#splot[0:1] [0:1] "ftcs.dat"
splot "implicite_3D.dat"
pause -1
set terminal postscript eps enhanced color
set output 'myplot.eps'
replot
