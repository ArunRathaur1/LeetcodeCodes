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
    ListNode* reverse(ListNode*head){
    if(head==NULL|| head->next==NULL){
        return  head;
    }
    ListNode* curr=head;
    ListNode* forward=head;
    ListNode* previous=NULL;
    while (curr!=NULL)
    {
        forward=curr->next;
        curr->next=previous;
        previous=curr;
        curr=forward;
    }
    return previous;
    
}
ListNode* add(ListNode* head1,ListNode* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    int carry=0;
    ListNode* previous=NULL;
    ListNode* h1=head1;
    while(head1!=NULL && head2!=NULL){
        head1->val=head1->val+head2->val+carry;
        if(head1->val>9){
            int tem=head1->val;
            head1->val=head1->val%10;
            carry=tem/10;
            previous=head1;
            head1=head1->next;
            head2=head2->next;
            continue;
        }
        previous=head1;
        head1=head1->next;
        head2=head2->next;
        carry=0;
    }
    while(head1!=NULL){
         head1->val=head1->val+carry;
          if(head1->val>9){
            int tem=head1->val;
            head1->val=tem%10;
            carry=tem/10;
            previous=head1;
            head1=head1->next;
            continue;
        }
        previous=head1;   
        head1=head1->next;
        carry=0;
    }
    if(carry!=0){
        ListNode* newnode=new ListNode(carry);
        previous->next=newnode;
    }
    return h1;
    
}
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
    // head1=reverse(head1);
    // head2=reverse(head2);
    ListNode*head3;
    ListNode* tem=head1;
    int l1=0,l2=0;
    while(tem!=NULL){
        l1++;
        tem=tem->next;
    }
    tem=head2;
    while(tem!=NULL){
        l2++;
        tem=tem->next;
    }
    if(l1>l2){
        head3=add(head1,head2);
    }
    else{
        head3=add(head2,head1);
    }
    return head3;
    }
};