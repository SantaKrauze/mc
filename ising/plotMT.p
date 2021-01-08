set terminal png size 1000,800 enhanced
set encoding utf8

set xlabel "T*"
set ylabel "<m>"
set xrange [0:11]
set yrange [0:1.1]
set output "report/MofT.png"
plot "data/data5.dat" u 2:1 with points t "L=5", "data/data20.dat" u 2:1 with points t "L=20", "data/data80.dat" u 2:1 with points t "L=80"
