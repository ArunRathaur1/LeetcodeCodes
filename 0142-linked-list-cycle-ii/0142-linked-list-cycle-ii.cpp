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
        ListNode* tem=new ListNode(-1);
        if(head==NULL||head->next==NULL)return NULL;
        ListNode* tem1=head;
        ListNode* tem2=head;
        int flag=0;
        while(tem1!=NULL&& tem2!=NULL&& tem2->next!=NULL){
            tem1=tem1->next;
            tem2=tem2->next->next;
            if(tem1==tem2)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)return NULL;
        tem1=head;
         while(tem1!=NULL&& tem2!=NULL&& tem2->next!=NULL){
           
            if(tem1==tem2){
                return tem1;
            }
             tem1=tem1->next;
            tem2=tem2->next;
         }
         return NULL;
    }
};