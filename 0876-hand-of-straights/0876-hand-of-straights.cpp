class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int s) {
        map<int,int>m;
        for(auto i: hand){
            m[i]++;
        }
        for(auto i=m.begin();i!=m.end();i++){
            int number=i->first;
            int count=i->second;
            if(count>0){
                for(int i=0;i<s;i++){
                    if(m[number+i]-count<0)return false;
                    m[number+i]-=count;
                }
            }
        }
        return true;
    }
};