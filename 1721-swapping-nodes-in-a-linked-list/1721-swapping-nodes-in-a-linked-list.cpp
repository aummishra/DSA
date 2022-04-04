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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        ListNode* temp = head;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp=temp->next;
        }
        swap(v[k-1],v[v.size()-k]);
       ListNode* temp1 = head;
        int cnt  = 0;
        while(temp1!=nullptr && cnt<v.size()){
            temp1->val = v[cnt];
            temp1=temp1->next;
            cnt++;
        }
        return head;
    }
};