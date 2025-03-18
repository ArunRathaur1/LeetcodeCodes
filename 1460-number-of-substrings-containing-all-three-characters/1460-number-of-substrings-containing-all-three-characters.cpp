class Solution {
public:
    int numberOfSubstrings(string s) {
        // map<char,int>m;
        // int l=s.length();
        // int ans=0;
        // int left=0;
        // for(int i=0;i<l;i++){
        //     m[s[i]]++;
        //     while(m.size()==3){
        //         ans=ans+(l-i);
        //         m[s[left]]--;
        //         if(m[s[left]]==0)m.erase(s[left]);
        //         left++;
        //     }
        // }
        // return ans;
        int a = -1, b = -1, c = -1;
        int counta = 0, countb = 0, countc = 0;
        int l = s.length();
        int ans = 0;
        int left = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == 'a') {
                counta++;
                a = i;
            } else if (s[i] == 'b') {
                countb++;
                b = i;
            } else if (s[i] == 'c') {
                countc++;
                c = i;
            }
            while (counta != 0 && countb != 0 && countc != 0) {
                ans = ans + l - max({a, b, c});
                if (s[left] == 'a') {
                    counta--;
                    a = -1;
                } else if (s[left] == 'b') {
                    countb--;
                    b = -1;
                } else if (s[left] == 'c') {
                    countc--;
                    c = -1;
                }
                left++;
            }
        }
        return ans;
    }
};