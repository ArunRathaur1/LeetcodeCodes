class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ar=nums;
        for(auto I:nums)ar.push_back(I);
        stack<int>nextGrater;
        vector<int>ans;
        int size=ar.size();
        for(int i=size-1;i>=0;i--){
            if(nextGrater.empty()){
               nextGrater.push(ar[i]);
               ans.push_back(-1);
            }
            else{
                while(!nextGrater.empty()&& nextGrater.top()<=ar[i])nextGrater.pop();
                if(nextGrater.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(nextGrater.top());
                }
                nextGrater.push(ar[i]);
            }
        }
        int index=ans.size()-1;
        for(int i=0;i<nums.size();i++){
            nums[i]=ans[index];
            index--;
        }
        return nums;
    }
};