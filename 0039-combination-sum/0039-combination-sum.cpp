class Solution {
public:
    void output(vector<int>&ar,int target,int index,vector<vector<int>>&ans,vector<int>&st){
        if(target==0){
            ans.push_back(st);
        }
        if(target<0)return;
        for(int i=index;i<ar.size();i++){
            if (ar[i] <= target) {
                st.push_back(ar[i]);
                output(ar,target-ar[i],i,ans,st);
                st.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ar;
           output(candidates, target, 0, ans, ar);
        return ans;
    }
};