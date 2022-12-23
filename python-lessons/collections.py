list = [1, 2, 3, 4, 5]
list.append(2)
list.remove(2)
list.insert(1, 89)
# list.sort()
x = sorted(list)
print(list, x, sep='\n')
for i, num in enumerate(list):
    print("-> ", i , num)
z = list[1:4]
print(z)

apple = [x for x in range(10)]
print(apple)
fruits = ["apple", "banana", "cherry", "apple", "mango"]
print(fruits)
a, b, c, d, e = fruits
some = [x for x in fruits if x == 'apple']
print(some)
print(d, c, b, a)

aTuple = ("cherry", "banana", "apple")
print(aTuple)

a = [1, 2, 3]
b = a[:]

b[1] = 11
print(a)


g = {4, 2, 3}
g.discard(5)
for i in g:
    print(i)
print(g)
