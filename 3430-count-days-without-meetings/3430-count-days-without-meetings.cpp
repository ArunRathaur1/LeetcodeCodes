class Solution {
public:
    static bool cmp(vector<int>a,vector<int>b){
        return a[0]<b[0];
    }
    vector<vector<int>>mergerInvertal(vector<vector<int>>& ar){
        vector<vector<int>>arr;
        int prev=ar[0][0];
        int next=ar[0][1];
        int n=ar.size();
        for(int i=1;i<n;i++){
           int tem=ar[i][0];
            if(tem<=next){
                next=max(ar[i][1],next);
            }
            else{
                arr.push_back({prev,next});
                prev=ar[i][0];
                next=ar[i][1];
            }
        }
        arr.push_back({prev,next});
        return arr;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(),cmp);
        vector<vector<int>>tem=mergerInvertal(meetings);
        int size=tem.size();
        int prev=1;
        int next=tem[0][0];
        int count=next-prev;
        for(int i=1;i<size;i++){
            prev=tem[i-1][1];
            next=tem[i][0];
            count+=next-prev-1;
        }
        count+=days-tem[size-1][1];
        return count;
    }
};