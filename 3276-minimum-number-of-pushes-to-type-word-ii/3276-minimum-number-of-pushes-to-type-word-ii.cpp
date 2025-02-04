class Solution {
public:
    static bool  cmp(const int a,const int b){
        return a>b;
    }
    int minimumPushes(string word) {
       vector<int>ar(26,0);
        for(int i=0;i<word.length();i++){
            ar[word[i]-'a']++;
        }
        sort(ar.begin(),ar.end(),cmp);
        int k=0;
        int index=0;
        int count=0;
        for(auto i: ar){
            if(index%8==0){
                k++;
            }
            index++;
            count=count+k*i;
        }
        return count;
    }
};