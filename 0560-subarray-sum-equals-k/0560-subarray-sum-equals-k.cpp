class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currsum=0;
        int l=nums.size();
        int left=0;
        int ans=0;
        map<int,int>m;
        m[0]=1;
        for(int right=0;right<l;right++){
            currsum=currsum+nums[right];
            if(m.find(currsum-k)!=m.end()){
                ans=ans+m[currsum-k];
            }
            m[currsum]++; 
        }
        return ans;
    }
};