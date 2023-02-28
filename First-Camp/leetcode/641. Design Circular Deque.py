class MyCircularDeque:

    def __init__(self, k: int):
        self.MAX = k
        self.circDeque = deque()

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        self.circDeque.appendleft(value)
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        self.circDeque.append(value)
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        self.circDeque.popleft()
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        self.circDeque.pop()
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.circDeque[0]

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.circDeque[-1]
        

    def isEmpty(self) -> bool:
        if len(self.circDeque) == 0:
            return True
        return False

    def isFull(self) -> bool:
        if len(self.circDeque) == self.MAX:
            return True
        return False