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
    ListNode* Reverse(ListNode*& head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* tem=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tem;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)return true;
        ListNode* l1=head;
        ListNode* l2=head;
        while(l1!=NULL&&l2!=NULL&& l2->next!=NULL){
            l1=l1->next;
            l2=l2->next->next;
        }
        ListNode* r1=Reverse(l1);
        ListNode* r2=head;
        while(r1!=NULL){
            if(r1->val!=r2->val)return false;
            r1=r1->next;
            r2=r2->next;
        }
        return true;
    }
};