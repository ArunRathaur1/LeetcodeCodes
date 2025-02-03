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
        ListNode* tem=head;
        int count=0;
        while(tem!=NULL&& count<n){
            count++;
            tem=tem->next;
        }
        ListNode* tem2=head;
        ListNode* prev=NULL;
        while(tem!=NULL){
            prev=tem2;
            tem2=tem2->next;
            tem=tem->next;
        }
        if(prev==NULL){
            return head->next;
        }
        prev->next=prev->next->next;
        return head;
    }
};