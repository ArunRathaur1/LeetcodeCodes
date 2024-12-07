class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size=nums.size();
        set<vector<int>>ans;
        vector<vector<int>>arr;
        sort(nums.begin(),nums.end());
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
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
                        ans.insert(ar);
                        k++;
                    }
                }
            }
        }
        for(auto i:ans){
            arr.push_back(i);
        }
        return arr;
    }
};