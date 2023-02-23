# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if (not head) or (not head.next) or (not head.next.next):
            return head
        odd = root = head
        even = temp = head.next
        
        while temp:
            root.next = temp.next
            if not root.next:
                break
            root = root.next
            temp.next = root.next
            temp = temp.next
        root.next = even
        return odd 
