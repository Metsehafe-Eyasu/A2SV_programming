total = int(input())
laptops = dict()
for _ in range(total):
    price, quality = list(map(int, input().split()))
    laptops[price] = quality

sorter = sorted(laptops)
sortedLaptops = {i: laptops[i] for i in sorter}

prev = 0
for i in sortedLaptops.keys():
    if prev > sortedLaptops[i]:
        print("Happy Alex")
        exit()
    prev = sortedLaptops[i]
print("Poor Alex")