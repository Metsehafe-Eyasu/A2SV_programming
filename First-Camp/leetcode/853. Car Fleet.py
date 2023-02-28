class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pairs = sorted(zip(position, speed))
        fleets = []
        for pos, spd in pairs:
            while fleets and spd < fleets[-1][1]:
                n = (pos - fleets[-1][0]) / (fleets[-1][1] - spd)
                if (pos + (spd*n)) <= target:
                    fleets.pop()
                else:
                    break
                    
            fleets.append((pos, spd))
        return len(fleets)