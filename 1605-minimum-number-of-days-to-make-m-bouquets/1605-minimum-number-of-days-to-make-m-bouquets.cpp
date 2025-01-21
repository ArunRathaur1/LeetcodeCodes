class Solution {
public:
    bool possible(vector<int>&bloomDay,int mid,int m,int k){
        int count=0;
        int cons=0;
        for(auto i:bloomDay){
            if(i<=mid){
                cons++;
            }
            else{
                cons=0;
            }
            if(cons==k){
                count++;
                cons=0;
            }
        }
        if(count>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size=bloomDay.size();
        if(1LL*m*k>size)return -1;
        int left=1;
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(possible(bloomDay,mid,m,k)){
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