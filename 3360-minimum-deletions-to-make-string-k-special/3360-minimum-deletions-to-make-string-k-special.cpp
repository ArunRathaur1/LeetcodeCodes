class Solution {
public:
    int solve(vector<int>&ar,int left,int right,int k){
        if(left>=right)return 0;
        int case1=0,case2=0;
        case1=ar[left]+solve(ar,left+1,right,k);
        if(ar[right]-k-ar[left]>=0)
        case2=ar[right]-k-ar[left]+solve(ar,left,right-1,k);
        return min(case1,case2);
    }
    int minimumDeletions(string word, int k) {
        map<char,int>m;
        int l=word.length();
        for(int i=0;i<l;i++){
            m[word[i]]++;
        }
        vector<int>ar;
        for(auto i: m){
            ar.push_back(i.second);
        }
        sort(ar.begin(),ar.end());
        int left=0;
        int right=ar.size()-1;
        int c=solve(ar,left,right,k);
        return c;
    }
};