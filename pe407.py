def Mn(n):
    largest = 0;
    for a in range (0,n):
        if (a*a)%n == a and a>=largest:
            largest = a
    return largest

print sum(map(Mn,range (1,pow(10,7)+1)))
