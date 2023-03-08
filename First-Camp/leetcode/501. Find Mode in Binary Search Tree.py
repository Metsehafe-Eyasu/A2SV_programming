# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        arr = defaultdict(int)

        def traversal(root):
            if not root: return
            arr[root.val] += 1
            traversal(root.left)
            traversal(root.right)

        traversal(root)
        ans = [(k, v) for k, v in sorted(arr.items(), key=lambda item: item[1])]
        return [key for (key, val) in ans if val == ans[-1][1]]