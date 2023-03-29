# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        mp = dict()
        def rec(root):
            if root == None:
                return
            if root.val not in mp:
                mp[root.val] = 1
            else:
                mp[root.val] = mp[root.val] + 1
            if root.left:
                rec(root.left)
            if root.right:
                rec(root.right)
        rec(root)
        
        ma = 0
        for [x, y] in mp.items():
            # print(x, y)
            if y > ma:
                ma = y

        ans = []
        for [x, y] in mp.items():
            if y == ma:
                ans.append(x)
        return ans