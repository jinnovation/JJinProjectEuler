import time
import math

start = time.time()

max = 2540160 # 7*9! => 7 digits

print sum([x for x in range (3,max+1) if x==sum(map(math.factorial,map(int,str(x))))])
print "Execution time:",(time.time()-start)*1000,"ms"
