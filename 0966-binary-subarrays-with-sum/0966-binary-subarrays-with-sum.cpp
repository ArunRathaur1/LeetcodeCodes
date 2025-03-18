class Solution {
public:
    int sumlessthanK(vector<int>&nums,int goal){
        int sum=0;
        int left=0;
        int l=nums.size();
        int ans=0;
        for(int i=0;i<l;i++){
            sum=sum+nums[i];
            while(left<=i&& sum>goal){
                sum=sum-nums[left];
                left++;
            }
            ans=ans+(i-left+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int c1=sumlessthanK(nums,goal);
        int c2=sumlessthanK(nums,goal-1);
        cout<<c1<<" "<<c2<<endl;
        return c1-c2;
    }
};