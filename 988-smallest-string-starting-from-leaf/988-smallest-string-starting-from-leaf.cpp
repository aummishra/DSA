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
    void help(TreeNode* root,set<string> &st, string temp){
        if(root==nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            temp += 'a' + root->val;
            reverse(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        temp += 'a' + root->val;
         help(root->left,st,temp);
         help(root->right,st,temp);
    }
    string smallestFromLeaf(TreeNode* root) {
        set<string> st;
        string s = "";
        help(root,st,s);
        for(auto it:st){
            return it;
        }
        return s;
    }
};