class Solution {
public:
    int minBitFlips(int start, int goal) {
        int c=0;
      while(goal!=0 ||start!=0){
        int k1=start&1;
        int k2=goal&1;
        if(k1!=k2)c++;
        start=start>>1;
        goal=goal>>1;
      } 
      return c; 
    }
};