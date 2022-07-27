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
    TreeNode* help(TreeNode* root){
        if(root==nullptr){
            return root;
        }
        TreeNode* temp = help(root->right);
        root->right  = help(root->left);
        TreeNode* temp1 = root;
        while(temp1->right!=nullptr){
            temp1 = temp1->right;
        }
        temp1->right = temp;
        root->left = nullptr;
        return root;
    }
    void flatten(TreeNode* root) {
       root = help(root);
    }
};