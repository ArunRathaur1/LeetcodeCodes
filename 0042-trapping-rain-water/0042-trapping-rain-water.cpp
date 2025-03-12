class Solution {
public:
    int trap(vector<int>& nums) {
        stack<int>st;
        int l=nums.size();
        int currmax=-1;
        vector<int>left(l,-1),right(l,-1);
        for(int i=l-1;i>=0;i--){
            if(currmax<=nums[i]){
                currmax=nums[i];
            }
            else{
                right[i]=currmax;
            }
        }
        currmax=-1;
        for(int i=0;i<l;i++){
            if(currmax<=nums[i]){
                currmax=nums[i];
            }
            else{
                left[i]=currmax;
            }
        }
        int count=0;
        for(int i=0;i<l;i++){
            if(left[i]!=-1&&right[i]!=-1)
            {
                count+=min(left[i],right[i])-nums[i];
            }
        }
        return count;
    }
};