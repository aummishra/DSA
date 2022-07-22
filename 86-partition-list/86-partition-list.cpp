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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return head;
        if(head->next==nullptr) return head;
        ListNode* first = new ListNode();
        ListNode* second = new ListNode();
        ListNode* c = second;
        ListNode* c1 = first;
        ListNode* temp = head;
        while(temp!=nullptr){
            if(temp->val < x){
                first->next = temp;
                first = first->next;
            }
            else{
                second->next = temp;
                second = second->next;
            }
            temp = temp->next; 
        }
        second->next = nullptr;// 1->1->0
        head = c1->next; // head->0
        first->next = c->next; //first->second
        if(head !=nullptr) return head;
        return first->next;
    }
};