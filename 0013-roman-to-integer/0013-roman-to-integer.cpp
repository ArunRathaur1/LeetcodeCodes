class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int size=s.length();
        vector<int>ar(size,0);
        vector<int>gar(size,0);
        for(int i=0;i<size;i++){
            ar[i]=m[s[i]];
        }
        gar[size-1]=ar[size-1];
        for(int i=size-2;i>=0;i--){
           gar[i]=max(gar[i+1],ar[i]);
        }
        int ans=0;
        for(int i=0;i<size;i++){
            if(gar[i]>ar[i]){
                ans=ans-ar[i];
            }
            else{
                ans=ans+ar[i];
            }
        }
        return ans;
    }
};