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
    //s -> 1,2,2
    //g -> 4,3,5
    ListNode* partition(ListNode* head, int x) {
        vector<int> s;
        vector<int> g;
        ListNode* temp = head;
        while(temp!=nullptr){
            if(temp->val < x) s.push_back(temp->val);
            else g.push_back(temp->val);
            temp = temp->next;
        }
        ListNode* ans = new ListNode();
        ListNode* res = ans;
        int i = 0;
        while(i<s.size()){
            ListNode* temp1 = new ListNode(s[i]);
            ans->next = temp1;
            ans = ans->next;
            i++;
        }
        int j=0;
        while(j<g.size()){
            ListNode* temp1 = new ListNode(g[j]);
            ans->next = temp1;
            ans = ans->next;
            j++;
        }
        return res->next;
    }
};