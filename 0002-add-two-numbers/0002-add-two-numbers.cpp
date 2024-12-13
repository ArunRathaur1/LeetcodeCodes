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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum=new ListNode();
        ListNode* tem=sum;
        int carry=0;
        while(l1!=NULL&& l2!=NULL){
            int x=l1->val+l2->val+carry;
            int data=x%10;
            carry=x/10;
            ListNode* node=new ListNode(data);
            sum->next=node;
            sum=sum->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int x=l1->val+carry;
            int data=x%10;
            carry=x/10;
            ListNode* node=new ListNode(data);
            sum->next=node;
            sum=sum->next;
            l1=l1->next;
        }
        while(l2!=NULL){
             int x=l2->val+carry;
            int data=x%10;
            carry=x/10;
            ListNode* node=new ListNode(data);
            sum->next=node;
            sum=sum->next;
            l2=l2->next;
        }
        if(carry!=0){
            ListNode* node=new ListNode(carry);
            sum->next=node;
        }
        return tem->next;
    }
};