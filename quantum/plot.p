set terminal png size 1000,800 enhanced
set output "plot.png"

set xlab "MSC"
set ylab "E"

plot "data" u 2:1 title "E(x)"
