class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return false;
    s=s+s;
    if(s.find(goal)!=std::string::npos){
        return true;
    }
    return false;
    }
};