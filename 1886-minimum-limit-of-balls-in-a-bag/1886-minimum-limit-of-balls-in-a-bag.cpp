class Solution {
public:
    bool possbile(vector<int>nums,int balls,int op){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%balls==0)count=count+nums[i]/balls-1;
            else
            count=count+nums[i]/balls;
            if(count>op)return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int right=*max_element(nums.begin(),nums.end());
        int left=1;
        int ans=right;
        while(left<=right){
            int mid=(left+right)/2;
            if(possbile(nums,mid,maxOperations)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};