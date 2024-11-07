class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size()==1)return true;
        int x=0;
        int i=0;
        while(i<bits.size()-1){
            if(bits[i]==1&& bits[i+1]==0){
                bits[i]=-1;
                bits[i+1]=-1;
                i++;
            }
            else if(bits[i]==1&& bits[i+1]==1){
                bits[i]=-1;
                bits[i+1]=-1;
                i++;
            }
            i++;
        }
       if(bits[bits.size()-1]!=-1)return true;
       return false;
    }
};