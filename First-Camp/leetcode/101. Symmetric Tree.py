# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self, rightNode, leftNode):
        if not rightNode and not leftNode:
            return True
        if (not rightNode and leftNode) or (rightNode and not leftNode):
            return False
        
        if rightNode.val != leftNode.val: return False

        return self.traversal(rightNode.right, leftNode.left) and self.traversal(rightNode.left, leftNode.right)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root: return True
        return self.traversal(root.right, root.left)