f1 = 1
f2 = 1
fnL = 1
count = 2

while fnL != 1000:
    fn = f1+f2
    fnL = len(str(fn))
    f1 = f2
    f2 = fn
    count+=1

print count
