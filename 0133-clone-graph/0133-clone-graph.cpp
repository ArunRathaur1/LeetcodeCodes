/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)return node;
        map<Node*,Node*>m;
        queue<Node*>q;
        q.push(node);
        Node* n=new Node(node->val);
        m[node]=n;
        while(!q.empty()){
            Node* tem=q.front();
            q.pop();
            for(auto neighbour: tem->neighbors){
                if(m.find(neighbour)==m.end()){
                    Node* newnode=new Node(neighbour->val);
                    m[neighbour]=newnode;
                    q.push(neighbour);
                }
                m[tem]->neighbors.push_back(m[neighbour]);
            }
        }
        return m[node];
    }
};