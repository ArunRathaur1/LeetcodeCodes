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
        ListNode* t=new ListNode();
        t->next=head;
        ListNode* prev=NULL;
        ListNode* dummy=t;
        ListNode* curr=head;
        int index=1;
        while(curr!=NULL){
            curr=curr->next;
            if(index>=n){
                prev=dummy;
                dummy=dummy->next;
            }
            index++;
        }
        if(dummy==head){
            return head->next;
        }
        else{
            prev->next=dummy->next;
        }
        return t->next;

    }
};