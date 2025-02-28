class Solution {
public:
    void combination(vector<int>&nums,int sum,vector<int>&tem,vector<vector<int>>&ans,int index,int n,int target){
         if(sum==target){
            ans.push_back(tem);
            return;
        }
        if(index>=n)return;
        if(sum>target)return ;
        cout<<sum<<endl;
       
        for(int i=index;i<n;i++){
            if(i>index&& nums[i]==nums[i-1])continue;
            tem.push_back(nums[i]);
            combination(nums,sum+nums[i],tem,ans,i+1,n,target);
            tem.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>tem;
        int index=0;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        combination(candidates,0,tem,ans,index,n,target);
        return ans;
    }
};