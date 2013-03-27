def engLen_dig(d):
    if d==1 or d==2 or d==6:
        return 3
    elif d==3 or d==7 or d==8:
        return 5
    elif d==0 or d==4 or d==5 or d==9:
        return 4


def engLen_num(ds):
    len = sum(map(engLen_dig,map(int,str(ds))))
    if ds>100:
        len+=10 # "and" and "hundred"
    if ds>=1000:
        len+=8 # "thousand"

    return len


print engLen_num(342)

count = 0

for n in range (1,1001):
    count += engLen_num(n)

print count

