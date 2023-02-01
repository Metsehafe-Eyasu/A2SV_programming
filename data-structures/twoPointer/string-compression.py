
class Solution:
    def compress(self, chars: List[str]) -> int:
        length = len(chars)
        initial = chars[0]
        answer = []
        count = 0
        for i in range(length + 1):
            if i < length and initial == chars[i]:
                count += 1
            else:
                answer.append(initial)

                if i < length:
                    initial = chars[i]
                
                if count > 1:
                    answer.extend([*str(count)])
                count = 1
        chars.clear()
        for i in answer:
            chars.append(i)
        return len(answer)
            