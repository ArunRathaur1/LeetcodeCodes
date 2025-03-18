class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int left=0;
        int ans=0;
        map<int,int>m;
        m[0]=1;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            currsum=currsum+nums[i];
            if(m.find(currsum-k)!=m.end()){
                ans=ans+m[currsum-k];
            }
            m[currsum]++;
        }
        return ans;
    }
};