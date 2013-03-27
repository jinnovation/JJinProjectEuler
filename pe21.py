import math

def properDivisorSum(n):
    sum = 1
    for d in range (2,int(math.ceil(math.sqrt(n)+1))):
        if n%d==0:
            sum += d + n/d
    return sum

def amicable(n1,n2):
    if properDivisorSum(n1)==n2 and properDivisorSum(n2)==n1 and n1!=n2:
        return True
    else:
        return False

asum = 0
for n in range (1,10001):
    if amicable(n,properDivisorSum(n)):
        asum += n

print asum
    
