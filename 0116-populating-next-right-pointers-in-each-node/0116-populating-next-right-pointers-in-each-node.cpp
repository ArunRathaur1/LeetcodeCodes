/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return NULL;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* tem=q.front();
            q.pop();
            if(tem==NULL){
                if(!q.empty())q.push(NULL);
            }
            else{
                Node* prev=tem;
                if(prev->left)q.push(prev->left);
                if(prev->right)q.push(prev->right);
                while(q.front()!=NULL){
                    Node* newnode=q.front();
                    q.pop();
                    if(newnode->left)q.push(newnode->left);
                    if(newnode->right)q.push(newnode->right);
                    prev->next=newnode;
                    prev=newnode;
                }
                prev->next=NULL;
            }

        }
        return root;
    }
};