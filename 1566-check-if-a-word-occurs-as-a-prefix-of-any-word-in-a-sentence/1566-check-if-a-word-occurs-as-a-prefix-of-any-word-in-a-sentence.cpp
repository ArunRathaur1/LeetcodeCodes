class Solution {
public:
    int isPrefixOfWord(string ar, string searchWord) {
        int length=ar.length();
        stringstream s(ar);
        vector<string>st;
        string word;
        while(getline(s,word,' ')){
            st.push_back(word);
        }
        for(int i=0;i<st.size();i++){
            string s1=st[i];
            int flag=0;
            for(int i=0;i<searchWord.size();i++){
                if(s1[i]!=searchWord[i]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                return i+1;
            }
        }
        return -1;
    }
};