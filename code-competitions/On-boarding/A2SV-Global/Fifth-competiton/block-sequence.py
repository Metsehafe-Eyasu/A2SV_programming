stacks, height = list(map(int, input().split()))
array = list(map(int, input().split()))
columns = [0] * max(array)
cumulative = 0
total = sum(array)
if stacks == 1:
    print(0)
else:
    length = max(array)
    for i in range(length):
        count = len(list(j for j in array if j >= i+1))
        columns[i] = count

    copy = [i for i in array]
    
    for i in range(length):
        print(copy)
        for j in range(stacks):
            if columns[i] > 1 and copy[j] > 1:
                cumulative += 1
                columns[i] -= 1
                copy[j] -= 1
            print(">  ",columns)
    print(total, cumulative)
        
    