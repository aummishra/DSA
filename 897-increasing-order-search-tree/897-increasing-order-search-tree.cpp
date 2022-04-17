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
    TreeNode* solve(TreeNode* root,TreeNode* cur){
        if(root==nullptr) return cur;
        cur = solve(root->left,cur);
        cur->right = root;
        root->left = nullptr;
        cur = root;
        return solve(root->right,cur);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dum = new TreeNode(0);
        TreeNode* cur = dum;
        solve(root,cur);
        return dum->right;
    }
};