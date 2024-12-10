class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        int flag=0;
        for(int i=size-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                int minelement=*std::max_element(nums.begin()+i,nums.end());
                int index=-1;
                for(int j=i;j<size;j++){
                    if(nums[j]>nums[i]&& nums[j]<=minelement){
                        index=j;
                        minelement=nums[j];
                    }
                }
                swap(nums[index],nums[i]);
                sort(nums.begin()+i+1,nums.end());
                flag=1;
                break;
            }
        }
        if(flag==0){
        std::reverse(nums.begin(),nums.end()); 
        }
    }
};