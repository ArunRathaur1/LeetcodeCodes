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
    void revser(ListNode*& head,ListNode*& currnode){
        if( currnode==NULL)return;
        ListNode* tem=currnode->next;
        currnode->next=head;
        head=currnode;
        currnode=tem;
        revser(head,currnode);
    }
    ListNode* reverseList(ListNode* head) {
      ListNode* prev=NULL;
      ListNode* curr=head;
      revser(prev,curr);
      return prev;
    }
};