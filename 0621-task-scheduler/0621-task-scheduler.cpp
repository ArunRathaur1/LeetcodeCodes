class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>q1;
        queue<pair<int,int>>q;
        vector<int>ar(26,0);
        for(int i=0;i<tasks.size();i++){
            ar[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(ar[i]!=0)q1.push(ar[i]);
        }
        int time=0;
        while(!q1.empty()||!q.empty()){
            time++;
            if(!q1.empty()){
                int t=q1.top();
                q1.pop();
                t--;
                if(t>0){
                    q.push({t,time+n});
                }
            }
            if(!q.empty()&& q.front().second==time){
                q1.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};