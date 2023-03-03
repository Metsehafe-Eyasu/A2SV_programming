class Solution:
    def decoder(self, index: int, s:str, length: int):
        num = ""
        char = ""
        while index < length:
            if s[index] == '[':
                string, ind = self.decoder(index + 1, s, length)
                char += int(num) * string
                index = ind
                num = ""
            elif s[index] == ']':
                return [char, index]
            elif s[index].isdigit():
                num += s[index]
            else:
                char += s[index]
            index += 1
        return [char, index] 

    def decodeString(self, s: str) -> str:
        string, index = self.decoder(0, s, len(s))
        return string
