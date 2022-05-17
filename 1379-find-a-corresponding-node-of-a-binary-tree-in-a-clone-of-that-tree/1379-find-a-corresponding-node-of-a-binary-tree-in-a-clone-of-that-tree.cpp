/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* t;
    void help(TreeNode* root,int x){
        if(root==nullptr){
            return;
        }
        if(root->val == x){
         t=root;
            return;
        }
        help(root->left,x);
        help(root->right,x);
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int x = target->val;
        t = nullptr;
        help(cloned,x);
        return t;
        
    }
};