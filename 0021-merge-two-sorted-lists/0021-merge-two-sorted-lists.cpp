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
    ListNode* mergeTwoLists(ListNode* t1, ListNode* t2) {
       if(t1==0||t2==0){
        return t1==0?t2:t1;
       }
       if(t1->val<=t2->val){
        t1->next=mergeTwoLists(t1->next,t2);
        return t1;
       }
       else{
     t2->next=mergeTwoLists(t1,t2->next);
        return t2;
       }
    }
};