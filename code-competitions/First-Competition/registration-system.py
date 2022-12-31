from collections import defaultdict
database = defaultdict(int)
total = int(input())
for i in range(total):
    string = input()
    if database[string] > 0:
        print(string + str(database[string]))
    else:
        print('OK')
    database[string] += 1
