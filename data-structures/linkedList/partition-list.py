# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        lessPart = lessPtr = ListNode()
        morePart = morePtr = ListNode()

        runner = head
        while runner:
            if runner.val < x:
                lessPtr.next = runner
                lessPtr = lessPtr.next
            else:
                morePtr.next = runner
                morePtr = morePtr.next

            runner = runner.next
        morePtr.next = None
        lessPtr.next = morePart.next

        return lessPart.next

        