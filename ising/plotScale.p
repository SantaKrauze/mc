
set xlabel "ln[(|1-T/Tc|)L^(1/v)]"
set ylabel "ln[ml^(b/v)]"

plot "data/scale5.csv" u 5:4 t "L=5", "data/scale20.csv" u 5:4 t "L=20", "data/scale80.csv" u 5:4 t "L=80"
