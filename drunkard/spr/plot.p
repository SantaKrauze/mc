set terminal png size 1000,800

set output 'plot.png'

set xlab "log(N)"
set ylab "log(var)"

plot "../data.dat" title "log(var) = a*log(N)", 1.00228*x + 0.0324
