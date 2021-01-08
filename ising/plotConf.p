set terminal png size 1000,800 enhanced
set encoding utf8

set palette grey
set pm3d map
set cbrange [-1:1]
set output "report/conf5-01.png"
splot "data/5/t01" matrix w image notitle
set output "report/conf5-tc.png"
splot "data/5/tc" matrix w image notitle
set output "report/conf5-10.png"
splot "data/5/t10" matrix w image notitle

set output "report/conf20-01.png"
splot "data/20/t01" matrix w image notitle
set output "report/conf20-tc.png"
splot "data/20/tc" matrix w image notitle
set output "report/conf20-10.png"
splot "data/20/t10" matrix w image notitle

set output "report/conf80-01.png"
splot "data/80/t01" matrix w image notitle
set output "report/conf80-tc.png"
splot "data/80/tc" matrix w image notitle
set output "report/conf80-10.png"
splot "data/80/t10" matrix w image notitle
