A, B, AB = list(map(int, input().split()))

total = AB*2
if B > A:
    total += A + 1 + A 
elif A > B:
    total += B + 1 + B 
else:
    total += A + B
print(total)