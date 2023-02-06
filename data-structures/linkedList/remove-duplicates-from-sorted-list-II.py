# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        if not head.next:
            return head
        dummy = ListNode()
        dummy.next = head

        runner = dummy

        while runner.next and runner.next.next:
            if runner.next.val == runner.next.next.val:
                duplicate = runner.next.val
                while runner.next and runner.next.val == duplicate:
                    runner.next = runner.next.next
            else:
                runner = runner.next
        return dummy.next