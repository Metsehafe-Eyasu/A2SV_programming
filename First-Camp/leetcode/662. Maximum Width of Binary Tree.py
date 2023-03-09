# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        queue = deque()
        ans = -200

        queue.append((root, 0))
        while queue:
            length = len(queue)
            right = queue[0][1]
            left = queue[-1][1]
            ans = max(ans, left - right + 1)
            i = 0
            while length:
                curr = queue.popleft()
                index = curr[1] - right
                if curr[0].left:
                    queue.append((curr[0].left, 2*index + 1) )
                if curr[0].right:
                    queue.append((curr[0].right, 2*index + 2))
                length -= 1
        return ans      