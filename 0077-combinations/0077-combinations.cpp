class Solution {
public:
    void getcombination(vector<vector<int>>&ans,vector<int>&tem,int index,int n,int k){
        if(tem.size()==k){
            ans.push_back(tem);
            return;
        }
        for(int i=index;i<=n;i++ ){
            tem.push_back(i);
            getcombination(ans,tem,i+1,n,k);
            tem.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>tem;
        getcombination(ans,tem,1,n,k);
        return ans;
    }
};