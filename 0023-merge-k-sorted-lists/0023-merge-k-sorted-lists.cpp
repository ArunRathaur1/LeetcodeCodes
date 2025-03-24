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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       ListNode* ans=new ListNode();
       ListNode* forward=ans;
       int l=lists.size();
       priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> q;
       for(int i=0;i<l;i++){
            if(lists[i]!=NULL){
                q.push({lists[i]->val,lists[i]});
            }
       }
       while(!q.empty()){
        pair<int,ListNode*>x=q.top();
        q.pop();
        ListNode* node=x.second;
        forward->next=node;
        forward=node;
        if(node->next!=NULL){
            node=node->next;
            q.push({node->val,node});
        }
       }
       return ans->next;
    }
};