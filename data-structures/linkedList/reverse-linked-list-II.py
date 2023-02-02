# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        prevPtr = None
        currentPtr = head
        for _ in range(left-1):
            prevPtr = currentPtr
            currentPtr = currentPtr.next

        tail = currentPtr
        leftPtr = prevPtr

        for _ in range(right-left + 1):
            nextNode = currentPtr.next
            currentPtr.next = prevPtr
            prevPtr = currentPtr
            currentPtr = nextNode

        if leftPtr:
            leftPtr.next = prevPtr
        else:
            head = prevPtr

        tail.next = currentPtr

        return head 