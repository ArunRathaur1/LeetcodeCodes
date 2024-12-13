class Solution {
public:
    vector<vector<int>> generate(vector<int>&nums,int index,int size){
        if(index==size){
            return {{}};
        }
        vector<vector<int>>tem=generate(nums,index+1,size);
        vector<vector<int>>newsubsets;
        for(int i=0;i<tem.size();i++){
            vector<int>k=tem[i];
            k.push_back(nums[index]);
            newsubsets.push_back(k);
        }
        tem.insert(tem.end(),newsubsets.begin(),newsubsets.end());
        set<vector<int>>st(tem.begin(),tem.end());
        vector<vector<int>>tem2(st.begin(),st.end());
        return tem2;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return generate(nums,0,nums.size());
    }
};