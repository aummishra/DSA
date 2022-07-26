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
    void help(TreeNode* root,vector<string> &ans,string temp){
        //string temp = "";
        if(root==nullptr) return;
        if(root->left==nullptr && root->right == nullptr){
            temp = temp + to_string(root->val);
            ans.push_back(temp);
            return;
        }
        temp = temp + to_string(root->val) + "->";
        help(root->left,ans,temp);
        help(root->right,ans,temp);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";
        help(root,ans,s);
        return ans;
    }
};