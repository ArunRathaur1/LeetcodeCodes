class Solution {
public:
    bool possible(long long mid,long long k,vector<int>& candies){
        if(mid==0)return true;
        long long count=0;
        for(auto i: candies){
            count=count+i/mid;
            if(count>=k)return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long right=*max_element(candies.begin(),candies.end());
        long long left=1;
        int ans=0;
        cout<<right<<endl;
        while(left<=right){
            long long mid=(left+right)/2;
            if(possible(mid,k,candies)){
                ans=mid;
                left=mid+1;
            }
            else{
                
                right=mid-1;
            }
        }
        return ans;
    }
};