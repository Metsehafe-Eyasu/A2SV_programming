class DataStream:

    def __init__(self, value: int, k: int):
        self.k = k
        self.value = value
        self.equal = 0  

    def consec(self, num: int) -> bool:
        if num == self.value:
            self.equal += 1
        else:
            self.equal = 0
        
        if self.equal >= self.k:
            return True
        return False