# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None
        turtle = head.next
        rabbit = head.next.next

        while rabbit != turtle and rabbit != None and rabbit.next != None:
            turtle = turtle.next
            rabbit = rabbit.next.next
        if not rabbit or not rabbit.next:
            return None
        
        turtle = head
        while rabbit != turtle:
            rabbit = rabbit.next
            turtle = turtle.next
        return turtle
