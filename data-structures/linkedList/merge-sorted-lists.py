# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        ptr1 = list1
        ptr2 = list2
        placer = dummy
        while ptr1 and ptr2:
            if ptr1.val < ptr2.val:
                placer.next = ptr1
                ptr1 = ptr1.next
            else:
                placer.next = ptr2
                ptr2 = ptr2.next
            placer = placer.next
            
        if not ptr2 and ptr1:
            placer.next = ptr1
        if not ptr1 and ptr2:
            placer.next = ptr2
        return dummy.next