class Solution {
public:
    bool checksamebits(int a,int b){
        return __builtin_popcount(a)==__builtin_popcount(b);
    }
    bool canSortArray(vector<int>& nums) {
       vector<int>ar=nums;
       int size=nums.size();
       for(int i=0;i<size;i++){
            for(int j=0;j<size-1;j++){
                if(checksamebits(ar[j],ar[j+1])&& ar[j]>ar[j+1]){
                    swap(ar[j],ar[j+1]);
                }
            }
       }
        for(int i=1;i<size;i++){
            if(ar[i-1]>ar[i])return false;
        }
        return true;
    }
};