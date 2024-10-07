class Solution {
public:
    int minLength(string s) {
        int length=s.length();
        string x=s;
        while(true){
            int n=x.length();
            string p="";
            int found=0;
            for(int i=0;i<n;i++){
                if(x[i]=='A'&&x[i+1]=='B'||x[i]=='C'&&x[i+1]=='D'){
                    i++;
                    found=1;
                }
                else{
                    p=p+x[i];
                }
            }
            x=p;
            if(found==1){
                continue;
            }
            else{
                break;
            }
        }
        return x.length();
    }
};