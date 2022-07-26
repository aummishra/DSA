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
    void help(int target,vector<vector<int>> &ans, vector<int> temp,int cs,TreeNode* root){
         if(root==nullptr) return;
        if(root->left==nullptr && root->right == nullptr){
            temp.push_back(root->val);
            cs += root->val;
            if(cs==target)ans.push_back(temp);
            return;
        }
        cs += root->val;
        temp.push_back(root->val);
        help(target,ans,temp,cs,root->left);
        help(target,ans,temp,cs,root->right);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<vector<int>> ans;
        vector<int> s;
        int cs = 0;
        help(targetSum,ans,s,cs,root);
        return ans;
    }
};