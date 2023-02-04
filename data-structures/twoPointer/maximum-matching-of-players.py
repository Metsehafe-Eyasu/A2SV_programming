class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort(reverse=True)
        trainers.sort(reverse=True)

        count = 0
        index = 0
        lengthP = len(players)
        lengthT = len(trainers)
        for i in range(lengthP):
            if index >= lengthT:
                break
            
            if players[i] <= trainers[index]:
                count += 1
                index += 1
        return count
            
