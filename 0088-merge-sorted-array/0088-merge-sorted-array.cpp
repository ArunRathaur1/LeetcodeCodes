class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int a1=0,a2=0;
        while(a1<m&&a2<n){
            if(nums1[a1]>nums2[a2]){
                ans.push_back(nums2[a2]);
                a2++;
            }
            else{
                 ans.push_back(nums1[a1]);
                 a1++;
            }
        }
        while(a1<m){
              ans.push_back(nums1[a1]);
                 a1++;
        }
        while(a2<n){
             ans.push_back(nums2[a2]);
                a2++;
        }
        nums1.assign(ans.begin(),ans.end());
    }
};