number = int(input())
length = len(str(number))

iterableNum = str(number)
minValue = number

for i in range(length):
    if i == 0 and iterableNum[i] == '9':
        continue
    rev = str(9 - int(iterableNum[i]))
    val = iterableNum[:i] + rev + iterableNum[i+1:]
    if int(val) < minValue:
        minValue = int(val)
        iterableNum = val
print(minValue)