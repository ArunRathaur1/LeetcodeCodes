class Solution {
public:
    vector<int> seieve(int right){
        vector<bool>ar(right+1,true);
        ar[0]=ar[1]=false;
        for(long long i=2;i<right+1;i++){
            if(ar[i]==true){
                for(long long j=1LL*i*i;j<right+1;j=j+i){
                    ar[j]=false;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<right+1;i++){
            if(ar[i]==true){
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>ar=seieve(right);
        vector<int>ans={-1,-1};
        if(ar.size()<2)return ans;
        int diff=INT_MAX;
        int k=ar.size();
        int i=0;
        while(i<k&& ar[i]<left)i++;
        cout<<ar[i]<<endl;
        int first=ar[i];
        for(int j=i+1;j<k;j++){
            int second=ar[j];
            if(second!=first&& diff>(second-first)){
                ans={first,second};
                diff=second-first;
            }
            first=second;
        }
        return ans;
    }
};