n = map(int,list([n.strip() for n in open("pe8-input.txt","r").readlines()][0]))

max = 0
c = 0
while c<len(n)-4:
    p = n[c]*n[c+1]*n[c+2]*n[c+3]*n[c+4]
    if  p >= max:
        max = p
    c+=1

print max

