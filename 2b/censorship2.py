
myFile = open( 'input.txt', encoding = 'cp866' )

print( myFile.read().split('\n') )
print()
print( myFile.read().encode('cp866') )