class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int total=a+b+c;
        int index=0;
        string s="";
        priority_queue<pair<int,char>>p;
        if(a>0)p.push({a,'a'});
        if(b>0)p.push({b,'b'});
        if(c>0)p.push({c,'c'});
        while(!p.empty()){
            auto[freq,ch]=p.top();
            p.pop();
            if(s.length()>=2&&s[s.length()-1]==ch&& s[s.length()-2]==ch){
                if(p.empty())break;
                auto[freq2,ch2]=p.top();
                p.pop();
                s=s+ch2;
                freq2--;
                if(freq2>0)p.push({freq2,ch2});
                p.push({freq,ch});
            }
            else{
              s=s+ch;
              freq=freq-1;
              if(freq!=0)p.push({freq,ch}); 
               
            }
        }
        return s;
    }
};