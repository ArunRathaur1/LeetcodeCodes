class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string>st;
        for(auto I :bannedWords){
            st.insert(I);
        }
        int count=0;
        for(auto i: message){
            // cout<<i<<endl;
            // for(auto i: st){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            if(st.find(i)!=st.end())count++;
            if(count>=2)return true;
        }
        return false;
    }
};