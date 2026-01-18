class Solution {
public:
    bool isMagic(vector<vector<int>> &grid,int r,int c,int k){
        int target = 0;
        for(int j = c;j<c+k;j++){
            target += grid[r][j];
        }

        //rows
        for(int i = r;i<r+k;i++){
            int sum = 0;
            for(int j = c;j<c+k;j++){
                sum += grid[i][j];
            }
            if(sum != target) return false;
        }

        //column
        for(int j = c;j<c+k;j++){
            int sum = 0;
            for(int i = r;i<r+k;i++){
                sum += grid[i][j];
            }
            if(sum != target) return false;
        }

        //diagonal

        int d1 = 0,d2=0;
        for(int i = 0;i<k;i++){
            d1 += grid[r+i][c+i];
            d2 += grid[r+i][c+k-1-i];
        }

        return d1 == target && d2 == target;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int k = min(n,m); k >= 2;k--){
            for(int i = 0; i+k <= n;i++){
                for(int j = 0; j+k <= m;j++){
                    if(isMagic(grid,i,j,k))
                    return k;
                }
            }
        }
        return 1;
    }
};