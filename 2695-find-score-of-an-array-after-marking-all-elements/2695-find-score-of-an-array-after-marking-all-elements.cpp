class Solution {
public:
    long long findScore(vector<int>& nums) {
        int l=nums.size();
        vector<bool>visited(l,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
        for(int i=0;i<l;i++){
            q.push({nums[i],i});
        }
        long long score=0;
        while(!q.empty()){
            auto[value,index]=q.top();
            q.pop();
            if(visited[index]==false){
                score=score+value;
                visited[index]=true;
                if(index+1<l){
                    visited[index+1]=true;
                }
                if(index-1>=0){
                    visited[index-1]=true;
                }
            }
        }
        return score;
    }
};