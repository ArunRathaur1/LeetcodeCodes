class Solution {
public:
    vector<string> stringSequence(string target) {
       vector<string>st;
       string cs="";
       int l=target.length();
       for(int i=0;i<l;i++){
            char curr='a';
            while(target[i]!=curr){
                cout<<cs+curr<<" ";
                st.push_back(cs+curr);
                curr++;
            }
            st.push_back(cs+curr);
            cs=cs+target[i];
       } 
       return st;
    }
};