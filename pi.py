#!/usr/bin/env python
import random

no = 0
n = 100000000
i = 0

while (i < n):
    x = random.random()
    y = random.random()

    if (x*x+y*y < 1):
        no = no + 1
    i = i + 1
    #print(x,y)

pi = 4*no/n
print(pi)
