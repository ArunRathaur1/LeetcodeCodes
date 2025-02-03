class Solution {
public:
    int incresing(vector<int>&nums){
        int l=nums.size();
        int p=INT_MIN;
        int count=0;
        int maxcount=0;
        for(int i=0;i<l;i++){
                if(nums[i]>p){
                    count++;
                    p=nums[i];
                }
                else{
                    maxcount=max(maxcount,count);
                    p=nums[i];
                    count=1;
                }
        }
        maxcount=max(maxcount,count);
        return maxcount;
    }
    int decreasing(vector<int>&nums){
        int l=nums.size();
        int p=INT_MAX;
        int count=0;
        int maxcount=0;
        for(int i=0;i<l;i++){
                if(nums[i]<p){
                    count++;
                    p=nums[i];
                }
                else{ 
                    maxcount=max(maxcount,count);
                    p=nums[i];
                    count=1;
                }
        }
        maxcount=max(maxcount,count);
        return maxcount;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(incresing(nums),decreasing(nums));
    }
};