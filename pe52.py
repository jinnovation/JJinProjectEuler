def digits(n):
    return sorted(set(map(int,str(n))))

def same_digits(n1,n2):
    if digits(n1)==digits(n2):
        return True
    else:
        return False

def trial(n): # problem-specific test case
    return same_digits(n,2*n) and same_digits(n,3*n) and same_digits(n,4*n) and same_digits(n,5*n) and same_digits(n,6*n)

n = 1
while (not trial(n)):
    n+=1

print n
