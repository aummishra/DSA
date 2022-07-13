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
     vector<vector<int>> ans;
    void level(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
          vector<int> temp;
            int n = q.size();
            for(int i=1;i<=n;i++){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left !=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }

                temp.push_back(curr->val);
            }
           ans.push_back(temp); 
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr){
            return ans;
        }
    level(root);
        return ans;
    }
};