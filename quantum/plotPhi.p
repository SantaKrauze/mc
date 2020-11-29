set terminal png size 1000,800 enhanced
set output "report/phi.png"

set xlab "x"
set ylab "phi"

plot "phi.dat" title "phi(x)"
