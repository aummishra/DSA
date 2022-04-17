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
    void inorder(TreeNode* root,vector<int> &v){
        if(root==nullptr){
          return;  
        } 
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* build(vector<int> &v){
        if(v.size()==0) return nullptr;
        TreeNode* root = new TreeNode(v[0]);
        TreeNode* temp = root;
        for(int i=1;i<v.size();i++){
            TreeNode* x = new TreeNode(v[i]);
            temp->right = x;
            temp = x;
        }
        return root;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return build(v);
    }
};