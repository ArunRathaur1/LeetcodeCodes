class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int s) {
        map<int,int>m;
        int n=hand.size();
        for(int i=0;i<n;i++){
            m[hand[i]]++;
        }
        for(auto it=m.begin();it!=m.end();it++){
            int number=it->first;
            int count=it->second;
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