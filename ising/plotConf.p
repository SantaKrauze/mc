set terminal png size 1000,800 enhanced
set encoding utf8

set palette grey
set pm3d map
set cbrange [-1:1]
set output "report/conf5.png"
splot "5" matrix w image notitle
set output "report/conf20.png"
splot "20" matrix w image notitle
set output "report/conf80.png"
splot "80" matrix w image notitle
