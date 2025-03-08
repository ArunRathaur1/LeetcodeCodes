class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        while(start!=goal){
            int x1=start&1;
            int x2=goal&1;
            if(x1!=x2)ans++;
            start=start>>1;
            goal=goal>>1;
        }
        return ans;
    }
};