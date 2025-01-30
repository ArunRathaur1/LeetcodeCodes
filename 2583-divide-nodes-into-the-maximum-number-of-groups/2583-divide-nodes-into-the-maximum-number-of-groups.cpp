class DSU{
    public:
    vector<int>parent,rank;
    DSU(int nodes){
        parent.resize(nodes);
        rank.resize(nodes);
        for(int i=0;i<nodes;i++ ){
            parent[i]=i;
            rank[i]=0;
        }
    }
    vector<int> componets(){
        set<int>st;
        for(auto i: parent){
            st.insert(i);
        }
        vector<int>ar(st.begin(),st.end());
        return ar;
    }
    int findparent(int x){
        if(parent[x]==x)return x;
        return parent[x]=findparent(parent[x]);
    }
    void joinedge(int x,int y){
        int x1=findparent(x);
        int y1=findparent(y);
        if(rank[x1]>rank[y1]){
            parent[y1]=x1;
        }
        else if(rank[x1]<rank[y1]){
            parent[x1]=y1;
        }
        else{
            parent[x1]=y1;
            rank[y1]++;
        }
    }
};
class Solution {
public:
    bool dfs(vector<int>&colors,int colorvalue,int node,vector<vector<int>>&adj){
        colorvalue=1-colorvalue;
        colors[node]=colorvalue;
        for(auto i: adj[node]){
            if(colors[i]==-1){
                bool x=dfs(colors,colorvalue,i,adj);
                if(x==false)return false;
            }
            else if(colors[node]==colors[i])return false;
        }
        return true;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        DSU ob(n+1);
        for(auto i: edges){
            ob.joinedge(i[0],i[1]);
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>colors(n+1,-1);
        int colorvalue=0;
        for(int i=1;i<=n;i++){
            if(colors[i]==-1){
                bool x=dfs(colors,colorvalue,i,adj);
                if(x==false)return -1;
            }
        } 
        vector<int>componets=ob.componets();
        unordered_map<int,int>m;
        for(auto i: componets){
            m[i]=0;
        }
        for(int i=1;i<=n;i++){
            vector<bool>visited(n+1,false);
            queue<int>q;
            q.push(i);
            q.push(-1);
            int count=0;
            while(!q.empty()){
                int t=q.front();
                q.pop();
                if(t==-1){
                    count++;
                    if(!q.empty())q.push(-1);
                }
                else{
                    visited[t]=true;
                    for(auto j: adj[t]){
                        if(visited[j]==false){
                            visited[j]=true;
                            q.push(j);
                        }
                    }
                }
            }
            int x=ob.findparent(i);
            m[x]=max(m[x],count);
        }
        int total=0;
        for(auto i: m){
            total+=i.second;
        }
        return total;
    }
};