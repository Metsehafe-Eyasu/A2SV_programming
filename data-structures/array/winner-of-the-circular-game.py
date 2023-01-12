n = 5
k = 2

players = [i for i in range(1, n + 1)]
print(players)
index = -1

for i in range(n-1):
    length = len(players)
    index =(index + k) % length+1
    players.remove(index+1)
    print(index)
    print(players)

