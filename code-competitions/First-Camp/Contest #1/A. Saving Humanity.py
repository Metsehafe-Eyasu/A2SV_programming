from collections import defaultdict
cases = int(input())
for _ in range(cases):
    total, iterations = list(map(int, input().split()))
    soldiers = list(map(int, [*input()]))
    left = 0
    right = 1
    while right < total:                    
        if soldiers[right] == 1:
            if soldiers[left] == 1:
                tempRight = right - 1
                tempLeft = left + 1
                iter = iterations
                while tempLeft < tempRight and iter > 0:
                    soldiers[tempRight] = '1'
                    soldiers[tempLeft] = '1'
                    tempLeft += 1
                    tempRight -= 1
                    iter -= 1
            elif soldiers[right] == 1:
                tempRight = right - 1
                iter = iterations
                while tempRight >= left and iter > 0:
                    soldiers[tempRight] = '1'
                    tempRight -= 1
                    iter -= 1
            left = right
        elif right == total and soldiers[left] == 1 and soldiers[right] == '0':
            iter = iterations
            tempLeft = left + 1
            while tempLeft <= right and iter > 0:
                soldiers[tempLeft] = '1'
                tempLeft += 1
                iter -= 1
        right += 1
    print(*soldiers, sep='')
    

# from collections import defaultdict
# cases = int(input())
# for _ in range(cases):
#     total, iterations = list(map(int, input().split()))
#     soldiers = list(map(int, [*input()]))
#     left = 0
#     right = 1
#     while right <= total:
#         if right == total:
#             while left < total and soldiers[left] == 1 and left < right and iterations > 0:
#                 soldiers[left] = 1
#                 left += 1
#                 iterations -= 1
#             break
                    
#         if soldiers[right] == 1 and soldiers[left] == 1:
#             tempRight = right - 1
#             tempLeft = left + 1
#             iter = iterations
#             while tempLeft < tempRight and iter > 0:
#                 soldiers[tempRight] = 1
#                 soldiers[tempLeft] = 1
#                 tempLeft += 1
#                 tempRight -= 1
#                 iter -= 1
#             left = right
#         elif soldiers[right] == 1:
#             tempRight = right - 1
#             iter = iterations
#             while tempRight >= left and iter > 0:
#                 soldiers[tempRight] = 1
#                 tempRight -= 1
#                 iter -= 1
#             left = right
#         right += 1
#     print(*soldiers, sep="")