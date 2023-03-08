# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inOrder(self, root):
        if not root:
            return


        self.inOrder(root.left)

        if self.k > 0:
            self.val = root.val
            self.k -= 1

        self.inOrder(root.right)


    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.k = k
        self.val = -1
        self.inOrder(root)
        return self.val