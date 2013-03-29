import time

begin = time.time()

# exponentiation by squaring
def better_pow(x,n):
    if n==1: 
        return x
    elif n%2==0:
        return better_pow(x*x,n/2)
    else:
        return x*better_pow(x*x,(n-1)/2)

# converts input to list of lists of 2 entries
pairs = [pair.strip().split(',') for pair in open("base_exp.txt","r")]

max = 0
max_linum = 0
linum = 1

for pair in pairs:
    print "Considering pair number",linum
    val = pow(int(pair[0]),int(pair[1]),1)# better_pow(int(pair[0]),int(pair[1])) # pow(int(pair[0]),int(pair[1]))
    if val>=max: 
        max = val
        max_linum = linum
    linum += 1


print max_linum

print "Execution time:",time.time()-begin,"seconds"
