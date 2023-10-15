n = int(input())

Sherlock = list(input())
Moriarty = sorted(list(input()))

copySherlock = [ digit for digit in Sherlock ]
copyMoriarty = [ digit for digit in Moriarty ]

minHits = 0
maxHits = 0


#count minHits
for i in range(n):
    for j in range(n):
        if Moriarty[j] == -1:
            continue
        
        if Moriarty[j] >= Sherlock[i]:
            Moriarty[j] = -1
            Sherlock[i] = -1
            break

for i in range(n):
    if Moriarty[i] != -1:
        minHits += 1

#cout maxHits
for i in range(n):
    for j in range(n):
        if copyMoriarty[j] == -1:
            continue
        if copyMoriarty[j] > copySherlock[i]:
            maxHits += 1
            copyMoriarty[j] = -1
            break

print( minHits )
print( maxHits )