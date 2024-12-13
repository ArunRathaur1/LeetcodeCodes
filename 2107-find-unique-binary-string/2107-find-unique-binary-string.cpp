class Solution {
public:
    // vector<string> generateall(int n){
    //     if(n==1){
    //         return {"1","0"};
    //     }
    //     vector<string>com=generateall(n-1);
    //     vector<string>comb2;
    //     for(int i=0;i<com.size();i++){
    //         string x=com[i]+'0';
    //         com[i]=com[i]+'1';
    //         comb2.push_back(x);
    //     }
    //     com.insert(com.end(),comb2.begin(),comb2.end());
    //     return com;
    // }
    string findDifferentBinaryString(vector<string>& nums) {
        // int l=nums[0].length();
        // vector<string>com=generateall(l);
        // unordered_set<string>st;
        // for(auto i: nums)st.insert(i);
        // int size=com.size();
        // for(int i=0;i<size;i++){
        //     if(st.find(com[i])==st.end())return com[i];
        // }
        // return "";
        int length=nums[0].length();
        unordered_set<string>st;
        for(auto i: nums)st.insert(i);
        for(int i=0;i<pow(2,length);i++){
            std::bitset<32>s1(i);//converting to bitset
            string s=s1.to_string().substr(32-length,length);
            if(st.find(s)==st.end())return s;
        }
        return "";
    }
};