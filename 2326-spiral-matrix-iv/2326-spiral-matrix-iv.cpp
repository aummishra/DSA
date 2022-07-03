/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        ListNode *temp = head;
        int x = 0;//x->m
        int y = 0;//y->l
        int row_end = m-1;
        int col_end = n-1;
        while(y<=col_end && x<=row_end&&temp!=nullptr){
            for(int i=y;i<=col_end;i++){
                if(temp==nullptr) break;
                ans[x][i] = temp->val;
                temp = temp->next;
            }
            x++;
            if(temp==nullptr) break;
            for(int i=x;i<=row_end;i++){
                if(temp==nullptr) break;
                ans[i][col_end] = temp->val;
                temp = temp->next;
            }
            col_end--;
            if(x>row_end || y>col_end || temp==nullptr) break;
            for(int i=col_end;i>=y;i--){
                if(temp==nullptr) break;
                ans[row_end][i] = temp->val;
                temp = temp->next;
            }
            row_end--;
            if(temp==nullptr) break;
            for(int i=row_end;i>=x;i--){
                if(temp==nullptr) break;
                ans[i][y] = temp->val;
                temp = temp->next;
            }
            y++;
            if(temp==nullptr) break;
        }
        return ans;
    }
};