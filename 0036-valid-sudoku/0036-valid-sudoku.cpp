class Solution {
public:
    bool grid33(vector<vector<char>>&board){
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                unordered_set<int>st;
               for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                        if(board[k][l]=='.')continue;
                         if(st.find(board[k][l])==st.end())
                            st.insert(board[k][l]);
                        else{
                            return false;
                        }
                }
                cout<<endl;
               }
            }
        }
        return true;
    }
    bool rowcheck(vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            unordered_set<int>st;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                     if( st.find(board[i][j])==st.end()){
                    st.insert(board[i][j]);
                    }
                    else{
                        return false;
                    }
                }
        }
     
        return true;
    }
    bool colcheck(vector<vector<char>>&board){
       for(int i=0;i<9;i++){
            unordered_set<int>st;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')continue;
                     if( st.find(board[j][i])==st.end()){
                    st.insert(board[j][i]);
                    }
                    else{
                        return false;
                    }
            }
        }
     
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return grid33(board)&&rowcheck(board)&&colcheck(board);
    }
};