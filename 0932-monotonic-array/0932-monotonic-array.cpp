class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        //increasing
        int value=nums[0];
        int flag=0;
        for(int i=0;i<nums.size();i++){
            if(value>nums[i]){
                flag=1;
                break;
            }
            else{
                value=nums[i];
            }
        }
        if(flag==0)return true;
        //decresing
        value=nums[0];
        int flag2=0;
        for(int i=0;i<nums.size();i++){
            if(value<nums[i]){
                flag2=1;
                break;
            }
            else{
                value=nums[i];
            }
        }
        if(flag2==0)return true;


             return false; 
    }
};