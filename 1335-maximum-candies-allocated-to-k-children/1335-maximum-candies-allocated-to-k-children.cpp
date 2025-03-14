class Solution {
public:
    bool notpossible(vector<int>candies,long long k){
        long long sum=0;
        int l=candies.size();
        for(int i=0;i<l;i++){
            sum=sum+candies[i];
            if(sum>=k)return false;
        }
        return true;
    }
    bool possible(long long mid,long long k,vector<int>& candies){
        
        long long count=0;
        for(auto i: candies){
            count=count+i/mid;
        }
        if(count>=k)return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
       if(notpossible(candies,k))return 0;
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