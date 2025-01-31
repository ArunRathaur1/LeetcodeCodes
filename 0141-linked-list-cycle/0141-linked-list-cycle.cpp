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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)return false;
        ListNode* tem1=head;
        ListNode* tem2=head;
        while(tem1!=NULL&& tem2!=NULL&& tem2->next!=NULL){
            tem1=tem1->next;
            tem2=tem2->next->next;
            if(tem1==tem2)return true;
        }
        return false;
    }
};