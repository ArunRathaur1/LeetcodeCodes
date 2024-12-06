class Solution {
public:
    vector<string>generate(int n){
        if(n==1){
            return {"0","1"};
        }
        vector<string>get=generate(n-1);
        vector<string>output;
        for(int i=0;i<get.size();i++){
            output.push_back("0"+get[i]);
        }
        for(int i=get.size()-1;i>=0;i--){
            output.push_back("1"+get[i]);
        }
        return output;
    }
    vector<int> grayCode(int n) {
        vector<string>grayString=generate(n);
        vector<int>ans;
        int size=grayString.size();
        for(int i=0;i<size;i++){
            ans.push_back(stoi(grayString[i],0,2));
        }
        return ans;
    }
};