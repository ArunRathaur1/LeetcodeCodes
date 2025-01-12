/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
      Node* i=head;
      while(i!=NULL){
        Node* tem=new Node(i->val);
        tem->next=i->next;
        i->next=tem;
        i=i->next->next;
        } 
        i=head;
        while(i!=NULL){
            Node* tem=i->next;
            tem->random=i->random?i->random->next:NULL;
            i=i->next->next;
        }
        i=head;
        Node* copyhead=i->next;
        Node* temhead=copyhead;
        while(i!=NULL){
            i->next=i->next->next;
            if(temhead->next){
                temhead->next=temhead->next->next;
            }
            i=i->next;
            temhead=temhead->next;
        }
        return copyhead;
    }
};