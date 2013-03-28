import time

begin = time.time()

# converts input to list of lists of 2 entries
pairs = [pair.strip().split(',') for pair in open("base_exp.txt","r")]

max = 0
max_linum = 0
linum = 1

# godawful unacceptably slow
for pair in pairs:
    print linum
    val = pow(int(pair[0]),int(pair[1]))
    if val>=max: 
        max = val
        max_linum = linum
    linum += 1


print max_linum

print "Execution time:",time.time()-begin,"seconds"
