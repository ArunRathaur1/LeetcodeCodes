class Solution {
public:
    bool find(vector<vector<char>>&board,string word,vector<vector<bool>>&visited,int i,int j,int row,int col,int index,int length){
        if(index==length)return true;
        if(i>=row||j>=col||i<0||j<0||visited[i][j]==true||word[index]!=board[i][j])return false;
        visited[i][j]=true;
        bool down=false,up=false,left=false,right=false;
            down=find(board,word,visited,i+1,j,row,col,index+1,length);
            up=find(board,word,visited,i-1,j,row,col,index+1,length);
            left=find(board,word,visited,i,j-1,row,col,index+1,length);
            right=find(board,word,visited,i,j+1,row,col,index+1,length);
        visited[i][j]=false;
        return left||right||down||up;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        int length=word.length();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                bool ans=find(board,word,visited,i,j,row,col,0,length);
                if(ans)return true;
            }
        }
        return false;
    }
};