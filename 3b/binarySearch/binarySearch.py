import time

def testInput(binarySearch, numbers, targets):
    
    for target in targets:
        index = binarySearch(target, numbers)

        if numbers[index] == target:
            print('YES')
        else:
            print('NO')


def binarySearch(target, numbers):
    if(target > numbers[-1] or target < numbers[0]):
        return -1
    
    l, r = -1, len(numbers)

    while r - l > 1:
        m = (r + l)//2

        if target > numbers[m]:
            l = m
        else:
            r = m
    
    return r


def main():
        
    n, k = map(int, input().split())

    numbers = list(map(int, input().split()))
    targets = list(map(int, input().split()))

    testInput(binarySearch, numbers, targets)




if __name__ == '__main__':
    main()