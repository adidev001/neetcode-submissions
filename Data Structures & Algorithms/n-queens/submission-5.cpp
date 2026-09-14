class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        vector<string> board(n, string(n, '.'));
        solve(board, res, 0);
        return res;
    }

    void solve(vector<string> &board,vector<vector<string>> &res,int row){
        
        if(row==board.size()){
            res.push_back(board);
            return ;
        }
        for (int col=0;col<board.size();col++){
            if(issafe(row,col,board)){
                board[row][col]='Q';
                solve(board,res,row+1);
                board[row][col]='.';
            }


        }
    }

    bool issafe(int r,int c,vector<string>& board){
        for(int i =r-1 ; i>=0;i-- ){
            if(board[i][col]=='Q')return false;

        }

        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }

        for(int i= r-1, j=c+1;i>=0 && j<board.size();i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
};
