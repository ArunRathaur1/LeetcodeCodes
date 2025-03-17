class Solution {
public:
    bool possbile(long long time,vector<int>ranks,long long cars,long long length){
        long long count=0;
        for(long long i=0;i<length;i++){
            count=count+1LL*sqrt(time/ranks[i]);
            if(count>=cars)return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        long long l=ranks.size();
        long long left=0;
        long long right=1LL*ranks[l-1]*cars*cars;
        long long ans=0;
        while(left<=right){
            long long mid=1LL*(left+right)/2;
            if(possbile(mid,ranks,cars,l)){
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