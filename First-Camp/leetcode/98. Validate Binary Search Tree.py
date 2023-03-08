# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def preOrder(root, minVal, maxVal):
            if not root: return True
            if root.val >= maxVal or root.val <= minVal: return False

            left = preOrder(root.left, minVal, root.val)
            right = preOrder(root.right, root.val, maxVal)
            return left and right
        return preOrder(root, float('-inf'), float('inf'))