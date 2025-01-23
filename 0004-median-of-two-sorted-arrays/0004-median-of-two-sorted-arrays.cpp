class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size();
        int s2=nums2.size();
        int prev=-1;
        int curr=-1;
        int i1=0;
        int i2=0;
        int index=(s1+s2)/2;
        while(i1<s1&& i2<s2&& (i1+i2)<=index){
            prev=curr;
            if(nums1[i1]>nums2[i2]){
                curr=nums2[i2];
                i2++;
            }
            else{
                curr=nums1[i1];
                i1++;
            }
        }
        while(i1<s1 && (i1+i2)<=index){
            prev=curr;
            curr=nums1[i1];
            i1++;
        }
        while(i2<s2&& (i1+i2)<=index){
            prev=curr;
            curr=nums2[i2];
            i2++;
        }
        cout<<prev<<" "<<curr<<endl;

        if((s1+s2)%2==0){
            return (float(prev+curr))/2;
        }
        return float(curr);
    }
};