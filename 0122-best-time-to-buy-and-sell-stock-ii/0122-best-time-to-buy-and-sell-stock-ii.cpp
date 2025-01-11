class Solution {
public:
    int maxProfit(vector<int>& ar) {
        int maxprofit=0;
        int n=ar.size();
        for(int i=1;i<n;i++){
            if(ar[i]>ar[i-1]){
                maxprofit=maxprofit+ar[i]-ar[i-1];
            }
        }
        return maxprofit;
    }
};