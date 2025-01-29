class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    DSU(int nodes){
        parent.resize(nodes+1);
        rank.resize(nodes+1);
        for(int i=1;i<=nodes;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int findparent(int x){
        if(parent[x]==x)return x;
        return parent[x]=findparent(parent[x]);
    }
    void joinedge(int x,int y){
        int ux=findparent(x);
        int uy=findparent(y);
        if(rank[ux]>rank[uy]){
            parent[uy]=ux;
        }
        else if(rank[uy]>rank[ux]){
            parent[ux]=uy;
        }
        else{
            parent[ux]=uy;
            rank[ux]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int node=edges.size();
        DSU ob(node);
        vector<int>parent(node+1,-1);
        vector<vector<int>>e;
        for(int i=0;i<node;i++){
            if(parent[edges[i][1]]!=-1){
                e.push_back({parent[edges[i][1]],edges[i][1]});
                e.push_back({edges[i][0],edges[i][1]});
                edges[i][1]=-1;
            }
            else{
                parent[edges[i][1]]=edges[i][0];
            }
        }
        int p=0;
        vector<int>cycleedgge;
        for(int i=0;i<node;i++){
            if(edges[i][1]==-1)continue;
            int x1=ob.findparent(edges[i][0]);
            int x2=ob.findparent(edges[i][1]);
            if(x1==x2){
              p=1;
              cycleedgge=edges[i];
            }
            else{
                ob.joinedge(edges[i][0],edges[i][1]);
            }
        }
        if(e.size()!=0){
            return (p==0)?e[1]:e[0];
        }
        return cycleedgge;
    }
};