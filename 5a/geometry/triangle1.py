def calcArea(a, b):
    area = abs(a[0]*b[1] - a[1]*b[0])/2
    return area

def main():
    points = list(map(int, input().split()))

    a = (points[2] - points[0], points[3] - points[1])
    b = (points[4] - points[0], points[5] - points[1])

    area = calcArea(a, b)

    print(round(area, 6))

if __name__ == '__main__':
    main()