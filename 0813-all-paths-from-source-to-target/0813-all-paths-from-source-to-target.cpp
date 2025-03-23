class Solution {
public:
    void findpaths(vector<vector<int>>&graph,vector<int>&path,int node,vector<vector<int>>&ans,int target){
        if(node==target){
            ans.push_back(path);
        }
        for(auto i: graph[node]){
            path.push_back(i);
            findpaths(graph,path,i,ans,target);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<vector<int>>ans;
       vector<int>path;
       int target=graph.size()-1;
       path.push_back(0);
       findpaths(graph,path,0,ans,target);
       return ans;
    }
};