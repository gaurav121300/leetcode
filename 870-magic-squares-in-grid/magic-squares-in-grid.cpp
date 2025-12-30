class Solution {
public:
    bool isMagic(vector<vector<int>> &grid,int r,int c){
        if(grid[r+1][c+1] != 5)
        return false;

        vector<int>freq(10,0);

        for(int i = r;i< r + 3;i++){
            for(int j = c; j< c + 3 ; j++){
                int val = grid[i][j];
                if(val < 1 || val > 9 || freq[val]++){
                    return false;
                }
            }
        }

        for(int i = 0; i < 3;i++){
            int rowSum = grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2];
            int colSum = grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i];

            if(rowSum != 15 || colSum != 15) return false;
        }

        int dl = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int dr = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];

        if(dl != 15 || dr != 15) return false;

        return true;
    }

     int numMagicSquaresInside(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i = 0;i <= n-3;i++){
            for(int j = 0;j <= m-3;j++){
                if(isMagic(grid,i,j))
                count++;
            }
        }
        return count;
    }
};
