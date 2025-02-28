class Solution {
public:
    vector<vector<int>>direction={{-1,0},{0,-1},{0,1},{1,0}};
    bool exist(vector<vector<char>>&board,string word,int row,int col,int i,int j,vector<vector<bool>>&visited,int index){
        if(i<0||i>=row||j<0||j>=col||visited[i][j]==true)return false;
        if(index==word.length())return true;
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int newx=i+direction[k][0];
            int newy=j+direction[k][1];
            if(newx>=row||newy>=col||newy<0||newx<0)continue;
            if(board[newx][newy]==word[index]){
                bool result=exist(board,word,row,col,newx,newy,visited,index+1);
                if(result==true)return true;
            }
        }
        visited[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(word[0]==board[i][j])
               {
                bool result=exist(board,word,row,col,i,j,visited,1);
                if(result)return result;
               } 
            }
        }
        return false;
    }
};