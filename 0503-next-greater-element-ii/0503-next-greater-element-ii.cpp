class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int k=nums.size();
        stack<int>st;
        nums.insert(nums.end(),nums.begin(),nums.end());
        int m=nums.size();
        vector<int>tem(m,-1);
        for(int i=m-1;i>=0;i--){
            while(!st.empty()&& st.top()<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                tem[i]=st.top();
            }
            st.push(nums[i]);
        }
        vector<int>ans(tem.begin(),tem.begin()+k);
        return ans;
    }
};