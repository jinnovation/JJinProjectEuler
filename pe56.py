dsum = 0

for a in range (1,100): # don't need to consider case a=0
    for b in range (0,100):
        s = sum(map(int,str(pow(a,b))))
        if s>=dsum:
            dsum = s

print dsum
