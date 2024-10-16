class Solution {
public:
    string findLatestTime(string s) {
        string hour=s.substr(0,2);
        string min=s.substr(3,2);
        cout<<hour<<" "<<min<<endl;
        if(hour[0]=='?'){
            if(hour[1]=='?'||hour[1]=='1'||hour[1]=='0')
                hour[0]='1';
            else{
                hour[0]='0';
            }
        }
        if(hour[1]=='?'){
            if(hour[0]=='1'){
                hour[1]='1';
            }
            else{
                hour[1]='9';
            }
        }
        if(min[0]=='?'){
            min[0]='5';
        }
        if(min[1]=='?'){
            min[1]='9';
        }
        return hour+":"+min;
    }
};