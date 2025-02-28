class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,char>>>adj(n);
        for(int i=0;i<redEdges.size();i++){
            adj[redEdges[i][0]].push_back({redEdges[i][1],'r'});
        }
        for(int i=0;i<blueEdges.size();i++){
            adj[blueEdges[i][0]].push_back({blueEdges[i][1],'b'});
        }
        vector<int>red_distance(n,INT_MAX);
        vector<int>blue_distance(n,INT_MAX);
        queue<pair<int,char>>q;
        q.push({0,'r'});
        q.push({0,'b'});
        red_distance[0]=0;
        blue_distance[0]=0;
        while(!q.empty()){
            pair<int,char>p=q.front();
            q.pop();
            int node=p.first;
            int color=p.second;
            int distance=color=='r'?red_distance[node]:blue_distance[node];
            for(auto i: adj[node]){
                if(i.second!=color){
                    if(i.second=='r'&&red_distance[i.first]>distance+1){
                        red_distance[i.first]=distance+1;
                        q.push({i.first,i.second});
                    }
                    else if(i.second=='b'&&blue_distance[i.first]>distance+1){
                        blue_distance[i.first]=distance+1;
                        q.push({i.first,i.second});
                    }
                }
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int p=min(red_distance[i],blue_distance[i]);
            if(p==INT_MAX)
                p=-1;
            ans[i]=p;
        }
        return ans;
    }
};