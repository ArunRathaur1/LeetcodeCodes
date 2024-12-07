class Solution {
public:
    bool check(vector<int>&nums,int op,int mid){
        for(int i=0;i<nums.size();i++){
            op=op-(nums[i]-1)/mid;
            if(op<0)return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int op) {
        int left=1;
        int right=*std::max_element(nums.begin(),nums.end());
        int ans=right;
        while(left<right){
            int mid=(left+right)/2;
            if(check(nums,op,mid)){
                right=mid;
                ans=mid;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};