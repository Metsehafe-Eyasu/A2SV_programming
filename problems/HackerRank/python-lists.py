if __name__ == '__main__':
    N = int(input())
    array = []
    for i in range(N):
        inputList = input().split()
        if inputList[0] == 'insert':
            array.insert(int(inputList[1]), int(inputList[2]))
        elif inputList[0] == 'print':
            print(array)
        elif inputList[0] == 'remove':
            array.remove(int(inputList[1]))
        elif inputList[0] == 'append':
            array.append(int(inputList[1]))
        elif inputList[0] == 'sort':
            array.sort()
        elif inputList[0] == 'pop':
            array.pop()
        elif inputList[0] == 'reverse':
            array.reverse()
        