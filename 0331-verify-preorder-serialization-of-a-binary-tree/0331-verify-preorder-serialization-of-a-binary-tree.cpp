class Solution {
public:
    bool isValidSerialization(string preorder) {
       stringstream ss(preorder);
       string val;
       int node=1;
       while(getline(ss,val,',')){
            node--;
            if(node<0)return false;
            if(val!="#"){
                node=node+2;
            }
       }
       return node==0;
    }
};