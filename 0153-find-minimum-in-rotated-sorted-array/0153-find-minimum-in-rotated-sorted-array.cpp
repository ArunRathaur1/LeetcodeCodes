class Solution {
public:
    int findMin(vector<int>& ar) {
        int m=INT_MAX;
        int right=ar.size()-1;
        int left=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(ar[left]<=ar[mid]){
                m=min(ar[left],m);
                left=mid+1;
            }
            else{
                m=min(ar[mid],m);
                right=mid-1;
            }
        }
        return m;
    }
};