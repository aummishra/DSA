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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        if(root==nullptr) return {0.00000};
        q.push(root);
        while(!q.empty()){
            double n = q.size();
            double temp=0.00000;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                temp+= node->val;
                //cout<<node->val;
                if(node->left !=nullptr) q.push(node->left);
                if(node->right !=nullptr) q.push(node->right);
            }
            //cout<<endl;
            temp = temp/n;
            ans.push_back(temp);
        }
        return ans;
    }
};