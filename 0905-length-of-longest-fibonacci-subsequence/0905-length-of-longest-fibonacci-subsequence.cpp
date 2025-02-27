class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        set<int>st;
        for(auto i: arr)st.insert(i);
        int n=arr.size();
        int maxcount=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=arr[i];
                int b=arr[j];
                int count=2;
                while(st.find(a+b)!=st.end()){
                    int c=a+b;
                    a=b;
                    b=c;
                    count++;
                }
                maxcount=max(maxcount,count);
            }
        }
        return (maxcount<3)?0:maxcount;
    }
};