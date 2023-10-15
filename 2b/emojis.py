emojis = input()

start = ':;'
mid = "-"
end = '[]()'

stack = []
amount = 0
startFilling = False

for char in emojis:
    if char in start:
        if startFilling:
            continue
        stack.append( char )
        startFilling = True
    elif char in end and startFilling:
        stack.pop()
        startFilling = False
        amount += 1
    elif char in mid and startFilling:
        continue
    else:
        stack = []
        startFilling = False

# print( emojis )
# print( stack )
print( amount )
