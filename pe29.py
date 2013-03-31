import time

start = time.time()

print len(set([a**b for a in xrange (2,101) for b in xrange (2,101)]))
print "Execution time:",(time.time()-start)*1000,"ms"
