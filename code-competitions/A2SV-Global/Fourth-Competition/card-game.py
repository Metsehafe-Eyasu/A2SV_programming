length = int(input())
cards = list(map(int, input().split()))

right = length - 1
left = 0

isTurn = True
answer = [0, 0]
while left <= right:
    if isTurn:
        if cards[right] > cards[left]:
            answer[0] += cards[right]
            right -= 1
        else:
            answer[0] += cards[left]
            left += 1
        isTurn = False
    else:
        if cards[right] > cards[left]:
            answer[1] += cards[right]
            right -= 1
        else:
            answer[1] += cards[left]
            left += 1
        isTurn = True
print(*answer)