lines = int(input())
nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}
for i in range(lines):
    string = list(input().split())
    ordered = dict()
    for j in string:
        output = ''
        for letter in j:
            if letter not in nums:
                output += letter

        for letter in j:
            if letter in nums:
                ordered[letter] = output
                break
    length = len(ordered)
    print(*ordered.values(), sep=' ')
    for k in range(1, length):
        print(ordered[str(k)], end=' ')
    print(ordered[str(length)])