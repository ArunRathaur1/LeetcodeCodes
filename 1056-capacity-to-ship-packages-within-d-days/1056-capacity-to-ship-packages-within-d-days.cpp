class Solution {
public:
    bool possible(vector<int>&weights,int mid,int days){
        int count=0;
        int sum=0;
        for(auto i: weights){
            sum=sum+i;
            if(sum>mid){
                count++;
                sum=i;
            }
        }
        if(sum<=mid)count++;
        if(count<=days)return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int right=accumulate(weights.begin(),weights.end(),0);
        int left=*max_element(weights.begin(),weights.end());
        int ans=0;
        while(right>=left){
            int mid=(left+right)/2;
            if(possible(weights,mid,days)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};