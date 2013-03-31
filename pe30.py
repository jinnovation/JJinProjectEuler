import time

start = time.time()

max = 355000 # 6*9^5 = 354294

print sum([x for x in xrange(2,max+1) if x ==sum(map(lambda x: x**5,map(int,str(x))))])
print "Execution time",(time.time()-start)*1000,"ms"
