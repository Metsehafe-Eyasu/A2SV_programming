# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        self.average = 0
        def traversal(root):
            if not root: 
                return (0, 0)
            
            left = traversal(root.left)
            right = traversal(root.right)

            currsum = left[0] + right[0] + root.val
            count = left[1] + right[1] + 1

            if currsum // count == root.val: 
                self.average += 1

            return (currsum, count)
        traversal(root)
        return self.average