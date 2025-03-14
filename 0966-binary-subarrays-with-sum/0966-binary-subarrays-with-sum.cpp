class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=nums.size();
        map<int,int>m;
        int prefix=0;
        int ans=0;
        m[0]=1;
        for(int i=0;i<l;i++){
            prefix=prefix+nums[i];
            if(m.find(prefix-goal)!=m.end()){
                ans=ans+m[prefix-goal];
            }
            m[prefix]++;
        } 
        return ans;   
    }
};