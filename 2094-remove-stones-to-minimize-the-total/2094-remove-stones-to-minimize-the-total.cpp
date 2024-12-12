class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int,vector<int>>q;
        for(auto p:piles)q.push(p);
        for(int i=0;i<k;i++){
            int tem=q.top();
            q.pop();
            q.push(tem%2==0?tem/2:tem/2+1);
        }
        int total=0;
        while(!q.empty()){
            total=total+q.top();
            q.pop();
        }
        return total;
    }
};