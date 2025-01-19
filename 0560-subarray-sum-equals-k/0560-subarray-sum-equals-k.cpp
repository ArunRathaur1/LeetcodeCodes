class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int count=0;
       int size=nums.size();
       for(int i=0;i<size;i++){
            int sum=0;
            for(int j=i;j<size;j++){
                sum=sum+nums[j];
                if(sum==k)count++;
            }
       }
       return count; 
    }
};