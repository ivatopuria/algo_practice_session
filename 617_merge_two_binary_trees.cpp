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
    TreeNode* dfs(TreeNode* root1, TreeNode* root2){
        TreeNode* new_root = new TreeNode();
        if(root1 == nullptr and root2 == nullptr){
            return new_root;
        }
        if(root1 == nullptr){
            new_root = root2;
            return new_root;
        }
        if(root2 == nullptr){
            new_root = root1;
            return new_root;
        }
        new_root->val = root1->val + root2->val;
        if(root1->left != nullptr or root2->left != nullptr){
            new_root->left = dfs(root1->left, root2->left);
        }
        if(root1->right != nullptr or root2->right != nullptr){
            new_root->right = dfs(root1->right, root2->right);
        }
        return new_root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr and root2 == nullptr){
            return root1;
        }
        return dfs(root1, root2);
    }
};