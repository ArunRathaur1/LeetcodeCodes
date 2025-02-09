class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       unordered_map<int,int>ar;
       long long l=nums.size();
       for(int i=0;i<l;i++){
        nums[i]=nums[i]-i;
        ar[nums[i]]++;
       } 
       long long total=0;
       for(auto x:ar){
            total=total+(1ll*x.second*(x.second-1))/2;
       }
       return (l*(l-1))/2-total;
    }
};