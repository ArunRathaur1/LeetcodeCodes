class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
       queue<int>q;
       map<int,int>ar;
       vector<int>visited(graph.size(),-1);
       ar[0]=-1;
       int index=0;
       for(int i=0;i<graph.size();i++){
         if(visited[i]==-1){
            q.push(i);
            while(!q.empty()){
            int tem=q.front();
            q.pop();
            for(auto node:graph[tem]){
                if(visited[node]==-1){
                     q.push(node);
                    ar[node]=ar[tem]==-1?-2:-1;
                    visited[node]=1;
                    index++;
                }
                else if(ar[node]==ar[tem]){
                   return false; 
                }
              
            }
        }
             
       }
       }
       return true;
    }
};