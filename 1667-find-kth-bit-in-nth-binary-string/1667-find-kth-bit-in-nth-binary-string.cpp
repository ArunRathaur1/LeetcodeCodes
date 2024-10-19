class Solution {
public:
    string  reverse(string g){
        int left=0;
        int right=g.length()-1;
        while(left<right){
            swap(g[left],g[right]);
            left++;
            right--;
        }
        return g;
    }
    string inverse(string g){
        int k=g.length();
        for(int i=0;i<k;i++){
            if(g[i]=='0'){
                g[i]='1';
            }
            else{
                g[i]='0';
            }
        }
        return g;
    }
    string simulation(int n){
        if(n==1)return "0";
        string p="";
        string k=simulation(n-1);
        string i=inverse(k);
        p=k+"1"+reverse(i);
        return p; 
    }
    char findKthBit(int n, int k) {
        string x=simulation(n);
        return x[k-1];
    }
};