class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>m;
        int k=nums.size();
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                m[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto i:m){
            if(i.second>=2){
                int x=(i.second*(i.second-1))/2;
                ans=ans+ x*8;
            }
        }
        return ans;
    }
};