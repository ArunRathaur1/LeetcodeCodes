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
        Node* n=new Node(node->val);
        queue<Node*>q;
        q.push(node);
        map<Node*,Node*>visited;
        visited[node]=n;
        while(!q.empty()){
            Node* x=q.front();
            q.pop();
            for(auto node:x->neighbors){
                if(visited.find(node)==visited.end()){
                    Node* p=new Node(node->val);
                    visited[node]=p;
                    q.push(node);
                }
                visited[x]->neighbors.push_back(visited[node]);
            }

        }
        return visited[node];
    }
};