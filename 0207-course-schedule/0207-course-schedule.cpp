class Solution {
public:
    bool canFinish(int course, vector<vector<int>>& nums) {
        vector<vector<int>>adj(course);
        vector<int>indegree(course);
        for(auto i: nums){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int>q;
        for(int i=0;i<course;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int t=q.front();
            count++;
            q.pop();
            for(auto i:adj[t]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(count==course)return true;
        return false;
    }
};