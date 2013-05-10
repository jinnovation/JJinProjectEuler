import time

time_start = time.time()

################################################################################
#### Methods ####
def wordToNum(word):
    sum = 0

    for letter in word:
        sum += ord(letter) - ord('A') + 1

    return sum

def isTri(word):
    wordNum = wordToNum(word)
    for num in tris:
        if (wordNum == num):
            return True
    return False

################################################################################
#### Items ####
words = [word.strip('"\n').upper() for word in
         open("words.txt",'r').read().split(',')]


tris = []
n = 1
while  0.5*n*(n+1) < max([wordToNum(word) for word in words]):
    tris.append(int(0.5*n*(n+1)))
    n+=1
    

################################################################################
#### Procession ####

quant = 0
for word in words:
    if (isTri(word)):
        quant+=1

print quant
print "Runtime:",time.time()-time_start,"seconds"

