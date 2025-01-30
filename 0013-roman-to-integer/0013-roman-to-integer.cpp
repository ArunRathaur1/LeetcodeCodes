class Solution {
public:
    int romanToInt(string s) {
        std::vector<std::pair<char, int>> x = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        map<char,int>m;
        for(auto i: x){
            m[i.first]=i.second;
        }
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