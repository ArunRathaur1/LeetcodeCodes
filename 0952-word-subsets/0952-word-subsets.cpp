class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
      int n=words1.size();
      int m=words2.size();
      vector<int>freq(26,0);
      vector<string>ans;
      for(int i=0;i<m;i++){
            vector<int>tem(26,0);
            for(auto ch: words2[i]){
                tem[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                if(freq[i]<tem[i]){
                    freq[i]=tem[i];
                }
            }
        }
        for(int i=0;i<n;i++){
            vector<int>ar(26,0);
            for(auto ch:words1[i]){
                ar[ch-'a']++;
            }
            int flag=0;
            for(int j=0;j<26;j++){
                if(freq[j]>ar[j]){
                    flag=1;
                    break;
                }   
            }
            if(flag==0){
                ans.push_back(words1[i]);
            }
        }  
        return ans;
    }
};