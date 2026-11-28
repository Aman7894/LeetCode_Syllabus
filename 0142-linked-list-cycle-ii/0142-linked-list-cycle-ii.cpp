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
    ListNode *detectCycle(ListNode *head) {
        ListNode* s=head;
        ListNode* f=head;
        bool istrue =false;
        while(f!=NULL&&f->next!=NULL){
            s=s->next;
            f=f->next->next;
            if(s==f){
                istrue= true;
                break;
            }
        }
        if(istrue){
            
            f=head;
            while(f!=s){
                s=s->next;
                f=f->next;
            }
            return s;
        }
        
        return NULL;
    }
};