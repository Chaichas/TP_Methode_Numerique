set dgrid 
set pm3d
set xlabel "Expace x"
set ylabel "Temps t"
set zlabel "u(x,t)"
splot "ftcs.dat"
pause -1
set terminal postscript eps enhanced color
set output 'myplot.eps'
replot
