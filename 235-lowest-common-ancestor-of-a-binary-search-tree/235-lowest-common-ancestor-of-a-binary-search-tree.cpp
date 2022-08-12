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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return root;
        if(root->val >= p->val && root->val <= q->val) return root;
        root->left = solve(root->left,p,q);
        root->right = solve(root->right,p,q);
        if(solve(root->left,p,q)) return root->left;
        return root->right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(q->val < p->val){
            return solve(root,q,p);
        }
        return solve(root,p,q);
    }
};