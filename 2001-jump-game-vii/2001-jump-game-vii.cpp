class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        if(s[n-1]=='1')return false;
        queue<int>q;
        int farthest=0;
        q.push(0);
        while(!q.empty()){
            int tem=q.front();
            q.pop();
            int k=max(tem+minJump,farthest+1);
            int y=min(tem+maxJump,n-1);
            for(int i=k;i<=y;i++){
                if(s[i]=='0'){
                    q.push(i);
                }
                if(i==n-1)return true;
            }
            farthest=max(farthest,tem+maxJump);
        }
        return false;
    }
};