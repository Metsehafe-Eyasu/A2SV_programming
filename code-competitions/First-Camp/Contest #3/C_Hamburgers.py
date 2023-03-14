from collections import Counter, defaultdict

def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()


def solution():
    ingredients = strInput()
    avBread, avSausage, avCheese = intList()
    prBread, prSausage, prCheese = intList()
    cash = intInput()
    
    recipe = Counter(ingredients)
    count = 0
    
    if avBread >= recipe['B'] and avCheese >= recipe['C'] and avSausage >= recipe['S']:
        count += min(avBread - recipe['B'], avCheese - recipe['C'], avSausage - recipe['S'])
        avBread -= count*recipe['B']
        avCheese -= count*recipe['C']
        avSausage -= count*recipe['S']
     if avBread >= recipe['B'] or avCheese >= recipe['C'] or avSausage >= recipe['S']:
         
    needed = 0
    diff1 = recipe['S'] - avSausage    
    diff2 = recipe['S'] - avSausage
    diff3 = recipe['B'] - avBread
    
    
    
    
    
    total = prBread*recipe['B'] + prCheese*recipe['C'] + prSausage*recipe['S']
    count += cash // total
    # while True:
    #     b = s = c = False
    #     if avBread >= recipe['B']:
    #         avBread -= recipe['B']
    #         b = True
    #     if avCheese >= recipe['C']:
    #         avCheese -= recipe['C']
    #         c = True
    #     if avSausage >= recipe['S']:
    #         avSausage -= recipe['S']
    #         s = True
        
    #     if not (s and c and b):       
    #         needed = 0
    #         if not s:
    #             diff = recipe['S'] - avSausage
    #             avSausage = 0
    #             needed += prSausage*diff
    #         if not c:
    #             diff = recipe['C'] - avCheese
    #             avCheese = 0
    #             needed += prCheese*diff
    #         if not b:
    #             diff = recipe['B'] - avBread
    #             avBread = 0
    #             needed += prBread*diff
            
    #         if needed > cash:
    #             break
    #         else:
    #             cash -= needed
    #     count += 1
        
    #     if avSausage == 0 and avCheese == 0 and avBread == 0:
    #         total = prBread*recipe['B'] + prCheese*recipe['C'] + prSausage*recipe['S']
    #         count += cash // total
    #         break
        
    return count




# cases = intInput()
cases = 1
for i in range(cases):
    print(solution())