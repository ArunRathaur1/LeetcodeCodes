class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size();
        int s2=nums2.size();
        long long sum1=0,sum2=0,zero1=0,zero2=0;
        for(int i=0;i<s1;i++){
            if(nums1[i]==0){
                zero1++;
            }
            else{
                sum1=sum1+nums1[i];
            }
        }
        for(int i=0;i<s2;i++){
            if(nums2[i]==0){
                zero2++;
            }
            else{
                sum2=sum2+nums2[i];
            }
        }
        if((zero1==0 and sum1<sum2+zero2)||(zero2==0 and sum2<sum1+zero1)){
            return -1;
        }
        else{
            return max(sum1+zero1,sum2+zero2);
        }
    }
};