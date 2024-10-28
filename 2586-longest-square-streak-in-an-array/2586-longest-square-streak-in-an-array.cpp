class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int>st;
        int maxcount=INT_MIN;
        int size=nums.size();
        for(auto I:nums)st.insert(I);
        for(int i=0;i<size;i++){
            long long  x=nums[i];
            int count=0;
            while(st.find(x)!=st.end()){
               count++;
                if(x>INT_MAX/x)
                {
                    break;
                }
                x=x*x;
                
            }
            maxcount=max(count,maxcount);
        }
        if(maxcount>=2){
            return maxcount;
        }
        return -1;
    }
};