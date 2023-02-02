# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        slow = ListNode()
        slow.next = head
        fast = head
        head = slow
        index = 0
        while index < n:
            fast = fast.next
            index += 1
        
        while fast:
            slow = slow.next
            fast = fast.next
        if slow.next:
            slow.next = slow.next.next
        return head.next

