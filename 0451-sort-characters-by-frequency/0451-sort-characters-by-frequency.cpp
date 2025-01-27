class Solution {
public:
    string frequencySort(string s) {
       vector<int>ar(150,0);
       int n=s.length();
       for(int i=0;i<n;i++){
            ar[s[i]]++;
       }
       priority_queue<pair<int,char>,vector<pair<int,char>>>q;
       for(int i=0;i<150;i++){
            if(ar[i]>0){
                q.push({ar[i],char(i)});
            }
       } 
       string ans="";
       while(!q.empty()){
        pair<int ,char>ch=q.top();
        q.pop();
        for(int i=0;i<ch.first;i++){
            ans+=ch.second;
        }
       }
       return ans;
    }
};