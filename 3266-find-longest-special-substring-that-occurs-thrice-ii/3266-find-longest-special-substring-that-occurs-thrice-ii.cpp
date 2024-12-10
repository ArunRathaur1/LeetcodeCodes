class Solution {
public:
    int maximumLength(string s) {
        int length = s.length();
        if (length == 0) return -1;

        int ans = -1;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            vector<int> ar;
            int count = 0;
            for (int i = 0; i < length; i++) {
                if (s[i] == ch) {
                    count++;
                } else {
                    if (count > 0) ar.push_back(count);
                    count = 0;
                }
            }
            if (count > 0) ar.push_back(count); 
                 if (ar.empty()) continue;
              int maxelement = *std::max_element(ar.begin(), ar.end());
            vector<int>tem(maxelement+1);
            for(int i=1;i<=maxelement;i++){
                int x=0;
                for(int k=0;k<ar.size();k++){
                    if(ar[k]>0){
                        x=x+ar[k];
                        ar[k]--;
                    }
                }
                tem[i]=x;
            }
            int index=maxelement;
            // for(int i=0;i<tem.size();i++){
            //     cout<<tem[i]<<" ";
            // }
            // cout<<endl;
            while(index>0){
                if(tem[index]>=3)
                break;
                index--;
            }
            if(index==0)index=-1;
            ans=max(ans,index);
        }

        return ans;
    }
};
