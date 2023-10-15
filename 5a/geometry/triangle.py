def calcDistance(x1, y1, x2, y2):
    distance = ((x2 - x1)**2 + (y2 - y1)**2)**0.5
    return distance

def calcArea(a, b, c):
    p = (a + b + c)/2
    area = (p * (p - a) * (p - b) * (p - c))**0.5
    return area

def main():
    
    points = list(map(int, input().split()))

    a = calcDistance( points[0], points[1], points[2], points[3] )
    b = calcDistance( points[2], points[3], points[4], points[5] )
    c = calcDistance( points[4], points[5], points[0], points[1] )

    area = round( calcArea(a, b, c), 6 )

    print(area)

if __name__ == '__main__':
    main()