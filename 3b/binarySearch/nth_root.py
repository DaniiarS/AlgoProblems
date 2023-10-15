import time

def f(x, n):
    return x ** n

def binarySearch(target, n):
    l, r = 0, 1e10 
    eps = 1e-10

    while r - l > eps:
        m = (r + l)/2
        
        if f(m, n) <= target:
            l = m
        else:
            r = m
    
    return l

def main():
    target = float(input())
    n = int(input())

    result = binarySearch(target, n)

    print(result)


if __name__ == '__main__':
    main()
