class Solution {
public:
    bool isprefixandsuffix(string s1,string s2){
        if(s1.length()>s2.length())return false;
        int l=s1.length();
        for(int i=0;i<l;i++){
            if(s1[i]!=s2[i])return false;
        }
        int index=s2.length()-1;
        for(int i=l-1;i>=0;i--){
            if(s1[i]!=s2[index])return false;
            index--;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        int row=words.size();
        for(int i=0;i<row;i++){
            for(int j=i+1;j<row;j++){
                if(isprefixandsuffix(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};