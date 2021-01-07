set terminal png size 1000,800 enhanced
set encoding utf8

set xlabel "T*"
set ylabel "<m>"
set xrange [0:11]
set yrange [0:1.1]
set output "report/plot.png"
plot "data5.dat" u 2:1 with linespoints t "L=5", "data20.dat" u 2:1 with linespoints t "L=20", "data80.dat" u 2:1 with linespoints t "L=80"
