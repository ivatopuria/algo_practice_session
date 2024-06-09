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
    map <int, vector< TreeNode* > > level;
    void dfs(TreeNode* root, int current_level){
        if(root == nullptr) return;
        if(current_level % 2){
            level[current_level].push_back(root);
        }
        dfs(root->left, current_level + 1);
        dfs(root->right, current_level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root, 0);
        for(auto [key, nodes] : level){
            int n = nodes.size();
            for(int i = 0; i < n / 2; i++){
                swap(nodes[i]->val, nodes[n - 1 - i]->val);
            }
        }
        return root;
    }
};