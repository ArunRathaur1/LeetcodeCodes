class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int s=num.length();
        int tem=-1;
        int start=0;
        for(int i=0;i<s;i++){
        string p=to_string(num[i]);
        int q=stoi(p)-'0';
            if(q<change[q]){
                if(start==0){
                    start=i+1;
                }
                num[i]=char(change[q])+'0';
            }
            else if(q==change[q])continue;
            else if(start!=0){
                break;
            }
       } 
       return num; 
    }
};