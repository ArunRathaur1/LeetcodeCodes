class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int count=0;
       int size=nums.size();
       map<int,int>m;
       m[0]=1;
       int currsum=0;
       int ans=0;
       for(int i=0;i<size;i++){
        currsum=currsum+nums[i];
        if(m.find(currsum-k)!=m.end()){
            ans=ans+m[currsum-k];
        }
        m[currsum]++;
       }
       return ans;
    }
};