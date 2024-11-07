class Solution {
public:
    int largestCombination(vector<int>& ar) {
        vector<int>bitcount(25,0);
        int size=ar.size();
        for(int i=0;i<size;i++){
            int x=ar[i];
            int count=0;
            while(x!=0){
                int p=x&1;
                if(p==1){
                    bitcount[count]++;
                }
                count++;
                x=x>>1;
            }
        }
        return *max_element(bitcount.begin(),bitcount.end());
    }
};