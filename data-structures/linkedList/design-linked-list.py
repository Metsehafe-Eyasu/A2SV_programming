class Node:
    def __init__(self, val: int) -> None:
        self.val = val
        self.next = None

class MyLinkedList:

    def __init__(self):
        self.head = None
        self.size = 0
            
    def get(self, index: int) -> int:
        if index < 0 or index >= self.size or self.head is None:
            return -1

        temp = self.head

        for i in range(index):
            temp = temp.next

        return temp.val

    def addAtHead(self, val: int) -> None:
        insertStart = Node(val)
        insertStart.next = self.head
        self.head = insertStart
        self.size += 1

    def addAtTail(self, val: int) -> None:
        insertEnd = Node(val)
        temp = self.head
        if temp is None:
            self.head = insertEnd
        else:
            while temp.next is not None:
                temp = temp.next
            temp.next = insertEnd
        self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.size:
            return
        if index == 0:
            self.addAtHead(val)
        else:
            temp = self.head
            for i in range(index-1):
                temp = temp.next
            value = Node(val)
            value.next = temp.next
            temp.next = value
            self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return
        temp = self.head
        if index == 0:
            self.head = temp.next
        else:
            for i in range(index-1):
                temp = temp.next
            temp.next = temp.next.next
        self.size -= 1