class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int suffix=1;
        int m=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(prefix==0)prefix=1;
            prefix=prefix*nums[i];
            m=max(prefix,m);
        }
        for(int i=n-1;i>=0;i--){
            if(suffix==0)suffix=1;
            suffix=suffix*nums[i];
            m=max(suffix,m);
        }
        return m;
    }
};