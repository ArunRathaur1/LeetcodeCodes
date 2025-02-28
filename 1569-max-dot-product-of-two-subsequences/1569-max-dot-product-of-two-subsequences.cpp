// class Solution {
// public:
//     int maxproduct(vector<int>&nums1,vector<int>&nums2,int i,int j,int l1,int l2,vector<vector<int>>&dp){
//         if(i>=l1|| j>=l2)return INT_MIN;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int case1=nums1[i]*nums2[j];
//         int next=maxproduct(nums1,nums2,i+1,j+1,l1,l2,dp);
//         int case4=case1;
//         if(next!=INT_MIN)
//         case4=case4+next;
//         int case2=maxproduct(nums1,nums2,i+1,j,l1,l2,dp);
//         int case3=maxproduct(nums1,nums2,i,j+1,l1,l2,dp);
//         dp[i][j]=max({case1,case2,case3,case4});
//         return dp[i][j];
//     }
//     int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
//         int l1=nums1.size();
//         int l2=nums2.size();
//         vector<vector<int>>dp(l1,vector<int>(l2,-1));
//         return maxproduct(nums1,nums2,0,0,l1,l2,dp);
//     }
// };
class Solution {
public:
   
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size();
        int l2=nums2.size();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,INT_MIN));
        for(int i=l1-1;i>=0;i--){
            for(int j=l2-1;j>=0;j--){
                int currp=nums1[i]*nums2[j];
                dp[i][j]=max({
                    currp,
                    currp+(dp[i+1][j+1]!=INT_MIN?dp[i+1][j+1]:0),
                    dp[i][j+1],
                    dp[i+1][j]
                });
            }
        }
        return dp[0][0];
    }
};