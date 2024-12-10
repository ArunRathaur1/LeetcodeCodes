class Solution {
public:
    void generate(vector<int>&nums,set<vector<int>>&ans,vector<int>&tem,int index,int size){
        if(index==size){
            ans.insert(nums);
        }
        for(int i=index;i<size;i++){
            swap(nums[index],nums[i]);
            generate(nums,ans,tem,index+1,size);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // set<vector<int>>st;
        // vector<vector<int>>ans;
        // vector<int>tem;
        // int size=nums.size();
        // generate(nums,st,tem,0,size);
        // for(auto i: st){
        //     ans.push_back(i);
        // }
        // return ans;



        //code 2
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            ans.push_back(nums);
        }
        return ans;
    }
};