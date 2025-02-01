class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
      int flag=nums[0]%2==0?0:1;
      int n=nums.size();
      for(int i=1;i<n;i++){
        if(flag==0&& nums[i]%2==0)return false;
        if(flag==1&& nums[i]%2!=0)return false;
        flag=1-flag;
      } 
      return true; 
    }
};