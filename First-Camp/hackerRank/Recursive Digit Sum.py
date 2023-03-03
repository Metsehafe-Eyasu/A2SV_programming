#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'superDigit' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING n
#  2. INTEGER k
#
def digitSum(s):
    if len(s) == 1:
        return s
    summed = sum(list(map(int, s))) 
    return digitSum([*str(summed)])

def superDigit(n, k):
    # Write your code here
    num = 0
    for i in str(n):
        num += int(i)
    
    p = [str(num) for _ in range(k)]
    return ''.join(digitSum(p))
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = first_multiple_input[0]

    k = int(first_multiple_input[1])

    result = superDigit(n, k)

    fptr.write(str(result) + '\n')

    fptr.close()
