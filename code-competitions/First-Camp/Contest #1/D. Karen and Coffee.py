recommends, minimum, questions = list(map(int, input().split()))

recipes = [0] * 2000002

recipeList = []
for i in range(recommends):
    minVal, maxVal = list(map(int, input().split()))
    recipeList.append([minVal, maxVal])
    
for minVal, maxVal in recipeList:
    recipes[minVal] += 1
    recipes[maxVal+1] -= 1
        
questionList = []
for i in range(questions):
    minVal, maxVal = list(map(int, input().split()))
    questionList.append([minVal, maxVal])

for i in range(1, 2000002):
    recipes[i] += recipes[i-1]
    
for ind, val in enumerate(recipes):
    if val < minimum:
        recipes[ind] = 0
    else:
        recipes[ind] = 1

for i in range(1, 2000002):
    recipes[i] += recipes[i-1]
 
for minVal, maxVal in questionList:
    accepted = recipes[maxVal] - recipes[minVal - 1]
    print(accepted)