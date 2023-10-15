line = list(input())

length = len(line)
newLength = length


ptr = 0
index = 0
nextIsDot = False

while index != length:
    if line[index] == '@':
        index += 1
        newLength -= 1
        continue
    line[ptr] = line[index]
    ptr += 1
    index += 1
    nextIsDot = False

for i in range(newLength):
    print(line[i], end = '')
print()