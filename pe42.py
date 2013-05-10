import time

time_start = time.time()

def wordToNum(word):
    sum = 0

    for letter in word:
        sum += ord(letter) - ord('A') + 1

    return sum

def wordIsTri(word):
    # TODO
    return True
    

words = [word.strip('"\n').upper() for word in
         open("words.txt",'r').read().split(',')]

wordSums = [wordToNum(word) for word in words]

print words
print wordSums
print "Runtime:",time.time()-time_start,"seconds"
