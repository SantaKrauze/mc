set terminal png size 1000,800 enhanced
set encoding utf8

set palette grey
set pm3d map
set output "report/5-Tc.png"
splot "5" matrix w image notitle
set output "report/20-Tc.png"
splot "20" matrix w image notitle
set output "report/80-Tc.png"
splot "80" matrix w image notitle
