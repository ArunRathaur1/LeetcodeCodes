class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int nodes=adj.size();
        vector<int>indegree(nodes,0);
        for(int i=0;i<nodes;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<nodes;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(int i:adj[t]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>p=topologicalSort(adj);
        reverse(p.begin(),p.end());
        vector<int>q;
        return (p.size()==numCourses)?p:q;
    }
};