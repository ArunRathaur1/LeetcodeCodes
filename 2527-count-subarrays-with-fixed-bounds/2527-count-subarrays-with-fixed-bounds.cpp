class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int m2=-1;int m1=-1;
        int cul=-1;
        long long ans=0;
        int l=nums.size();
        for(int i=0;i<l;i++){
            if(nums[i]>maxK||nums[i]<minK)cul=i;
            if(nums[i]==minK)m1=i;
            if(nums[i]==maxK)m2=i;
            int smaller=min(m1,m2);
            long long tem=smaller-cul;
            ans+=tem>0?tem:0;
        }
        return ans;
    }
};