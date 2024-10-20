class Solution {
public:
    bool parseBoolExpr(string s) {
        int l=s.length();
        stack<char>st;
        st.push(s[0]);
        for(int i=0;i<l;i++){
            if(s[i]=='!'||s[i]=='&'||s[i]=='|'||s[i]=='t'||s[i]=='f'){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                vector<bool>sr;
                while(st.top()!='!'&&st.top()!='&'&&st.top()!='|'){
                    char p=st.top();
                    if(p=='t')sr.push_back(true);
                    else{
                        sr.push_back(false);
                    }
                    st.pop();
                }
                char symbol=st.top();
                st.pop();
                if(symbol=='!'){
                    if(sr.front()==false)
                        st.push('t');
                    else{
                        st.push('f');
                    }
                    continue;
                }
                bool value=sr.front();
                for(auto i:sr){
                    if(symbol=='|'){
                        value=value | i;
                    }
                    else {
                        value=value & i;
                    }
                }
                if(value==true){
                    st.push('t');
                }
                else{
                    st.push('f');
                }
            }
        }
        if(st.top()=='t')return true;
        return false;
    }
};