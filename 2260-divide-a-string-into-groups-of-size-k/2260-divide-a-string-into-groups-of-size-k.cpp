class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ar;
        int p=s.length();
        int index=0;
        string q="";
        int i=0;
        while(i<p){
            if(index<k){
                q=q+s[i];
                index++;
               
            }
            if(index==k){
                ar.push_back(q);
                index=0;
                q="";
            }
             i++;
        }
        if(q!="")
        ar.push_back(q);
        int size=ar.size();
        string z=ar[size-1];
        if(z.length()<k)
        {
                for(int i=ar[size-1].length();i<k;i++){
                    ar[size-1]=ar[size-1]+fill;
                }
                return ar;
        }
        else{
            return ar;
        }
        return {};
    
    }
};