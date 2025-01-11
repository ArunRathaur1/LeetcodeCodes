class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int l1=0,l2=0;
        int n1=word1.length(),n2=word2.length();
        int turn=0;
        while(l1<n1&& l2<n2){
            if(turn%2==0){
                ans=ans+word1[l1];
                l1++;
            }
            else{
                ans=ans+word2[l2];
                l2++;
            }
            turn++;
        }
        while(l1<n1){
           ans=ans+word1[l1];
                l1++; 
        }
        while(l2<n2){
            ans=ans+word2[l2];
                l2++;
        }
        return ans;
    }
};