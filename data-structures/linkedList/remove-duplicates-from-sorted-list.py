# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        
        dummy = ListNode()
        dummy.next = head
        temp = head
        while temp and temp.next:
            runner = temp.next
            while runner and runner.val == temp.val:
                runner = runner.next
                temp.next = temp.next.next
            temp = temp.next
        return dummy.next