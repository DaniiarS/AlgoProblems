def good(size, w, h, n):
    return ( (size//w) * (size//h) ) >= n

def square_size(w, h, n):

    l, r = 0, (n * w + n * h)

    while r - l > 1:
        m = (r + l) // 2

        if good(m, w, h, n):
            r = m
        else:
            l = m
    
    return r


def main():

    w, h, n = map(int, input().split())
    print(square_size(w, h, n))


if __name__ == '__main__':
    main()