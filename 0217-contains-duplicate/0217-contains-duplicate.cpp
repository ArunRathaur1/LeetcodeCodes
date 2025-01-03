class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int>st;
      int t=nums.size();
      for(int i=0;i<t;i++){
        if(st.find(nums[i])==st.end())
        {
            st.insert(nums[i]);
        }
        else {
            return true;
        }
      }
      return false;
    }
};