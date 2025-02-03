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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* tem=head;
        ListNode* tem2=head;
        ListNode* prev=NULL;
        while(tem!=NULL&& tem->next!=NULL){
            tem=tem->next->next;
            prev=tem2;
            tem2=tem2->next;
        }
        if(prev==NULL)return NULL;
        prev->next=prev->next->next;
        return head;
    }
};