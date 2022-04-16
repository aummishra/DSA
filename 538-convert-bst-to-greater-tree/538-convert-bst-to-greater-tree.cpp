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
long long sum = 0;
class Solution {
public:
    Solution(){
        sum = 0;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==nullptr) return root;
        root->right = convertBST(root->right);
        root->val = sum + root->val;
        sum = root->val;
        root->left = convertBST(root->left);
        return root;
    }
};