# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        values = []
        runner = head
        while runner:
            values.append(runner.val)
            runner = runner.next
        stack = []
        length = len(values)
        answer = [0 for _ in range(length)]
        for index, value in enumerate(values):
            while stack and values[stack[-1]] < value:
                replacedIndex = stack.pop()
                answer[replacedIndex] = value
            stack.append(index)
        return answer
