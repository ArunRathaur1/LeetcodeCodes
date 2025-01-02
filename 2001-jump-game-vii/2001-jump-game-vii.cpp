class Solution {
public:
    bool canReach(string s, int minJ, int maxJ) {
        int n=s.length();
        if(s[n-1]=='1')return false;
       queue<int>q;
       int farthest=0;
       q.push(0);
       while(!q.empty()){
            int tem=q.front();
            q.pop();
            int x=n-1;
            int k=min(tem+maxJ,x);
            int y=max(tem+minJ,farthest+1);
            for(int i=y;i<=k;i++){
                    if(s[i]=='0'){
                        q.push(i);
                    }
                    if(i==n-1)return true;
                }
            farthest=max(farthest,tem+maxJ);
            }
      return false;
    }
};
