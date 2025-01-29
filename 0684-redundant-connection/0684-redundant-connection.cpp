class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    int nodes;
    DSU(int nodes){
        this->nodes=nodes+1;
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
        else if(rank[ux]<rank[uy]){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodes=edges.size();
        DSU ob(nodes);
        for(int i=0;i<nodes;i++){
            int parent1=ob.findparent(edges[i][0]);
            int parent2=ob.findparent(edges[i][1]);
            if(parent1!=parent2){
                ob.joinedge(edges[i][0],edges[i][1]);
            }
            else{
                return {edges[i][0],edges[i][1]};
            }
        }
        return {-1,-1};
    }
};