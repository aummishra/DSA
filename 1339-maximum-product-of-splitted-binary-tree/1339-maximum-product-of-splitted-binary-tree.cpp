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
    long long sum = 0;
    long long ans = -1;
    long long mod = 1e9 +7;
    void help(TreeNode* root){
        if(root==nullptr) return;
        help(root->left);
        sum += root->val;
        help(root->right);
    }
   long long calc(TreeNode* root,long long t){
        if(root==nullptr) return 0;
       long long left = calc(root->left,t);
       long long right = calc(root->right,t);
           ans = max(ans,left * abs(sum-left));
           ans = max(ans,right* abs(sum-right));
       return (left + right + root->val);
        
    }
    int maxProduct(TreeNode* root) {
        help(root);
        long long t = sum/2;
        long long x = calc(root,t);
        return ans%mod;
        
    }
};