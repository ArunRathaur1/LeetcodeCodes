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
    bool hasCycle(ListNode *head){
        if(!head||!head->next)return false;
        ListNode* tem2=head;
        ListNode* tem=head;
        while(tem2!=NULL && tem2!=NULL){
            tem=tem->next;
            if(!tem2||!tem2->next||!tem2->next->next)break;
            tem2=tem2->next->next;
            if(tem==tem2)
            return true;
        }
        return false;
    }
};