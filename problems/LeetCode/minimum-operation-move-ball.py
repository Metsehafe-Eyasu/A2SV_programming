class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        boxList = [*boxes]
        answer = []
        length = len(boxList)

        for i in range(length):
            sum = 0
            for j in range(length):
                if i == j:
                    continue
                if boxList[j] == '1':
                    sum += abs(i-j)
            answer.append(sum)

        return answer