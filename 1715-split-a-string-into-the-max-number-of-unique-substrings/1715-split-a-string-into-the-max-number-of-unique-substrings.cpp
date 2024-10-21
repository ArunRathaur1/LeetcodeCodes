class Solution {
public:
    int maxlength(string s,set<string>&st,int index){
        if(index==s.length())return 0 ;
        int maxvalue=0;
        for(int i=index;i<s.length();i++){
            string s1=s.substr(index,i-index+1);
            if(st.find(s1)==st.end()){
                st.insert(s1);
                maxvalue=max(maxvalue,1+maxlength(s,st,i+1));
                st.erase(s1);
            }
        }
        return maxvalue;
    }
    int maxUniqueSplit(string s) {
        set<string>st;
        return maxlength(s,st,0);
        

    }
};