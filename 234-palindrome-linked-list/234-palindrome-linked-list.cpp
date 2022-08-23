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
    bool isPalindrome(ListNode* head) {
           map<int,int> mp;
        int key = 0;
        //int sum = 0;
       // int ans = INT_MIN;
        ListNode* temp = head;
        while(temp!=nullptr){
            mp[key] = temp->val;
            temp = temp->next;
            key++;
        }
        int n = key;
        for(int i=0;i<=(n/2)-1;i++){
            if(mp[i]!=mp[n-1-i]) 
            return false;
        }
        return true;
    }
};