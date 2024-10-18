class Solution {
public:
    vector<string> generatesubstring(string s){
        vector<string>s1;
        int left=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ')
            {
                left=i;
                break;
            }
        }
        string head=s.substr(0,left);
        string tail=s.substr(left+1,s.length()-left);
        s1.push_back(head);
        s1.push_back(tail);
        return s1;
    }
    bool static customsort(vector<string>ar1, vector<string>ar2){
        if(ar1[1]!=ar2[1])return ar2[1]>ar1[1];
        else{
        return ar2[0]>ar1[0];
        }
        
    }
    vector<string> reorderLogFiles(vector<string>& s) {
       vector<vector<string>>ar;
        int size=s.size();
        for(int j=0;j<size;j++){
            vector<string>s1=generatesubstring(s[j]);
            for(auto i: s1[1]){
                if(i>='a'&& i<='z'){
                    ar.push_back(s1);
                    s[j]="-1";
                    break;
                }
            }
            
        }
        for(auto x: ar){
            for(auto y: x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        sort(ar.begin(),ar.end(),customsort);
        vector<string>output;
        for(auto x: ar){
            string p=x[0]+" "+x[1];
            output.push_back(p);
        }
        
        for(auto x: s ){
            if(x!="-1"){
                output.push_back(x);
            }
        }
        return output;
    }
};