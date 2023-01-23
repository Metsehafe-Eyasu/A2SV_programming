size = int(input())
array = list(map(int, input().split()))

start = 0
end = 0

i = 0 
rev = False
while(i < size-1):
    if array[i] > array[i+1]:
        rev = True
        start = i
        break
    i+=1
# i+=1
while(i < size-1):
    if array[i] < array[i+1]:
        end = i
        break
    i+=1
# i+=1

end = size-1 if rev and end == 0 else end
while(i < size-1):    
    if array[i] > array[i+1] or array[start] > array[i+1]:
        print('no')
        exit()
    i+=1

print('yes')
print(array[end], array[start])