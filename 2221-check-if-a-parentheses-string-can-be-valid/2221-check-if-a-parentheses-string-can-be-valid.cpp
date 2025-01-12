class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int>ar1,ar2;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('&& locked[i]=='1'){
                ar1.push(i);
            }
            else if(locked[i]=='0'){
                ar2.push(i);
            }
            else{
                if(!ar1.empty()){
                    ar1.pop();
                }
                else if(!ar2.empty()){
                    ar2.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!ar1.empty()&& !ar2.empty()){
            if(ar1.top()<ar2.top()){
                ar1.pop();
                ar2.pop();
            }
            else{
                return false;
            }
        }
        if(!ar1.empty())return false;
        if(ar2.size()%2==0)return true;
        return false;
    }
};