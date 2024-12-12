class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        priority_queue<int,vector<int>>q;
       int size=g.size();
       for(auto i: g)q.push(i);
       for(int i=0;i<k;i++){
        int p=q.top();
        q.pop();
        q.push(sqrt(p));
       }
       long long tem=0;
       while(!q.empty()){
        tem=tem+q.top();
        q.pop();
       }
       return tem;
    }
};
        