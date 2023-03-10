# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        if not node:
            return

        temp = node
        slow = ListNode()
        slow.next = temp
        while temp.next:
            temp.val = temp.next.val
            temp = temp.next
            slow = slow.next
        slow.next = None
        