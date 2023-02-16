# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        turtle = head
        rabbit = head
        while rabbit and rabbit.next:
            turtle = turtle.next
            rabbit = rabbit.next.next
        
        prev = None
        while turtle:
            nxt = turtle.next
            turtle.next = prev
            prev = turtle
            turtle = nxt
        maxTwinSum = 0
        
        while prev:
            maxTwinSum = max(maxTwinSum, head.val + prev.val)
            head = head.next
            prev = prev.next

        return maxTwinSum
