class Solution {
public:
    void travel(vector<vector<char>>& board,int row,int col, int j, int i){
        if(i<0||i>=row||j<0||j>=col)return ;
        if(board[i][j]=='.')return ;
            board[i][j]='1';
        travel(board,row,col,j+1,i);
        travel(board,row,col,j,i+1);
    }
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='X'){
                    count++;
                    travel(board,row,col,j,i);
                }
            }
        }
        return count;
    }
};