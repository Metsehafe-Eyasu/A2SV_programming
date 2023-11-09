class MyCircularQueue:

    def __init__(self, k: int):
        self.queue = [None]*k
        self.MAX_SIZE = k
        self.top = -1
        self.bottom = -1
        self.size = 0

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        if self.bottom == -1:
            self.top = 0
            self.bottom = 0
        else:
            self.bottom = (self.bottom + 1) % self.MAX_SIZE
        self.queue[self.bottom] = value
        self.size += 1
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.queue[self.top] = None
        if self.top == self.bottom:
            self.top = self.bottom = -1
        self.top = (self.MAX_SIZE + self.top + 1) % self.MAX_SIZE
        self.size -= 1
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.queue[self.top]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.queue[self.bottom]

    def isEmpty(self) -> bool:
        if self.size == 0:
            return True
        return False

    def isFull(self) -> bool:
        if self.size == self.MAX_SIZE:
            return True
        return False
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()