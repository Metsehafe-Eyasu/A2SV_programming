cases = int(input())
for _ in range(cases):
    length = int(input())
    array = list(map(int, input().split()))

    i = 0
    answer = 0
    while i < length:
        maxVal = array[i]
        if array[i] < 0:
            while i < length:
                if array[i] > 0:
                    break
                maxVal = max(maxVal, array[i])
                i+=1
            answer += maxVal
        else:
            while i < length:
                if array[i] < 0:
                    break
                maxVal = max(maxVal, array[i])
                i+=1
            answer += maxVal
    print(answer)