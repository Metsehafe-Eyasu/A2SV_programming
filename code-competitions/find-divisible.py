query = int(input())
for i in range(query):
    start, end = list(map(int, input().split()))
    
    final = end - (end % start)
    print(start, final)
