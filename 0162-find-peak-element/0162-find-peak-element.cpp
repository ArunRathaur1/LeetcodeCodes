class Solution {
public:
    int findPeakElement(vector<int>& ar) {
        int size=ar.size();
        if(ar.size()==1)return 0;
        else if(ar[0]>ar[1])return 0;
        else if(ar[size-1]>ar[size-2])return size-1;
      int left=1;
      int right=ar.size()-2;
      int height=INT_MIN;
        while(left<=right){
            int mid=(left+right)/2;
            if(ar[mid]>ar[mid-1]&& ar[mid]>ar[mid+1])return mid;
            else if(ar[mid]>ar[mid+1]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return height;
    }
};