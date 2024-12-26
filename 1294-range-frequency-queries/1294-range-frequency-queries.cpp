class RangeFreqQuery {
public:
    map<int,vector<int>>m;
    RangeFreqQuery(vector<int>& arr) {
        int s=arr.size();
        for(int i=0;i<s;i++){
            m[arr[i]].push_back(i);
        }
    }
    int query(int left, int right, int value) {
       if(m.find(value)==m.end())return 0;
        auto l=lower_bound(m[value].begin(),m[value].end(),left);
        auto u=upper_bound(m[value].begin(),m[value].end(),right);
       return distance(l,u);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */