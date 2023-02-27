recommends, minimum, questions = list(map(int, input().split()))

recipes = [0] * 2000002
for i in range(recommends):
    minVal, maxVal = list(map(int, input().split()))
    recipes[minVal] += 1
    recipes[maxVal+1] -= 1
        

for i in range(1, 2000002):
    recipes[i] += recipes[i-1]
    
prev = 0
for ind, val in enumerate(recipes):
    prev = recipes[ind]
    if val < minimum:
        recipes[ind] = 0
    else:
        recipes[ind] = 1

for i in range(1, 2000002):
    recipes[i] += recipes[i-1]
    

for i in range(questions):
    minVal, maxVal = list(map(int, input().split()))
    accepted = recipes[maxVal] - recipes[minVal - 1]
    print(accepted)

