cases = int(input())
for _ in range(cases):
    nonMal = set()
    string = [*input()]
    length = len(string)
    i = 0
    while i < length:
        if string[i] in nonMal:
            i+=1
            continue
        if i < length-1 and string[i] != string[i+1]:
            nonMal.add(string[i])
            i+=1
        elif i < length-1 and string[i] == string[i+1]:
            i+=2
        elif i == length-1:
            nonMal.add(string[i])
            i+=1
    answer = sorted(nonMal)
    print(*answer, sep='')