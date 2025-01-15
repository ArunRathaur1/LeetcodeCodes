class Solution {
public:
    string getnumber(int num) {
        if (num == 0) return "0";
        string s = "";
        while (num > 0) {
            s = char(num % 2 + '0') + s;
            num /= 2;
        }
        return s;
    }
    int makenumber(const string& s) {
        int num = 0;
        for (char c : s) {
            num = num * 2 + (c - '0');
        }
        return num;
    }

    int minimizeXor(int num1, int num2) {
        string s1 = getnumber(num1);
        string s2 = getnumber(num2);
        int setbitcount = 0;
        for (char c : s2) {
            if (c == '1') setbitcount++;
        }
        for(int i=0;i<setbitcount;i++){
            s1='0'+s1;
        }
        for (int i = 0; i<s1.length(); i++) {
            if (s1[i] == '1' && setbitcount > 0) {
                setbitcount--;
            } else if (setbitcount == 0) {
                s1[i] = '0';
            }
        }
        for(int i=s1.length()-1;i>=0;i--){
            if(s1[i]=='0'&& setbitcount>0){
                s1[i]='1';
                setbitcount--;
            }
            if(setbitcount==0)break;
        }
        return makenumber(s1);
    }
};