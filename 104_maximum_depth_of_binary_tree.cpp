/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    int dfs(TreeNode* root){
        int result = 1;
        if(root->left != nullptr){
            result = max(result, dfs(root->left) + 1);
        }
        if(root->right != nullptr){
            result = max(result, dfs(root->right) + 1);
        }
        return result;
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return dfs(root);   
    }
};