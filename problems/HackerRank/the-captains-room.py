# Enter your code here. Read input from STDIN. Print output to STDOUT
membersPerGroup = int(input())
listOfRooms = list(input().split(' '))
roomsDict = {}
length = len(listOfRooms)
for i in range(length):
    room = listOfRooms[i]
    if room in roomsDict:
        roomsDict[room] += 1
    else:
        roomsDict[room] = 1

for room in roomsDict:
    if roomsDict[room] != membersPerGroup:
        print(room)
        break