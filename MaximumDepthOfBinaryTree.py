"""
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def maxDepth(self, root):
    """
    :type root: TreeNode
    :rtype: int
    """
    if root == None:
        return 0
    else:
        l_h = 1 + self.maxDepth(root.left)
        r_h = 1 + self.maxDepth(root.right)
        return max(l_h,r_h)
            