set xlabel "Expace x"
set ylabel "u(x,t)"
plot "implicite.dat" with linespoints ls 1
pause -1
set terminal postscript eps enhanced color
set output 'myplot0.eps'
replot
