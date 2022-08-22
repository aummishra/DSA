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
    void connect(TreeNode* root, vector<vector<int>> &adj){
        if(root==nullptr) return;
        if(root->left !=nullptr){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            
        }
        if(root->right !=nullptr){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        connect(root->left,adj);
        connect(root->right,adj);
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adj(1e5+1);
        connect(root,adj);
        vector<int> vis(1e5+1,0);
       // vector<int> dist(1e5+1,-1);
        int ans  = 0;
     //BFS starts with start
        queue<pair<int,int>> q;
        vis[start] = 1;
       // dist[start] = 0;
        q.push({start,0});
        while(!q.empty()){
           pair<int,int> node = q.front();
            q.pop();
            for(auto &it: adj[node.first]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node.second + 1});
                    ans = max(ans,node.second+1);
                }
            }
            
        }
        return ans;
    }
};