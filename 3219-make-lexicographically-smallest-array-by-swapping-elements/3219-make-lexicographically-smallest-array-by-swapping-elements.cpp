class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>ar;
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ar.push_back({nums[i],i});
        }
        sort(ar.begin(),ar.end());
        int left=0;
        for(int i=1;i<=n;i++){
            if(i==n||ar[i].first-ar[i-1].first>limit){
                vector<int>index;
                for(int j=left;j<i;j++){
                    index.push_back(ar[j].second);
                }
                sort(index.begin(),index.end());
                for (int j = left; j < i; ++j) {
                    ans[index[j - left]] = ar[j].first;
                }
                left=i;
            }
        }
        return ans;

    }
};