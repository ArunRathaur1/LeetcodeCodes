class Solution {
public:
    bool possible(vector<int>&piles,int k,int h){
        long long count=0;
        for(auto banana: piles){
           if((banana%k)==0){
            count=count+banana/k;
           }
           else{
            count=count+1+banana/k;
           }
        }
        if(count<=h)return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int right=*max_element(piles.begin(),piles.end());
        int left=1;
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(possible(piles,mid,h)){
                ans=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return ans;
    }
};