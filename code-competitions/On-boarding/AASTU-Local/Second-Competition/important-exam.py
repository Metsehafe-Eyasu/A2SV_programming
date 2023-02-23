from collections import Counter
students, questions = list(map(int, input().split()))
test = []
for i in range(students):
    inputList = list(input())
    test.append(inputList)
points = list(map(int, input().split()))

for i in range(questions):
    question = [test[a][i] for a in range(students)]
    countedQuestion = Counter(question)
    print(countedQuestion.most_common())
        
    
    



# print(test)