# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return None

        tail = head
        listLength = 1

        while tail.next:
            tail = tail.next
            listLength += 1

        k = k % listLength
        tail.next = head
        rotatePoint = head

        for _ in range(listLength - k - 1):
            rotatePoint = rotatePoint.next

        newHead = rotatePoint.next
        rotatePoint.next = None
        return newHead