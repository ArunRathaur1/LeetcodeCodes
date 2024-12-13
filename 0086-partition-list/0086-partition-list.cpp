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
    ListNode* partition(ListNode* head, int x) {
       ListNode* l1=new ListNode();
       ListNode* l4=l1;
       ListNode* l2=new ListNode();
       ListNode* l3=l2;
       ListNode* curr=head;
       while(curr!=NULL){
            if(curr->val>=x){
                l2->next=curr;
                l2=l2->next;
            }
            else{
                l1->next=curr;
                l1=l1->next;
            }
            curr=curr->next;
       }
       l1->next=NULL;
       l2->next=NULL;
    //    while(l4!=NULL){
    //         cout<<l4->val<<" ";
    //         l4=l4->next;
    //    } 
    //    cout<<endl;
    //     while(l3!=NULL){
    //         cout<<l3->val<<" ";
    //         l3=l3->next;
    //    } 
    //    cout<<endl;
       
       l1->next=l3->next;
       return l4->next;     
    }
};