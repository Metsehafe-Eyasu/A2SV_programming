from collections import Counter
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        commonLetters = []

        firstWord = Counter(words[0])

        rest = words[1:]
        restList = []

        for i in rest:
            word = Counter(i)
            restList.append(word)
            
        for letter in firstWord:
            currLetter = firstWord[letter]
            for word in restList:
                if letter in word:
                    currLetter = min(currLetter, word[letter])
                else:
                    currLetter = 0
                    break
            for times in range(currLetter):
                commonLetters.append(letter)
                for word in restList:
                    word[letter] -= 1
        return commonLetters
