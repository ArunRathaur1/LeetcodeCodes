class Solution {
public:
    int minimumRecolors(string blocks, int k) {
       int black=0;
       int white=0;
       int n=blocks.length();
       int ans=0;
       for(int i=0;i<k;i++){
        if(blocks[i]=='B')black++;
        else white++;
       } 
       ans=white;
       int x=0;
       for(int i=k;i<n;i++){
            if(blocks[i]=='W')white++;
            else black++;
            if(blocks[x]=='W')white--;
            else black--;
            ans=min(ans,white);
            x++;
       }
       return ans;
    }
};