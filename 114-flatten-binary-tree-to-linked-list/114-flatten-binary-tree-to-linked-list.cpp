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
    void preorder(vector<TreeNode*> &v,TreeNode* root){
        if(root == nullptr) return;
        v.push_back(root);
        preorder(v,root->left);
        preorder(v,root->right);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> v;
        preorder(v,root);
        int n = v.size()-1;
        for(int i=0;i<n;i++){
            v[i]->right = v[i+1];
            v[i]->left = nullptr;
        }
    }
};