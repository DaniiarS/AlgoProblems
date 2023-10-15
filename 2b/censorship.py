input_file = open( 'input.txt', 'r', encoding = 'cp866')

text = input_file.read().split('\n')
original_text = [ line for line in text ]
text = [ line.split() for line in text ]

symbols = '.!?:-,;()'
size_of_text = len(text)


valid_lines = {}
for i in range(size_of_text):
    valid_lines[i] = True


# Delete ending symbols
for i in range( size_of_text ):
    size_of_line = len( text[i] )
    for j in range( size_of_line ):
        symbol = text[i][j][-1]
        symbol_index = symbols.find( symbol )

        if symbol_index != -1:
            text[i][j] = text[i][j].split( symbols[ symbol_index ] )[0]

for line in text:
    for word in line:
        print( word, len( word ) )

# Count "special" words
for i in range( size_of_text ):
    size_of_line = len( text[i] )
    suspect = 0

    for j in range( size_of_line ):
        size_of_word = len( text[i][j] )//2
        letters =[]
        ch = ''

        for k in range( 0, size_of_word, 2 ):
            ch += text[i][j][]

        if len(set(letters)) <= 3:
            suspect = suspect + 1
    
    if suspect >= size_of_line//2 + size_of_line%2:
        valid_lines[i] = False



output_file = open( 'output.txt', 'w', encoding = 'cp866' )

for i in range( size_of_text ):
    if ( valid_lines[i] ):
        if i == size_of_text - 1:
            output_file.write( original_text[i] )
            break
        output_file.write( original_text[i] + '\n' )

input_file.close()
output_file.close()

