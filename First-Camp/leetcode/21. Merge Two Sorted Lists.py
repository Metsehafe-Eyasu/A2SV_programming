# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge(self, head: Optional[ListNode], list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1 or not list2:
            if not list1 and list2:
                head.next = list2
            if list1 and not list2:
                head.next = list1
            if not list1 and not list2:
                head.next = None
        else:
            if list1.val <= list2.val:
                head.next = list1
                self.merge(head.next, list1.next, list2)
            else:
                head.next = list2
                self.merge(head.next, list1, list2.next)
        return head

    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        self.merge(dummy, list1, list2)
        return dummy.next