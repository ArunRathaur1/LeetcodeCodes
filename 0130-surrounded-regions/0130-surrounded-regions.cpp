class Solution {
public:
    void dfs(vector<vector<char>>&board,int i,int j,int row,int col){
        if(i>=row||i<0||j>=col||j<0||board[i][j]=='X'||board[i][j]=='1')return ;
        board[i][j]='1';
        dfs(board,i+1,j,row,col);
        dfs(board,i,j+1,row,col);
        dfs(board,i-1,j,row,col);
        dfs(board,i,j-1,row,col);
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'&&(i==0||i==row-1||j==0||j==col-1)){
                   dfs(board,i,j,row,col); 
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='1'){
                    board[i][j]='O';
                }
            }
        }
    }
};