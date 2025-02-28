class Solution {
public:
    void getpairs(string digits,vector<string>values,int index,vector<string>&ans,string& tem,int n){
        if(index>=n){
            ans.push_back(tem);
            return;
        }
        int number=digits[index]-'0';
        for(auto ch: values[number]){
            tem.push_back(ch);
            getpairs(digits,values,index+1,ans,tem,n);
            tem.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string>values={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        int index=0;
        int n=digits.length();
        string tem="";
        getpairs(digits,values,index,ans,tem,n);
        return ans;
    }
};