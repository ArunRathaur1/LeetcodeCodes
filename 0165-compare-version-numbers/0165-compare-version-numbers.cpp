class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss(version1), ss1(version2);
        string g1,g2;
        while(!ss.eof()||!ss1.eof()){
            int num1=0;
            int num2=0;
            if(getline(ss,g1,'.')){
                num1=stoi(g1);
            }
            if(getline(ss1,g2,'.')){
                num2=stoi(g2);
            }
            if(num1>num2)return 1;
            else if(num2>num1)return -1; 
        }
        return 0;
    }
};