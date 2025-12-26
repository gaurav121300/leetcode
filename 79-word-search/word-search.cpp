class Solution {
public:
    bool dfs(int i,int j,string word,vector<vector<char>> &board,int idx,int m,int n){
        if(idx == word.size())  return true;

        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '.';

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int d = 0;d<4;d++){
            int nx = i + dx[d];
            int ny = j + dy[d];

            if(dfs(nx,ny,word,board,idx+1,m,n)) return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(dfs(i,j,word,board,0,m,n))
                return true;
            }
        }
        return false;

    }
};