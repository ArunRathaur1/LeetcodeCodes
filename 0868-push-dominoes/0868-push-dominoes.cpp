class Solution {
public:
    string pushDominoes(string s) {
      int l=s.length();
    vector<int>left(l,0);
    vector<int>right(l,0);
    char v='.';
    int count=1;

    for(int i=0;i<l;i++){
        if(s[i]=='R'){
            count=1;
            v='R';
        }
        else if(s[i]=='L'){
            count=0;
            v='L';
        }
        else if(v=='R'&& s[i]=='.'){
            right[i]=count;
            count++;
        }
    }
    int v2='.';
    count=1;
    for(int i=l-1;i>=0;i--){
        if(s[i]=='L'){
            count=1;
            v2='L';
        }
        else if(s[i]=='R'){
            count=0;
            v2='R';
        }
        else if(v2=='L' and s[i]=='.'){
            left[i]=count;
            count++;
        }
    }
    for(int i=0;i<l;i++){
        if(left[i]==0 and right[i]!=0){
            s[i]='R';
        }
        else if(left[i]!=0 and right[i]==0){
            s[i]='L';
        }
        else{
            if(left[i]<right[i]){
                s[i]='L';
            }
            else if(left[i]>right[i]){
                s[i]='R';
            }
        }
    }
    return s;
    }
};