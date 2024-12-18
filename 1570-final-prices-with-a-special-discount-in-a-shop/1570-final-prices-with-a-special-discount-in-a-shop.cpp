class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans;
        int l=prices.size();
        for(int i=0;i<l;i++){
            int j=i+1;
            while(j<l&& prices[i]<prices[j]){
                j++;
            }
            int tem=j==l?0:prices[j];
            prices[i]=prices[i]-tem;
        }
        return prices;
    }
};