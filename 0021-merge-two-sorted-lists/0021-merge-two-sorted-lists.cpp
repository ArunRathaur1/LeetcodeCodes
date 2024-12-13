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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL&&list2==NULL)return NULL;
      ListNode* l1=list1;
      ListNode* l2=list2;
      ListNode* head=new ListNode();
      ListNode* temhead=head;
      while(l1!=NULL&& l2!=NULL){
        if(l1->val>l2->val){
            head->next=l2;
            head=head->next;
            l2=l2->next;
        }
        else{
            head->next=l1;
            head=head->next;
            l1=l1->next;
        }
      } 
      while(l1!=NULL){
        head->next=l1;
        head=head->next;
        l1=l1->next;
      } 
      while(l2!=NULL){
        head->next=l2;
        head=head->next;
        l2=l2->next;
      }
      return temhead->next;
    }
};