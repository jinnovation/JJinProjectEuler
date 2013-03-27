import time
begin = time.time()

def alphaVal(char):
    return ord(char.upper())-ord('A')+1

names = open("names.txt","r").read()

names = [name.strip('"') for name in names.split(',')]
names.sort()

rank = 1
score = 0

for name in names:
    alpha = sum(map(alphaVal,list(name)))
    score += alpha*rank
    rank += 1

print score
print "Execution time:",(time.time()-begin)*1000,"ms"
