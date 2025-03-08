class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)return 0;
        if(n==0)return 1;
        if(n==1)return x;
        if(n==-1)return 1/x;
        double p=myPow(x,n/2);
        if(n%2==0)return p*p;
        else{
            if(n<0){
                return 1/x*p*p;
            }
            return x*p*p;
        }
    }
};