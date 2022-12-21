import random
if 1 < 5:
    print('hello world', 'this is a separated line', sep=' : ')
if 2 > 1:
    print('21~', end='')
    print('\tpneumonoultramicroscopicsilicovolcanoconiosis')
# this is a comment
    """
    this is supposed to be multi-line comment in 
    in python hence this will be proof
    """

x, y, z = 'this', 2, 69.42
print(type(x))
print(x, y, z)
print('float + int', y + z)

a = b = c = 2 + 3j
print('here ->', a + b + c, x)
print(6 < 9)


def myFunc():
    global a
    a = 9
    print('function', a)


myFunc()
print(a)

print(bool(a))

carName = 'Volvo'
print(carName)

print(random.randrange(1, 100))
if not carName and not 2 > 5:
    print('not null')

f = -15

print(f % 7)

l = """
        This is a multi line string
        main objective is to insure
        multiline strings can be
        assigned to variables
    """

print(l)

for v in carName:
    print(v)

if 'This' in l:
    print('string' in l, 'checker')
if 'volvo' not in l:
    print('barbie' in l, 'checker')

b = 'hElLo, WoRLd, this, is, a, MESSAGE'
print(b[2:7].upper(), b[-8:-3].lower(), sep=' -> ')

print(b.split(','))

print(b + ' ' + carName)

print(f'{f} {carName} sigma')

print('lLo' in b)

order = '{2}, {0}, {1}'
print(order.format(a, carName, b))
