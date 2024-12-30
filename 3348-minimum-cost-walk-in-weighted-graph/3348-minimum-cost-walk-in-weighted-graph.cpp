class Solution {
public:
    void dfs(int node,map<int,vector<pair<int,int>>>&m,int &com_value,vector<int>&com,map<int,set<int>>&p){
        if(m[node].size()==0||com[node]!=-1)return ;
        com[node]=com_value;
        for(auto i: m[node]){
            p[com_value].insert(i.second);
            dfs(i.first,m,com_value,com,p);
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        map<int,vector<pair<int,int>>>m;
        int t=edges.size();
        for(int i=0;i<t;i++){
            m[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            m[edges[i][1]].push_back({edges[i][0],edges[i][2]});   
        }
        vector<int>com(n,-1);
        map<int,set<int>>p;
        int com_value=1;
        for(int i=0;i<n;i++){
            if(com[i]==-1){
                dfs(i,m,com_value,com,p);
            }
            com_value++;
        }
        vector<int>ans;
        for(auto q: query){ 
            if(com[q[0]]==com[q[1]]&& com[q[0]]!=-1){
                int tem=INT_MAX;
                for(auto i: p[com[q[0]]]){
                    tem=tem&i;
                }
                ans.push_back(tem);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};