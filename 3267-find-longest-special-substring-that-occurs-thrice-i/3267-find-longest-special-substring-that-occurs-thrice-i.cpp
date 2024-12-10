class Solution {
public:
    int maximumLength(string s) {
        map<string,int>ar;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    string p=s.substr(i,j-i+1);
                    ar[p]++;
                }
                else{
                    break;
                }
            }
        }
        int x=-1;
        for(auto i:ar){
            if(i.second>=3){
                int p=i.first.length();
                x=max(x,p);
            }
        }
        return x;
    }
};