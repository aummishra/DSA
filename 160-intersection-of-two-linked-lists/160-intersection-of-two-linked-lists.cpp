/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        if(head==nullptr){
            return 0;
        }
        int count=1;
        while(head->next!=nullptr){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        int d = abs(l1-l2);
        if(l1>l2){
            for(int i=0;i<d;i++){
                headA = headA->next;
            }
        }
        else{
            for(int i=0;i<d;i++){
                headB = headB->next;
            }
        }
        while(headA !=nullptr && headB!=nullptr){
            if(headA==headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
    return nullptr;
    }
};