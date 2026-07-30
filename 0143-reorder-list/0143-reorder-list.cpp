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
    void reorderList(ListNode* head) {
        vector<int> arr;
        ListNode* t=head;
        while(t!=0){
            arr.push_back(t->val);
            t=t->next;
        }
        int l=arr.size();
        int m=arr.size()/2;
        vector<int> ans;
        for(int i=0;i<m;i++){
            ans.push_back(arr[i]);
            ans.push_back(arr[l-i-1]);
        }
        if(l%2) ans.push_back(arr[l/2]);
        t=head;
        int i=0;
        while(i<l&&t!=0){
            t->val=ans[i];
            t=t->next;
            i++;
        }
        

    }
};