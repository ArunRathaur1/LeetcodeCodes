class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int s=num.length();
        int tem=-1;
       for(int i=0;i<s;i++){
        string p=to_string(num[i]);
        int q=stoi(p)-'0';
            if(q<change[q]){
            tem=i;
            break;
            }
       } 
       if(tem==-1)return num;
       for(int i=tem;i<s;i++){
        string p=to_string(num[i]);
        int q=stoi(p)-'0';
            if(q<=change[q]){
                num[i]=char(change[q])+'0';
            }
            else{
                break;
            }
       } 
       return num; 
    }
};