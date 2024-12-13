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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode*tem=new ListNode(-1);
        tem->next=head;
        ListNode* prev=tem;
        ListNode* curr=head;
        ListNode* currnext=head->next;
        while(currnext!=NULL){
            if(curr->val==currnext->val){
                 while(curr->val==currnext->val){
                    currnext=currnext->next;
                    if(currnext==NULL)break;
                }
                if(currnext==NULL){
                    prev->next=NULL;
                    break;
                }
                curr=currnext;
                prev->next=curr;
                currnext=currnext->next;
                continue;
            }
            prev=curr;
            curr=currnext;
            currnext=currnext->next;
        }
        if(tem->next!=NULL)
        return tem->next;
        return NULL;
    }
};