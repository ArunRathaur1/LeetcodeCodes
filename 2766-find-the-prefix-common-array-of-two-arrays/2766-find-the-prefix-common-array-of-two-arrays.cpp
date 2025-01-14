class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int x=A.size();
        vector<int>freq1(x+1,0);
        vector<int>ans(x,0);
        vector<int>freq2(x+1,0);
        for(int i=0;i<x;i++){
            int count=0;
            freq1[A[i]]++;
            freq2[B[i]]++;
            for(int j=0;j<x+1;j++){
                if(freq1[j]==1&& freq2[j]==1){
                    count++;
                }
            }
            ans[i]=count;
        }
        return ans;
    }
};