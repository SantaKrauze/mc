set terminal png size 1000,800 enhanced

set xlabel "MCS"
set ylabel "m"
set xrange [25000:235000]
set yrange [-2:2]

set output "report/flips5.png"
plot "flips5.dat" u 2:1 title "L=5, T*="
set output "report/flips20.png"
plot "flips20.dat" u 2:1 title "L=20, T*=1.7"
set output "report/flips80.png"
plot "flips80.dat" u 2:1 title "L=80, T*="
