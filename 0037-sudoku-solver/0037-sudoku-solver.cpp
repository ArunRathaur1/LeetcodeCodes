class Solution {
public:
    bool check(int k,vector<vector<char>>&board,int row,int col){
        for(int i=0;i<9;i++){
            if(board[row][i]-'0'==k)return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][col]-'0'==k)return false;
        }
        int p1=(row/3)*3;
        int p2=(col/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[p1+i][p2+j]-'0'==k)return false;
            }
        }
        return true;

    }
    bool solve(vector<vector<char>>&board,int dot){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(check(k,board,i,j)){
                            board[i][j]=k+'0';
                            bool p=solve(board,dot-1);
                            if(p)return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int dots=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')dots++;
            }
        }
        solve(board,dots);
    }
};