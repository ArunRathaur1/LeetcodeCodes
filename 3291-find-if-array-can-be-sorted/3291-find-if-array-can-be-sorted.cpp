class Solution {
public:
    bool canSortArray(vector<int>& nums) {
       vector<pair<int,int>>ar;
       int size=nums.size();
       for(int i=0;i<size;i++){
            int tem=0;
            int x=nums[i];
            while(x!=0){
                int p=x&1;
                if(p==1)tem++;
                x=x>>1;
            }
            ar.push_back({nums[i],tem});
       }
       for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(ar[j].first>ar[j+1].first&& ar[j].second==ar[j+1].second){
                swap(ar[j],ar[j+1]);
            }
        }
       }
        for(int i=1;i<size;i++){
            if(ar[i-1].first>ar[i].first)return false;
        }
        return true;
    }
};