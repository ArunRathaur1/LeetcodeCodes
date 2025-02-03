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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* l3=new ListNode();
        ListNode* l4=l3;
        while(l1!=NULL&& l2!=NULL){
            if(l1->val<=l2->val){
                l3->next=l1;
                l1=l1->next;
                l3=l3->next;
            }
            else{
                l3->next=l2;
                l2=l2->next;
                l3=l3->next;
            }
        }
        while(l1!=NULL){
            l3->next=l1;
            l1=l1->next;
            l3=l3->next;
        }
        while(l2!=NULL){
            l3->next=l2;
            l2=l2->next;
            l3=l3->next;
        }
        return l4->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL|| head->next==NULL)return head;
        ListNode* mid=head;
        ListNode*prev=NULL;
        ListNode* end=head;
        while(end!=NULL&& end->next!=NULL){
            prev=mid;
            mid=mid->next;
            end=end->next->next;
        }
        ListNode*head2=prev->next;
        prev->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(head2);
        ListNode* m=merge(l1,l2);
        return m;
    }
};