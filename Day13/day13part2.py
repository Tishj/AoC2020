import math

def chineseRemainder(n, a):
    sum = 0
    product = math.prod(n)
    for i, j in zip(n, a):
        p = product // i
        sum += j * modInv(p, i) * p
    return sum % product

def modInv(a, b):
    b0 = b
    x0, x1 = 0, 1
    if b == 1:
        return (1)
    while a > 1:
        q = a // b
        a, b = b, a % b
        x0, x1 = x1 - q * x0, x0
    if x1 < 0:
        x1 += b0
    return x1

data = open("input.txt", "r").read().split("\n")
leaveTime = int(data[0])
busses = data[1].split(",")

n, a = [], []
for i, j in enumerate(busses):
    if j != 'x':
        n.append(int(j))
        a.append(int(j)-i)
print(chineseRemainder(n, a))