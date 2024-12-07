class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size=nums.size();
        vector<vector<int>>arr;
        sort(nums.begin(),nums.end());
        for(int i=0;i<size;i++){
            if(i>0&&nums[i]==nums[i-1])continue;

            for(int j=i+1;j<size;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;

                long long tem=nums[i]+nums[j];
                int k=j+1;
                int l=size-1;
                while(k<l){
                    if(tem+nums[l]+nums[k]>target){
                        l--;
                    }
                    else if(tem+nums[l]+nums[k]<target){
                        k++;
                    }
                    else{
                        vector<int>ar={nums[i],nums[j],nums[k],nums[l]};
                        arr.push_back(ar);
                        while(k<l&& nums[k]==nums[k+1])k++;
                        while(k<l&&nums[l]==nums[l-1])l--;
                        k++;
                        l--;
                    }
                }
            }
        }
        return arr;
    }
};