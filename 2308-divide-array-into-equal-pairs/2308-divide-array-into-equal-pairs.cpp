class Solution {
public:
    bool divideArray(vector<int>& nums) {
     vector<int>ar(500+1,0);
     for(auto i : nums){
       ar[i]++;
     }
     for(auto i: ar){
        if(i%2!=0)return false;
     }
     return true;
    }
};