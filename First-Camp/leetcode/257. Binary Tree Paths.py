# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        ans = []
        def preOrd(node,val):
            if not node.right and not node.left:
                ans.append(val + str(node.val))
                return
            
            if node.right:
                preOrd(node.right, val + str(node.val) + "->")
            if node.left:
                preOrd(node.left, val + str(node.val) + "->")
        preOrd(root, "")
        return ans