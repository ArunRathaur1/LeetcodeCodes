class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
      long long count=0;
      long long nonzero=0;
      int l=nums.size();
      for(int i=0;i<l;i++)
      {
        if(nums[i]==0){
            count++;
        }
        else{
            nonzero=nonzero+(count*(count+1))/2;
            count=0;
        }
      }
      if(count!=0){
        nonzero=nonzero+(count*(count+1))/2;
      } 
      return nonzero; 
    }
};