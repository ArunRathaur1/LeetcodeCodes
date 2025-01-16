class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x1=nums1.size();
        int x2=nums2.size();
        int absxor=0;
        if(x1%2==0&&x2%2==0)return 0;
        int first=0,second=0;
        for(int i=0;i<x1;i++){
            first=first^nums1[i];
        }
        for(int i=0;i<x2;i++){
            second=second^nums2[i];
        }
        if(x1%2==0){
            return first;
        }
        else if(x2%2==0){
            return second;
        }
        else{
            return first^second;
        }
    }
};