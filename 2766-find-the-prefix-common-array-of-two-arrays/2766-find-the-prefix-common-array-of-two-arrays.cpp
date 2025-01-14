class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int x=A.size();
        vector<int>freq1(x+1,0);
        vector<int>ans(x,0);
        int count=0;
        for(int i=0;i<x;i++){
            freq1[A[i]]++;
            if(freq1[A[i]]==2)count++;
            freq1[B[i]]++;
            if(freq1[B[i]]==2)count++;
            ans[i]=count;
        }
        return ans;
    }
};