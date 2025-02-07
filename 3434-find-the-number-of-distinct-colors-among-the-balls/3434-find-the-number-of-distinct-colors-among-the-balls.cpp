class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        map<int,int>freq;
        map<int,int>ball;
        vector<int>ans;
        int l=q.size();
        for(int i=0;i<l;i++){
            int b=q[i][0];
            int c=q[i][1];
            if(ball.find(b)!=ball.end()){
                int current=ball[b];
                freq[current]--;
                if(freq[current]==0){
                    freq.erase(current);
                }
            }
            ball[b]=c;
            freq[c]++;
            ans.push_back(freq.size());
        }
        return ans;
    }
};