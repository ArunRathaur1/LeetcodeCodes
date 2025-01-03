class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        long long tem=1;
        int count=0;
        int index=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
                index=i;
            }
            else{
                tem=tem*nums[i];
            }
        }
        if(count>=2)return ans;
        else if(count==1){
            ans[index]=tem;
            return ans;
        }
        else{
             for(int i=0;i<n;i++){
                ans[i]=tem;
            }
            for(int i=0;i<n;i++){
                if(nums[i]!=0){
                    ans[i]=ans[i]/nums[i];
                }
            }
        }
        return ans;
    }
};