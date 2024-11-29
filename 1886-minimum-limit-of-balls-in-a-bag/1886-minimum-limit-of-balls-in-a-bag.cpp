class Solution {
public:
    bool check(int mid,vector<int>nums,int op){
        for(int i=0;i<nums.size();i++){
            op=op-(nums[i]-1)/mid;
            if(op<0)return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int op) {
        int ans=0;
        int left=1;
        int right = *std::max_element(nums.begin(), nums.end());
        ans=right;
        while(left<=right){
            int mid=(left+right)/2;
            if(check(mid,nums,op)){
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