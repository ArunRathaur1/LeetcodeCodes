/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* newhead=head;
        while(head!=NULL){
            if(head->child!=NULL){
                Node* newnode=head->next;
                Node* i=head->child;
                Node* prev=NULL;
                while(i!=NULL){
                    prev=i;
                    i=i->next;
                }
                head->next=head->child;
                head->child->prev=head;
                prev->next=newnode;
                if(newnode!=NULL)
                    newnode->prev=prev;
                head->child=NULL;
            }
            head=head->next;
        }
        return newhead;
    }
};