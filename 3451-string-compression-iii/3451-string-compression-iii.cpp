class Solution {
public:
    string compressedString(string word) {
        int length =word.length();
        char curr=word[0];
        int count=0;
        string ans="";
        for(int i=0;i<length;i++){
             if(word[i]!=curr||count>=9){
                string s1=to_string(count)+curr;
                ans.append(s1); 
                count=0;
                curr=word[i];
            }
            if(curr==word[i]){
                count++;
            }
        }
        if(count>0){
            string s1=to_string(count)+curr;
                ans.append(s1);
        }
        return ans;
    }
};