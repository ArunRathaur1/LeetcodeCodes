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
        Node* newhead=new Node(head->val);
        Node* i=head;
        Node* j=newhead;
        map<Node*,Node*>m;
        i=i->next;
        while(i!=NULL){
            Node* tem=new Node(i->val);
            i=i->next;
            j->next=tem;
            j=tem;
        }
        j=newhead;
        i=head;
        while(j!=NULL){
            m[i]=j;
            i=i->next;
            j=j->next;
        }
        j=newhead;
        i=head;
        while(j!=NULL){
            j->random=m[i->random];
            j=j->next;
            i=i->next;
        }
        return newhead;
    }
};