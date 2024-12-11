class Solution {
public:
    bool find(vector<vector<char>>&board,string word,int i,int j,int row,int col,int index,int length){
        if(index==length)return true;
        if(i>=row||j>=col||i<0||j<0||board[i][j]=='#'||word[index]!=board[i][j])return false;
        char tem=board[i][j];
        board[i][j]='#';
        bool down=false,up=false,left=false,right=false;
            down=find(board,word,i+1,j,row,col,index+1,length);
            up=find(board,word,i-1,j,row,col,index+1,length);
            left=find(board,word,i,j-1,row,col,index+1,length);
            right=find(board,word,i,j+1,row,col,index+1,length);
        board[i][j]=tem;
        return left||right||down||up;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        int length=word.length();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                bool ans=find(board,word,i,j,row,col,0,length);
                if(ans)return true;
            }
        }
        return false;
    }
};