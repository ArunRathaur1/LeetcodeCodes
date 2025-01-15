class Solution {
public:
    // Convert number to binary string
    string getnumber(int num) {
        if (num == 0) return "0";
        string s = "";
        while (num > 0) {
            s = char(num % 2 + '0') + s;
            num /= 2;
        }
        return s;
    }

    // Convert binary string to number
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
        cout<<s1<<" "<<s2<<endl;
        // Count the number of set bits in num2
        int setbitcount = 0;
        for (char c : s2) {
            if (c == '1') setbitcount++;
        }

        // Count the number of set bits in num1
        int bitcount = 0;
        for (char c : s1) {
            if (c == '1') bitcount++;
        }

        // If num2 has more or equal set bits than num1, return the largest number with setbitcount 1's
        if (setbitcount >= s1.length()) {
            return (1 << setbitcount) - 1; // This gives a number with setbitcount 1's
        }
        cout<<setbitcount<<endl;
        // I   f num2 has fewer set bits than num1, try to minimize the set bits in num1
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

        cout<<s1<<endl;
        return makenumber(s1);
    }
};