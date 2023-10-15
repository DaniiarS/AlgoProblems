line = input().split()
stack = []

digits = "0123456789"

for symbol in line:
    if symbol in digits:
        stack.append(int(symbol))
    else:
        a = stack.pop()
        b = stack.pop()

        if symbol == '+':
            stack.append( b + a )
        elif symbol == '-':
            stack.append( b - a )
        else:
            stack.append( b * a )


print( stack[0] )