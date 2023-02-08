# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        runner = head
        while runner:
            placer = dummy

            while placer.next and placer.next.val <= runner.val:
                placer = placer.next

            nextRunner = runner.next
            runner.next = placer.next
            placer.next = runner

            runner = nextRunner
        
        return dummy.next