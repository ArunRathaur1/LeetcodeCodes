class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int totalsum=INT_MAX;
        int minvalue=INT_MAX;
        int size=nums.size();
        for(int i=0;i<size;i++){
            int j=i+1;
            int k=size-1;
            while(j<k){
                int p=nums[i]+nums[j]+nums[k];
                if(p>target){
                    k--;
                    if(abs(p-target)<minvalue){
                        minvalue=abs(p-target);
                        totalsum=p;
                    }
                }
                else if(p<target){
                    j++;
                    if(abs(p-target)<minvalue){
                        minvalue=abs(p-target);
                        totalsum=p;
                    }
                }
                else{
                    return target;
                }
            }
        }
        return totalsum;
    }
};