import shlex

# names = open("names.txt","r").read().split(",")
# names.sort()

names = open("test.txt","r").read()

# names = shlex.split(names)
names = names.split(',')
# names.sort()

for x in names:
    x=x.strip('"')


print names
