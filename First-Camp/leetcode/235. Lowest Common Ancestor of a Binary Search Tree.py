# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        pPath = []
        qPath = []

        def search(root, val, arr):
            if not root: return
            arr.append(root)
            if val == root.val: return
            elif val > root.val:
                search(root.right, val, arr)
            else:
                search(root.left, val, arr)

        search(root, p.val, pPath)
        search(root, q.val, qPath)

        length = min(len(pPath), len(qPath))
        index = 0

        while pPath[index].val == qPath[index].val:
            index += 1
            if index == len(pPath) or index == len(qPath): break
            
        return pPath[index - 1]