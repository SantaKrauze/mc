set terminal png size 1000,800 enhanced

set xlabel "MCS"
set ylabel "m"
set yrange [-2:2]

set output "report/flips1.png"
plot "data/flips1.dat" u 2:1 title "L=8, T*=2"
set output "report/flips2.png"
plot "data/flips2.dat" u 2:1 title "L=10, T*=2.1"
set output "report/flips3.png"
plot "data/flips3.dat" u 2:1 title "L=15, T*=2"
