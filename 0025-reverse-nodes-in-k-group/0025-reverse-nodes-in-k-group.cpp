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
    private:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* tem=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tem;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* tem=head;
      int count=0;
      int flag=0;
      ListNode* newhead=head;
      ListNode* prev=NULL;
      while(tem!=NULL){
        count++;
        if(count==k){
            ListNode* x=tem->next;
            tem->next=NULL;
            ListNode* r1=reverse(head);
            if(flag==0){
                newhead=r1;
                flag=1;
            }
            head->next=x;
            if(prev!=NULL){
                prev->next=r1;
            }
            prev=head;
            head=x;
            tem=x;
            count=1; 
        }
        if(tem)
        tem=tem->next;
      }
      return newhead;  
    }
};