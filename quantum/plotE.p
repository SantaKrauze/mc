set terminal png size 1000,800 enhanced
set output "energy.png"

set xlab "MSC"
set ylab "E"

plot "energy.dat" u 2:1 title "E(MCS)"
