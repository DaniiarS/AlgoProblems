
def testBinarySearch(nearest_int, targets, numbers):
    for target in targets:
        index = nearest_int(target, numbers)
        print( numbers[index] )

def nearest_int(target, numbers):
    if target > numbers[-1]:
        return -1
    elif target < numbers[0]:
        return 0
    
    l , r = -1, len(numbers)

    while r - l > 1:
        m = (r + l)//2

        if numbers[m] < target:
            l = m
        else:
            r = m
    
    if(abs(numbers[r] - target) >= abs(numbers[l] - target)):
        return l
    
    return r

def main():
    n , k = map(int, input().split())

    numbers = list(map(int, input().split()))
    targets = list(map(int, input().split()))

    testBinarySearch(nearest_int, targets, numbers)


if __name__ == '__main__':
    main()