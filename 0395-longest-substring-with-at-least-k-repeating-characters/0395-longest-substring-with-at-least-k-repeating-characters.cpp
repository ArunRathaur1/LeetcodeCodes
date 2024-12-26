class Solution {
public:
    int longestSubstring(string s, int k) {
        priority_queue<pair<int,int>>q;
        int l=s.length();
        q.push({l,0});
        while(!q.empty()){
            pair<int,int>tem=q.top();q.pop();
            int start=tem.second;
            int length=tem.first;
            map<int,int>freq;
            for(int i=start;i<start+length;i++){
                freq[s[i]]++;
            }
            int flag=1;
            for(auto j:freq){
                if(j.second<k){
                    int p=start;
                    for(int i=start;i<start+length;i++){
                        if(s[i]==j.first){
                            if(i>p){
                                q.push({i-p,p});
                            }
                            p=i+1;
                        }
                    }
                    if(p<start+length){
                        q.push({start+length-p,p});
                    }
                    flag=-1;
                    break;
                }
            }
            if(flag==1){
                return length;
            }
        }
        return 0;
    }
};