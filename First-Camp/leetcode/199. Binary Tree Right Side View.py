# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        queue = deque()
        ans = []
        if not root:
            return ans
        queue.append(root)
        while queue:
            level = []
            length = len(queue)
            while length:
                curr = queue.popleft()
                level.append(curr.val)

                if curr.left:queue.append(curr.left)
                if curr.right:queue.append(curr.right)
                length -= 1
            ans.append(level[-1])
        return ans