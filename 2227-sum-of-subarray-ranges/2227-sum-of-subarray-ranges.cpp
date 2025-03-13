class Solution {
public:
    long long MaxSum(vector<int>&nums){
        stack<pair<int,int>>st;
        int size=nums.size();
        vector<long long>result(size,0);
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&& st.top().first<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                int k=st.top().second;
                result[i]=result[k]+nums[i]*1LL*(i-k);
                ans=ans+result[i];
            }
            else{
                result[i]=nums[i]*1LL*(i+1);
                ans=ans+result[i];
            }
            st.push({nums[i],i});
        }
        return ans;
    }
    long long MinSum(vector<int>&nums){
        stack<pair<int,int>>st;
        int size=nums.size();
        vector<long long>result(size,0);
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&& st.top().first>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                int k=st.top().second;
                result[i]=result[k]+nums[i]*1LL*(i-k);
                ans=ans+result[i];
            }
            else{
                result[i]=nums[i]*1LL*(i+1);
                ans=ans+result[i];
            }
            st.push({nums[i],i});
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long k=MaxSum(nums);
        long long k1=MinSum(nums);
        return k-k1;
    }
};