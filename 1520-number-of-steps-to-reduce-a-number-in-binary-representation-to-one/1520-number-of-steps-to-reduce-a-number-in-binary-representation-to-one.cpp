class Solution {
public:
    int numSteps(string s) {
        int steps=0;
        int i=s.length()-1;
        while(s.length()>1){
            if(s.back()=='0'){
                s.pop_back();
                steps++;
            }
            else{
                steps++;
                int i=s.length()-1;
                while(i>=0&& s[i]=='1'){
                    s[i]='0';
                    i--;
                }
                if(i>=0){
                    s[i]='1';
                }
                else{
                    s='1'+s;
                }

            }
        }
        return steps;
    }
};