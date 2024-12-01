class Solution {
public:
    int dominantIndex(vector<int>& nums) {
      int h=INT_MIN;
      int index=-1;
      for(int i=0;i<nums.size();i++){
        if(h<nums[i]){
            h=nums[i];
            index=i;
        }
      } 
        for(int i=0;i<nums.size();i++){
            if(i!=index&& nums[i]*2>h){
                return -1;
            }
        }
        return index;
    }
};