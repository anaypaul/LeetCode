"""
Reverse bits of a given 32 bits unsigned integer.
"""
def reverseBits(n):
    x = bin(n)[2:]
    add = 32 - len(x)
    while(add>0):
        add -= 1
        x = "0" + x
    result = 0
    for i in range(len(x)):
        result += (2**i)*int(x[i])
    return result
