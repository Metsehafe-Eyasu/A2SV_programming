# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        indices = defaultdict(lambda: defaultdict(list))
        def traversal(root, col, row):
            if not root:
                return
            indices[col][row].append(root.val)

            traversal(root.left, col - 1, row + 1)
            traversal(root.right, col + 1, row + 1)
        
        traversal(root, 0, 0)
        answer = []
        for i in sorted(indices):
            column = []
            for j in sorted(indices[i]):
                column.extend(list(sorted(indices[i][j])))
            answer.append(column)
        return answer