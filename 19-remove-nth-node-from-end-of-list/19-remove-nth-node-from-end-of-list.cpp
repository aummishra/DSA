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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       // vector<int> v;
        ListNode* temp = head;
        int size = 0;
        while(temp!=nullptr){ //O(n)
            //v.push_back(temp->val);
            size++;
            temp=temp->next;
        } 
        if(size == n) return head->next;
        ListNode* temp1 = head;
        int cnt = 1;
        while(cnt<=size-n && temp1!=nullptr){
            if(cnt == size-n){
                temp1->next = temp1->next->next;
            }
            temp1 = temp1->next;
            cnt++;
        }
        return head;
    }
};