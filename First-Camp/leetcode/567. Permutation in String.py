class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        length1 = len(s1)
        length2 = len(s2)
        if length2 < length1:
            return False
        count_s1 = [0]*26
        count_s2 = [0]*26
        for i in range(length1):
            count_s1[ord(s1[i]) - 97] += 1
            count_s2[ord(s2[i]) - 97] += 1
        for i in range(length2 - length1 + 1):
            if count_s1 == count_s2:
                return True
            if i == length2-length1:
                break
            count_s2[ord(s2[i + length1]) - 97] += 1
            count_s2[ord(s2[i]) - 97] -= 1
        return False