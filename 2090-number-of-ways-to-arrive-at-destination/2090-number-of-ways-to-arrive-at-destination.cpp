class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        vector<vector<pair<int ,int>>>adj(n);
        int mod=1e9+7;
        int e=roads.size();
        for(int i=0;i<e;i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long>distance(n,LLONG_MAX);
        vector<int>ways(n,0);
        ways[0]=1;
        distance[0]=0;
        q.push({0,0});
        while(!q.empty()){
            pair<int,int> x=q.top();
            q.pop();
            int node=x.second;
            long long weight=x.first;
            if(distance[node]<weight)continue;
            for(auto ne: adj[node]){
                long long dis=1LL*distance[node]+1LL*ne.second;
                if(distance[ne.first]==dis){
                    ways[ne.first]=(1LL*ways[ne.first]+1LL*ways[node])%mod;
                }
                else if(distance[ne.first]>dis){
                    ways[ne.first]=ways[node];
                    distance[ne.first]=dis;
                    q.push({distance[ne.first],ne.first});
                }
            }
        }
        return ways[n-1];

    }
};