# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False
        turtle = rabbit = head
        turtle = turtle.next
        rabbit = rabbit.next.next
        while rabbit != turtle and rabbit != None and rabbit.next != None:
            turtle = turtle.next
            rabbit = rabbit.next.next
        
        if rabbit and rabbit.next:
            return True
        else:
            return False
