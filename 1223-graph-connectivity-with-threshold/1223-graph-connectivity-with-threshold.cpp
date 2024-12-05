class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        map<int,vector<int>>adj;
        for (int i = 1; i <= n; i++) {
            for (int j = i * 2; j <= n; j += i) {
                if (gcd(i, j) > threshold) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);  // To make sure the graph is undirected
                }
            }
        }

       
        vector<int>con(n+1,-1);
        vector<bool>visited(n+1,false);
        int index=0;
        for(int i=1;i<=n;i++){
             if(visited[i]==false){
                queue<int>q;
                q.push(i);
                visited[i]=true;
                con[i]=index;
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    for(auto j: adj[t]){
                        if(visited[j]==false){
                            con[j]=index;
                            q.push(j);
                            visited[j]=true;
                        }
                    }
                }
            }
            index++;
        }

        int size=queries.size();
        vector<bool>output;
        for(int i=0;i<size;i++){
           if(con[queries[i][0]]==con[queries[i][1]]){
            output.push_back(true);
           } 
           else{
            output.push_back(false);
           }
        }
        return output;
    }
};