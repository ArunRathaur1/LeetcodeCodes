class Solution {
public:
    int countGoodTriplets(vector<int>& ar, int a, int b, int c) {
        int count=0;
        int l=ar.size();
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                if(abs(ar[j]-ar[i])<=a){
                    for(int k=j+1;k<l;k++){
                        if(abs(ar[j]-ar[k])<=b&&abs(ar[i]-ar[k])<=c)count++;
                    }
                }
            }
        }
        return count;
    }
};