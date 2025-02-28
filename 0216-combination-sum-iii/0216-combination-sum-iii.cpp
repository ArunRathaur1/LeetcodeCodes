class Solution {
public:
    void combination(vector<int>&tem,vector<vector<int>>&ans,int n,int index,int k,int sum){
        if(k==0&& sum==n){
            ans.push_back(tem);
            return ;
        }
        if(k<0|| sum>n)return ;
        for(int i=index;i<=9;i++){
            tem.push_back(i);
            combination(tem,ans,n,i+1,k-1,sum+i);
            tem.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>tem;
        vector<vector<int>>ans;
        int sum=0;
        combination(tem,ans,n,1,k,sum);
        return ans;
    }
};