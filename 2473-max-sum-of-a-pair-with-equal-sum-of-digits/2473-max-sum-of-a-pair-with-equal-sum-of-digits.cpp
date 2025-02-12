class Solution {
public:
    int digitsum(int number){
        int sum=0;
        while(number!=0){
            sum=sum+number%10;
            number=number/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        vector<pair<int,int>>ar(100,{-1,-1});
        int p=nums.size();
        for(int i=0;i<p;i++){
            int x=digitsum(nums[i]);
            if(ar[x].first==-1){
                ar[x].first=nums[i];
            }
            else if(ar[x].second==-1){
                ar[x].second=nums[i];
            }
            else{
               if(ar[x].first>=ar[x].second&& nums[i]>ar[x].second){
                ar[x].second=nums[i];
               }
               else if(ar[x].second>=ar[x].first&& nums[i]>ar[x].first){
                ar[x].first=nums[i];
               }

            }
        }
        long long maxsum=-1;
        for(int i=0;i<100;i++){
            if(ar[i].first!=-1&& ar[i].second!=-1){
                maxsum=max(maxsum,1LL*ar[i].first+1LL*ar[i].second);
            }
        }
        return maxsum;
    }
};