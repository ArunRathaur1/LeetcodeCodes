class Solution {
public:
    void dfs(int node,vector<vector<pair<int,int>>>&m,int &com_value,vector<int>&com,vector<int>&p){
        if(m[node].size()==0||com[node]!=-1)return ;
        com[node]=com_value;
        for(auto i: m[node]){
            p[com_value]=p[com_value]&i.second;
            dfs(i.first,m,com_value,com,p);
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int,int>>>m(n);
        int t=edges.size();
        for(int i=0;i<t;i++){
            m[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            m[edges[i][1]].push_back({edges[i][0],edges[i][2]});   
        }
        vector<int>com(n,-1);
        vector<int>p(n,INT_MAX);
        vector<int>ans;
        int com_value=1;
        for(int i=0;i<n;i++){
            if(com[i]==-1){
                dfs(i,m,com_value,com,p);
            }
            com_value++;
        }
        for(auto q: query){ 
            if(com[q[0]]==com[q[1]]&& com[q[0]]!=-1){
                ans.push_back(p[com[q[0]]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};