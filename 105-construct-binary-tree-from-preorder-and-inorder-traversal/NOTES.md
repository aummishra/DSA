class Solution {
public:
int idx =0;
int Search(vector<int>& inorder,int st, int en,int data){
for(int i=st;i<=en;i++){
if(inorder[i]==data){
return i;
}
}
return -1;
}
TreeNode* ft(vector<int>& preorder, vector<int>& inorder,int st,int en){
if(st>en){
return nullptr;
}
//static int idx =0;
int data = preorder[idx];
TreeNode* root = new TreeNode(data);
idx++;
if(st==en){
return root;
}
int pos = Search(inorder,st,en,data);
root->left  = ft(preorder,inorder,st,pos-1);
root->right = ft(preorder,inorder,pos+1,en);
return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
int n = preorder.size()-1;
idx = 0;
return ft(preorder,inorder,0,n);
}
};