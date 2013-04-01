import time

begin = time.time()

# give base 10, return palindrome-ness in base 10
def pal10(n):
    num = str(n)

    for i in range (0,len(num)):
        if num[i]==num[len(num)-1-i]:
            continue
        else:
            return False

    return True

# given base 10, return palindrome-ness in base 2
def pal2(n):
    return pal10(bin(n)[2:]) # first two chars of binary '0' & 'b'
    
sum = 0

for num in range (1,1000000):
    if pal10(num) and pal2(num):
        sum+=num
    else:
        continue

print sum
print "Execution time:",(time.time()-begin)*1000,"ms"
