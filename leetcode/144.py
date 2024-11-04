# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def iterate(self, root: Optional[TreeNode], order) -> List[int]:
        if not root:
            return []
        else:
            order.append(root.val)

        self.iterate(root.left, order)
        self.iterate(root.right, order)

        return order
        


    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        order = self.iterate(root, [])

        return order


