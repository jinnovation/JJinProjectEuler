# roman numeral "digit" -> arabic num
def romAra_single(num):
    if num=='M':
        return 1000
    elif num=='D':
        return 500
    elif num=='C':
        return 100
    elif num=='L':
        return 50
    elif num=='X':
        return 10
    elif num=='V':
        return 5
    elif num=='I':
        return 1
    # TODO: error case


# roman num -> arabic num
# BUG: makes naive assumption that there are no "subtractions" present (eg. IV)
# def romAra(num):
#     return sum(map(romAra_single,list(num)))

# def romAra(num):
#     arabic = 0
#     for digit in list(num):
#         # if current rdigit < next rdigit, arabic += (-current)
#         # else, arabic += current
        

rnums = [line.strip() for line in open('roman.txt','r')]

# print  romAra(rnums[0])
    
