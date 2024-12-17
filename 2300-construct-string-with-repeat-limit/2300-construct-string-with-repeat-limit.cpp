class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
       priority_queue<pair<char,int>,vector<pair<char,int>>>pq;
       map<char,int>m;
       for(auto i:s)m[i]++;
       for(auto i:m)pq.push({i.first,i.second});
       string ans="";
       while(!pq.empty()){
        pair<char,int>x=pq.top();
        char ch=x.first;
        int freq=x.second;
        pq.pop();
        int k=min(freq,repeatLimit);
        ans.append(string(k,ch));
        if(freq>repeatLimit){
            if(pq.empty()){
                break;
            }
            pair<char,int>y=pq.top();
            pq.pop();
            ans.append(1,y.first);
            y.second--;
            if(y.second>0){
                pq.push(y);
            }
            x.second=x.second-repeatLimit;
            pq.push(x);

        }
       }
       return ans;
    }
};
